/****************************************************************************
 *      datafile_cmd.c
 *      command database engine
 *  
 *	Based on MAMEYA 5.4
 *
 * command.dat 를 처리할 전용 루틴만 분리한 것으로 datafile.c의 끝부분에
 * #include 처리해서 컴파일하면 되도록 작성함.
 ****************************************************************************/

#define MAX_MENUIDX_ENTRIES 64

/****************************************************************************
 *      token parsing constants
 ****************************************************************************/
const char *DATAFILE_TAG_COMMAND = "$cmd";
const char *DATAFILE_TAG_END	 = "$end";

const char *command_filename = "command.dat";


static struct tDatafileIndex *cmnd_idx = 0;
static struct tMenuIndex *menu_idx = 0;

static int caname_wrap;


void init_cmdfunc(void)
{
	caname_wrap = 0;
}

/**************************************************************************
 **************************************************************************
 *
 *              Parsing functions
 *
 **************************************************************************
 **************************************************************************/

/****************************************************************************
 *      cmd_GetNextToken - Pointer to the token string pointer
 *                                 Pointer to position within file
 *
 *      Returns token, or TOKEN_INVALID if at end of file
 ****************************************************************************/
static UINT32 cmd_GetNextToken(UINT8 **ppszTokenText, long *pdwPosition)
{
	UINT32 dwLength;			/* Length of symbol */
	long dwPos;                 /* Temporary position */
	UINT8 *pbTokenPtr = bToken; /* Point to the beginning */
	UINT8 bData;                /* Temporary data byte */
	UINT8 space, character;

	if (caname_wrap)
	{
		space     = '\t';
		character = ' ' - 1;
	}
	else
	{
		space     = ' ';
		character = ' ';
	}

    while (1)
    {
		bData = mame_fgetc(fp);                                  /* Get next character */

        /* If we're at the end of the file, bail out */
        if (mame_feof(fp))
                return(TOKEN_INVALID);

        /* If it's not whitespace, then let's start eating characters */
		if (space != bData && '\t' != bData)
        {
            /* Store away our file position (if given on input) */
            if (pdwPosition)
                    *pdwPosition = dwFilePos;

            /* If it's a separator, special case it */
            if (',' == bData || '=' == bData)
            {
                *pbTokenPtr++ = bData;
                *pbTokenPtr = '\0';
                ++dwFilePos;

                if (',' == bData)
                    return(TOKEN_COMMA);
                else
                    return(TOKEN_EQUALS);
            }

            /* Otherwise, let's try for a symbol */
			if (bData > character)
            {
                dwLength = 0;                   /* Assume we're 0 length to start with */

                /* Loop until we've hit something we don't understand */
                while (bData != ',' &&
                       bData != '=' &&
				       bData != space &&
                       bData != '\t' &&
                       bData != '\n' &&
                       bData != '\r' &&
                       mame_feof(fp) == 0)
                {
                    ++dwFilePos;
                    *pbTokenPtr++ = bData;  /* Store our byte */
                    ++dwLength;
                    assert(dwLength < MAX_TOKEN_LENGTH);
                    bData = mame_fgetc(fp);
                }

                /* If it's not the end of the file, put the last received byte */
                /* back. We don't want to touch the file position, though if */
                /* we're past the end of the file. Otherwise, adjust it. */

                if (0 == mame_feof(fp))
                {
                    mame_ungetc(bData, fp);
                }

                /* Null terminate the token */
                *pbTokenPtr = '\0';

                /* Connect up the */
                if (ppszTokenText)
                        *ppszTokenText = bToken;

                return(TOKEN_SYMBOL);
            }

            /* Not a symbol. Let's see if it's a cr/cr, lf/lf, or cr/lf/cr/lf */
            /* sequence */

            if (LF == bData)
            {
                /* Unix style perhaps? */
                bData = mame_fgetc(fp);          /* Peek ahead */
                mame_ungetc(bData, fp);          /* Force a retrigger if subsequent LF's */

                if (LF == bData)                /* Two LF's in a row - it's a UNIX hard CR */
                {
                    ++dwFilePos;
                    *pbTokenPtr++ = bData;  /* A real linefeed */
                    *pbTokenPtr = '\0';
                    return(TOKEN_LINEBREAK);
                }

            /* Otherwise, fall through and keep parsing. */
            }
            else
            if (CR == bData)                /* Carriage return? */
            {
                /* Figure out if it's Mac or MSDOS format */
                ++dwFilePos;
                bData = mame_fgetc(fp);          /* Peek ahead */

                /* We don't need to bother with EOF checking. It will be 0xff if */
                /* it's the end of the file and will be caught by the outer loop. */
                if (CR == bData)                /* Mac style hard return! */
                {
                    /* Do not advance the file pointer in case there are successive */
                    /* CR/CR sequences */

                    /* Stuff our character back upstream for successive CR's */
                    mame_ungetc(bData, fp);

                    *pbTokenPtr++ = bData;  /* A real carriage return (hard) */
                    *pbTokenPtr = '\0';
                    return(TOKEN_LINEBREAK);
                }
                else
                if (LF == bData)        /* MSDOS format! */
                {
					if (caname_wrap)
					{
						mame_ungetc(bData, fp);

						*pbTokenPtr++ = bData;	/* A real carriage return (hard) */
						*pbTokenPtr = '\0';

						return(TOKEN_LINEBREAK);
					}
					else
					{
                        ++dwFilePos;                    /* Our file position to reset to */
                        dwPos = dwFilePos;              /* Here so we can reposition things */

                        /* Look for a followup CR/LF */
                        bData = mame_fgetc(fp);  /* Get the next byte */

                        if (CR == bData)        /* CR! Good! */
                        {
                            bData = mame_fgetc(fp);  /* Get the next byte */

                            /* We need to do this to pick up subsequent CR/LF sequences */
                            mame_fseek(fp, dwPos, SEEK_SET);

                            if (pdwPosition)
                                    *pdwPosition = dwPos;

                            if (LF == bData)        /* LF? Good! */
                            {
                                *pbTokenPtr++ = '\r';
                                *pbTokenPtr++ = '\n';
                                *pbTokenPtr = '\0';

                                return(TOKEN_LINEBREAK);
                            }
                        }
                        else
                        {
                            --dwFilePos;
                            mame_ungetc(bData, fp);  /* Put the character back. No good */
                        }
                    }
				}
                else
                {
                    --dwFilePos;
                    mame_ungetc(bData, fp);  /* Put the character back. No good */
                }

                /* Otherwise, fall through and keep parsing */
            }
		}

        ++dwFilePos;
    }
}

/**************************************************************************
 *	index_menuidx
 *	
 *
 *	Returns 0 on error, or the number of index entries created.
 **************************************************************************/
static int index_menuidx (const struct GameDriver *drv, struct tDatafileIndex *d_idx, struct tMenuIndex **_index)
{
	struct tMenuIndex *m_idx;
	int m_count = 0;
	UINT32 token = TOKEN_SYMBOL;

	long tell;
	long cmdtag_offset = 0;
	char *s;

	caname_wrap = 1;

	/* find driver in datafile index */
	while (d_idx->driver)
	{
		if (d_idx->driver == drv || d_idx->driver == drv->clone_of) break;
		d_idx++;
	}
	if (d_idx->driver == 0) return 0;	/* driver not found in Data_file_index */

	/* seek to correct point in datafile */
	if (ParseSeek (d_idx->offset, SEEK_SET)) return 0;

	/* allocate index */
	m_idx = *_index = (struct tMenuIndex *)malloc(MAX_MENUIDX_ENTRIES * sizeof (struct tMenuIndex));
	if (NULL == m_idx) return 0;

	/* loop through between $cmd= */
	token = cmd_GetNextToken ((UINT8 **)&s, &tell);
	while ((m_count < (MAX_MENUIDX_ENTRIES - 1)) && TOKEN_INVALID != token)
	{
		if (!ci_strncmp (DATAFILE_TAG_KEY, s, strlen(DATAFILE_TAG_KEY)))
			break;

		/* DATAFILE_TAG_COMMAND identifies the driver */
		if (!ci_strncmp (DATAFILE_TAG_COMMAND, s, strlen(DATAFILE_TAG_COMMAND)))
		{
			cmdtag_offset = tell;
			token = cmd_GetNextToken ((UINT8 **)&s, &tell);

			if (TOKEN_EQUALS == token)
			{
				token = cmd_GetNextToken ((UINT8 **)&s, &tell);
				m_idx->menuitem = (char*)malloc(strlen(s)+1);
				strcpy(m_idx->menuitem, s);

				m_idx->offset = cmdtag_offset;

				m_idx++;
				m_count++;
			}
			else
			{
				while (TOKEN_SYMBOL != token)
					token = cmd_GetNextToken ((UINT8 **)&s, &tell);

				m_idx->menuitem = malloc( strlen( s ) + 1 );
				strcpy( m_idx->menuitem, s );

				m_idx->offset = cmdtag_offset;

				m_idx++;
				m_count++;
			}
		}
		token = cmd_GetNextToken ((UINT8 **)&s, &tell);
	}

	/* mark end of index */
	m_idx->offset = 0L;
	m_idx->menuitem = NULL;

	return m_count;
}

/**************************************************************************
 *      cmd_load_datafile_text
 *
 *      Loads text field for a driver into the buffer specified. Specify the
 *      driver, a pointer to the buffer, the buffer size, the index created by
 *      index_datafile(), and the desired text field (e.g., DATAFILE_TAG_BIO).
 *
 *      Returns 0 if successful.
 **************************************************************************/
static int cmd_load_datafile_text (const struct GameDriver *drv, char *buffer, int bufsize,
									struct tDatafileIndex *idx, const char *tag)
{
    int     offset = 0;
    int found = 0;
    UINT32  token = TOKEN_SYMBOL;
    UINT32  prev_token = TOKEN_SYMBOL;
	int first = 1;

    *buffer = '\0';

    /* find driver in datafile index */
    while (idx->driver)
    {
        if (idx->driver == drv) break;

        idx++;
    }
    if (idx->driver == 0) return 1; /* driver not found in index */

    /* seek to correct point in datafile */
    if (ParseSeek (idx->offset, SEEK_SET)) return 1;

    /* read text until buffer is full or end of entry is encountered */
    while (TOKEN_INVALID != token)
    {
        char *s;
        int len;
        long tell;

        token = cmd_GetNextToken ((UINT8 **)&s, &tell);
        if (TOKEN_INVALID == token) continue;

        if (found)
        {
            /* end entry when a tag is encountered */
            if (TOKEN_SYMBOL == token && DATAFILE_TAG == s[0] && TOKEN_LINEBREAK == prev_token) break;

            prev_token = token;

            /* translate platform-specific linebreaks to '\n' */
            if (TOKEN_LINEBREAK == token)
                strcpy (s, "\n");

            /* append a space to words */
			if (!caname_wrap && TOKEN_LINEBREAK != token)
				strcat (s, " ");

            /* remove extraneous space before commas */
            if (TOKEN_COMMA == token)
            {
                --buffer;
                --offset;
                *buffer = '\0';
            }

            /* Get length of text to add to the buffer */
            len = strlen (s);

            /* Check for buffer overflow */
            /* For some reason we can get a crash if we try */
            /* to use the last 30 characters of the buffer  */
            if ((bufsize - offset) - len <= 45)
            {
                strcpy (s, " ...[TRUNCATED]");
                len = strlen(s);
                strcpy (buffer, s);
                buffer += len;
                offset += len;
                break;
            }

            /* add this word to the buffer */
			len = strlen (s);
			if ((len + offset) >= bufsize) break;

            strcpy (buffer, s);
            buffer += len;
            offset += len;
        }
        else
        {
            if (TOKEN_SYMBOL == token)
            {
                /* looking for requested tag */
                if (!ci_strncmp (tag, s, strlen (tag)))
				{  
                    found = 1;

					if (first && caname_wrap)
					{
						mame_fseek(fp, 2l, SEEK_CUR);
						first = 0;
					}
                }
                else if (!ci_strncmp (DATAFILE_TAG_KEY, s, strlen (DATAFILE_TAG_KEY)))
                    break; /* error: tag missing */
            }
        }
    }
    return (!found);
}

/**************************************************************************
 *	cmd_load_datafile_text_ex
 *
 *	Loads text field for a driver into the buffer specified. Specify the
 *	driver, a pointer to the buffer, the buffer size, the index created by
 *	index_datafile(), and the desired text field (e.g., DATAFILE_TAG_BIO).
 *
 *	Returns 0 if successful.
 **************************************************************************/
static int cmd_load_datafile_text_ex (const struct GameDriver *drv, char *buffer, int bufsize,
					const char *tag, struct tMenuIndex *m_idx, const int menu_sel)
{
	int offset = 0;
	int found = 0;
	UINT32	token = TOKEN_SYMBOL;
	UINT32 	prev_token = TOKEN_SYMBOL;
	int first = 1;

	*buffer = '\0';

	/* seek to correct point in datafile */
	if (ParseSeek ((m_idx + menu_sel)->offset, SEEK_SET)) return 1;

	/* read text until buffer is full or end of entry is encountered */
	while (TOKEN_INVALID != token)
	{
		char *s;
		int len;
		long tell;

		token = cmd_GetNextToken ((UINT8 **)&s, &tell);
		if (TOKEN_INVALID == token) continue;

		if (found)
		{
			/* end entry when a tag is encountered */
			if (TOKEN_SYMBOL == token && !ci_strncmp (DATAFILE_TAG_END, s, strlen (DATAFILE_TAG_END))) break;

			prev_token = token;

			/* translate platform-specific linebreaks to '\n' */
			if (TOKEN_LINEBREAK == token)
				strcpy (s, "\n");

			/* append a space to words */
			if (!caname_wrap && TOKEN_LINEBREAK != token)
				strcat (s, " ");

			/* remove extraneous space before commas */
			if (TOKEN_COMMA == token)
			{
				--buffer;
				--offset;
				*buffer = '\0';
			}

			/* add this word to the buffer */
			len = strlen (s);
			if ((len + offset) >= bufsize) break;
			strcpy (buffer, s);
			buffer += len;
			offset += len;
		}
		else
		{
			if (TOKEN_SYMBOL == token)
			{
				/* looking for requested tag */
				if (!ci_strncmp (tag, s, strlen (tag)))
				{
					found = 1;
					token = cmd_GetNextToken ((UINT8 **)&s, &tell);
					if ( TOKEN_EQUALS == token )
					{
						token = cmd_GetNextToken ((UINT8 **)&s, &tell);
						token = cmd_GetNextToken ((UINT8 **)&s, &tell);
					}

					if (first) first = 0;
				}
				else if (!ci_strncmp (DATAFILE_TAG_KEY, s, strlen (DATAFILE_TAG_KEY)))
					break; /* error: tag missing */
			}
		}
	}
	return (!found);
}

/**************************************************************************
 *	load_driver_command
 **************************************************************************/
int load_driver_command (const struct GameDriver *drv, char *buffer, int bufsize)
{
	int command = 0;
	int err = 0;

	*buffer = 0;
	caname_wrap = 1;

	/* try to open command datafile */
	if (ParseOpen (command_filename))
	{
		/* create index if necessary */
		if (cmnd_idx)
			command = 1;
		else
			command = (index_datafile (&cmnd_idx) != 0);

		/* load informational text (append) */
		if (cmnd_idx)
		{
			const struct GameDriver *gdrv;

			gdrv = drv;
			do
			{
				err = cmd_load_datafile_text (gdrv, buffer, bufsize,
										  cmnd_idx, DATAFILE_TAG_COMMAND);
				gdrv = gdrv->clone_of;
			} while (err && gdrv);

			if (err) command = 0;
		}
		ParseClose ();
	}

	return (command == 0);
}


/**************************************************************************
 *	load_driver_command_ex
 **************************************************************************/
int load_driver_command_ex (const struct GameDriver *drv, char *buffer, int bufsize, const int menu_sel)
{
	int command = 0;
	int err = 0;

	*buffer = 0;
	caname_wrap = 1;

	/* try to open command datafile */
	if (ParseOpen (command_filename))
	{
		/* create index if necessary */
		if (cmnd_idx)
			command = 1;
		else
			command = (index_datafile (&cmnd_idx) != 0);

		/* create menu_index if necessary */
		if (menu_idx)
			command = 1;
		else
			command = (index_menuidx (drv, cmnd_idx, &menu_idx) != 0);

		/* load informational text (append) */
		if (cmnd_idx)
		{
			const struct GameDriver *gdrv;

			gdrv = drv;
			do
			{
				err = cmd_load_datafile_text_ex (gdrv, buffer, bufsize,
					  DATAFILE_TAG_COMMAND, menu_idx, menu_sel);
				gdrv = gdrv->clone_of;
			} while (err && gdrv);

			if (err) command = 0;
		}
		ParseClose ();
	}


	return (command == 0);
}


/**************************************************************************
 *	command_sub_menu
 **************************************************************************/
UINT8 command_sub_menu(const struct GameDriver *drv, const char *menu_item[])
{
	int command = 0;
	UINT8 total = 0;
	static const struct GameDriver *last_drv = 0;

	/* try to open command datafile */

	if (ParseOpen (command_filename))

	{
		/* create index if necessary */
		if (cmnd_idx)
			command = 1;
		else
			command = (index_datafile (&cmnd_idx) != 0);
		
		command = (index_menuidx (drv, cmnd_idx, &menu_idx) != 0);
	}
	ParseClose ();

	if(menu_idx && command == TRUE)
	{
		struct tMenuIndex *m_idx = menu_idx;
		
		while(m_idx->menuitem != NULL)
		{
			menu_item[total++] = m_idx->menuitem;
			m_idx++;
		}
		last_drv = drv;
		return total;
	}
	else
		return 0;
}
