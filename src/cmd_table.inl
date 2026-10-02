
	// 화살표 등 기본 공략폰트 색 지정할 때 쓰입니다.
	// 기본값은 '0'이지만, 다른 색을 지정해서 변경 가능.
	#define BUTTON_COLOR_BASIC  8

	// 공략 폰트의 색상을 설정하는 배열입니다.
	static pen_t color_table[COLOR_BUTTONS] = {
		0,						// dummy
		BUTTON_COLOR_RED,		// BTN_A
		BUTTON_COLOR_YELLOW,	// BTN_B
		BUTTON_COLOR_GREEN,		// BTN_C
		BUTTON_COLOR_BLUE,		// BTN_D
		BUTTON_COLOR_PINK,		// BTN_E
		BUTTON_COLOR_PURPLE,	// BTN_F
		BUTTON_COLOR_AQUA,		// BTN_G
		BUTTON_COLOR_SILVER,	// BTN_H
		BUTTON_COLOR_NAVY,		// BTN_I
		BUTTON_COLOR_LIME,		// BTN_J
		BUTTON_COLOR_RED,		// BTN_K
		BUTTON_COLOR_YELLOW,	// BTN_L
		BUTTON_COLOR_GREEN,		// BTN_M
		BUTTON_COLOR_BLUE,		// BTN_N
		BUTTON_COLOR_PINK,		// BTN_O
		BUTTON_COLOR_PURPLE,	// BTN_P
		BUTTON_COLOR_AQUA,		// BTN_Q
		BUTTON_COLOR_SILVER,	// BTN_R
		BUTTON_COLOR_NAVY,		// BTN_S
		BUTTON_COLOR_LIME,		// BTN_T
		BUTTON_COLOR_RED,		// BTN_U
		BUTTON_COLOR_YELLOW,	// BTN_V
		BUTTON_COLOR_GREEN,		// BTN_W
		BUTTON_COLOR_BLUE,		// BTN_X
		BUTTON_COLOR_PINK,		// BTN_Y
		BUTTON_COLOR_PURPLE,	// BTN_Z
		BUTTON_COLOR_RED,		// BTN_1
		BUTTON_COLOR_YELLOW,	// BTN_2
		BUTTON_COLOR_GREEN,		// BTN_3
		BUTTON_COLOR_BLUE,		// BTN_4
		BUTTON_COLOR_PINK,		// BTN_5
		BUTTON_COLOR_PURPLE,	// BTN_6
		BUTTON_COLOR_AQUA,		// BTN_7
		BUTTON_COLOR_SILVER,	// BTN_8
		BUTTON_COLOR_NAVY,		// BTN_9
		BUTTON_COLOR_LIME,		// BTN_10
		BUTTON_COLOR_RED,		// BTN_11
		BUTTON_COLOR_YELLOW,	// BTN_12
		BUTTON_COLOR_AQUA,		// BTN_+
		BUTTON_COLOR_BASIC,		// DIR_...
		BUTTON_COLOR_BASIC,		// DIR_1
		BUTTON_COLOR_BASIC,		// DIR_2
		BUTTON_COLOR_BASIC,		// DIR_3
		BUTTON_COLOR_BASIC,		// DIR_4
		BUTTON_COLOR_RED,		// Joystick Ball
		BUTTON_COLOR_BASIC,		// DIR_6
		BUTTON_COLOR_BASIC,		// DIR_7
		BUTTON_COLOR_BASIC,		// DIR_8
		BUTTON_COLOR_BASIC,		// DIR_9
		BUTTON_COLOR_BASIC,		// DIR_N
		BUTTON_COLOR_BASIC,		// Continue Arrow
		BUTTON_COLOR_AQUA,		// BTN_START
		BUTTON_COLOR_LIME,		// BTN_SELETE
		BUTTON_COLOR_PINK,		// BTN_Punch
		BUTTON_COLOR_PURPLE,	// BTN_Kick
		BUTTON_COLOR_SILVER,	// BTN_Guard
		0,
		0,
		BUTTON_COLOR_GREEN,		// LP
		BUTTON_COLOR_YELLOW,	// MP
		BUTTON_COLOR_RED,		// SP
		BUTTON_COLOR_GREEN,		// LK
		BUTTON_COLOR_YELLOW,	// MK
		BUTTON_COLOR_RED,		// SK
		BUTTON_COLOR_PURPLE,	// 3K
		BUTTON_COLOR_PINK,		// 3P
		BUTTON_COLOR_PURPLE,	// 2K
		BUTTON_COLOR_PINK,		// 2P
		BUTTON_COLOR_BASIC,		// Tap
		BUTTON_COLOR_RED,		// CUSTOM_1
		BUTTON_COLOR_YELLOW,	// CUSTOM_2
		BUTTON_COLOR_GREEN,		// CUSTOM_3
		BUTTON_COLOR_BLUE,		// CUSTOM_4
		BUTTON_COLOR_PINK,		// CUSTOM_5
		BUTTON_COLOR_PURPLE,	// CUSTOM_6
		BUTTON_COLOR_AQUA,		// CUSTOM_7
		BUTTON_COLOR_SILVER,	// CUSTOM_8
		BUTTON_COLOR_RED,		// (↑)
		BUTTON_COLOR_YELLOW,	// (↓)
		BUTTON_COLOR_GREEN,		// (←)
		BUTTON_COLOR_BLUE,		// (→)
		BUTTON_COLOR_NAVY,		// Non Player Lever
		BUTTON_COLOR_LIME,		// Gray Color Lever
		BUTTON_COLOR_RED,		// 1 Player Lever
		BUTTON_COLOR_YELLOW,	// 2 Player Lever
		BUTTON_COLOR_GREEN,		// 3 Player Lever
		BUTTON_COLOR_BLUE,		// 4 Player Lever
		BUTTON_COLOR_PINK,		// 5 Player Lever
		BUTTON_COLOR_PURPLE,	// 6 Player Lever
		BUTTON_COLOR_AQUA,		// 7 Player Lever
		BUTTON_COLOR_SILVER,	// 8 Player Lever
	};


// 로고 및 개발자 폰트를 간단히 비교하기 위해 만든 매크로
#define isLOGO6(n)					\
	( *(c+1) == *(temp[n]+1) &&		\
	  *(c+2) == *(temp[n]+2) &&		\
	  *(c+3) == *(temp[n]+3) &&		\
	  *(c+4) == *(temp[n]+4) &&		\
	  *(c+5) == *(temp[n]+5) )

#define isLOGO8(n)					\
	( *(c+1) == *(temp[n]+1) &&		\
	  *(c+2) == *(temp[n]+2) &&		\
	  *(c+3) == *(temp[n]+3) &&		\
	  *(c+4) == *(temp[n]+4) &&		\
	  *(c+5) == *(temp[n]+5) &&		\
	  *(c+6) == *(temp[n]+6) &&		\
	  *(c+7) == *(temp[n]+7) )


#define iLOGO6(C1, C2)			\
		*c     = C1;			\
		*(c+1) = C2 + 1;		\
		*(c+2) = C1;			\
		*(c+3) = C2 + 2;		\
		*(c+4) = C1;			\
		*(c+5) = C2 + 3;		\
		c+=6;

#define iLOGO8(C1, C2)			\
		*c     = C1;			\
		*(c+1) = C2 + 1;		\
		*(c+2) = C1;			\
		*(c+3) = C2 + 2;		\
		*(c+4) = C1;			\
		*(c+5) = C2 + 3;		\
		*(c+6) = C1;			\
		*(c+7) = C2 + 4;		\
		c+=8;

	enum
	{
		LOGO_first_entry = -1,

		LOGO_mbox32_high,	// 엠박스32 로고(상단)
		LOGO_mbox32_low,	// 엠박스32 로고(하단)
		LOGO_second_high,	// 마메야   로고(상단)
		LOGO_second_low,	// 마메야   로고(하단)

		LOGO_deco_mbox,		// 공략작성자: 엠박스32 로고

		LOGO_last_entry
	};

// 마메야의 로고를 입력하면 됩니다.
	static const char *logo[] =
	{
		"#엠박스#",
		"#공략집#",
		"#마메야@",
		"#공략집@",
		"#mbox#",
		NULL
	};

static void convert_command_move(char *buf)
{
	unsigned char *c = (unsigned char *)buf;

	int i;

	int c1 = 0xad;		// 공략폰트 영역 1 (1블럭당 94글자)
	int c2 = c1 + 1;	// 공략폰트 영역 2
	int c3 = c1 + 2;	// 공략폰트 영역 3

	int s1 = 0xa1;		// 공략폰트 첫번째 주소 위치

	int logo_mbox32 = 0xa1 - 1;			// 엠박스32 로고 폰트 위치
	int logo_second = logo_mbox32 + 8;	// 마메야   로고 폰트 위치
	int deco_mbox32 = logo_mbox32 + 16;	// 엠박스32 개발자 폰트 위치

	unsigned char *temp[8];

	for (i = LOGO_first_entry + 1; i < LOGO_last_entry; i++)
		temp[i] = (unsigned char *)logo[i];

	while (*c)
	{
		if (iszen1(*c) && iszen2(*(c+1)))
		{
			c+=2;
		}
		else
		{
			if (*c == '_')
			{
				switch(*(c+1))
				{
					case '0': // DIR_...
					case '1': // DIR_1
					case '2': // DIR_2
					case '3': // DIR_3
					case '4': // DIR_4
					case '5': // Joystick Ball
					case '6': // DIR_6
					case '7': // DIR_7
					case '8': // DIR_8
					case '9': // DIR_9
						*c     = c1;
						*(c+1) = s1 + 40 + (*(c+1) - '0');
						c+=2;
						break;

					case 'N': // DIR_N
						*c     = c1;
						*(c+1) = s1 + 50;
						c+=2;
						break;

					case 'A': // BTN_A
					case 'B': // BTN_B
					case 'C': // BTN_C
					case 'D': // BTN_D
						*c     = c1;
						*(c+1) = s1 + 1 + (*(c+1) - 'A');
						c+=2;
						break;

					case 'P': // BTN_Punch
						*c     = c1;
						*(c+1) = s1 + 54 ;
						c+=2;
						break;
					case 'K': // BTN_Kick
						*c     = c1;
						*(c+1) = s1 + 55;
						c+=2;
						break;
					case 'G': // BTN_Guard
						*c     = c1;
						*(c+1) = s1 + 56;
						c+=2;
						break;
					
					case 'S': // BTN_START
						*c     = c1;
						*(c+1) = s1 + 52;
						c+=2;
						break;
					case 'T': // BTN_SELETE
						*c     = c1;
						*(c+1) = s1 + 53;
						c+=2;
						break;

					case 'a': // BTN_1
					case 'b': // BTN_2
					case 'c': // BTN_3
					case 'd': // BTN_4
					case 'e': // BTN_5
					case 'f': // BTN_6
					case 'g': // BTN_7
					case 'h': // BTN_8
					case 'i': // BTN_9
					case 'j': // BTN_10
						*c     = c1;
						*(c+1) = s1 + 27 + (*(c+1) - 'a');
						c+=2;
						break;

					case '+': // BTN_+
						*c     = c1;
						*(c+1) = s1 + 39;
						c+=2;
						break;

					case '>': // Continue Arrow
						*c     = c1;
						*(c+1) = s1 + 51;
						c+=2;
						break;

					default:
						c++;
						break;
				}
			}

			else if (*c == '^')
			{
				switch(*(c+1))
				{
					case 'N': // BTN_N
					case 'Z': // BTN_Z
						*c     = c1;
						*(c+1) = s1 + 1 + (*(c+1) - 'A');
						c+=2;
						break;

					case 'E': // Light  Punch
					case 'F': // Middle Punch
					case 'G': // Strong Punch
					case 'H': // Light  Kick
					case 'I': // Middle Kick
					case 'J': // Strong Kick
						*c     = c1;
						*(c+1) = s1 + 59 + (*(c+1) - 'E');
						c+=2;
						break;

					case 'T': // 3 Kick
					case 'U': // 3 Punch
					case 'V': // 2 Kick
					case 'W': // 2 Punch
					case 'X': // TAP
						*c     = c1;
						*(c+1) = s1 + 65 + (*(c+1) - 'T');
						c+=2;
						break;

					case 'k': // Half Circle Back
					case 'l': // Half Circle Front Up
					case 'm': // Half Circle Front
					case 'n': // Half Circle Back Up
						*c     = c2;
						*(c+1) = s1 + (*(c+1) - 'k');
						c+=2;
						break;
					case 'o': // 1/4 Cir For 2 Down
					case 'p': // 1/4 Cir Down 2 Back
					case 'q': // 1/4 Cir Back 2 Up
					case 'r': // 1/4 Cir Up 2 For
					case 's': // 1/4 Cir Back 2 Down
					case 't': // 1/4 Cir Down 2 For
					case 'u': // 1/4 Cir For 2 Up
					case 'v': // 1/4 Cir Up 2 Back
					case 'w': // Full Clock Forward
					case 'x': // Full Clock Back
					case 'y': // Full Count Forward
					case 'z': // Full Count Back
						*c     = c2;
						*(c+1) = s1 + 4 + (*(c+1) - 'o');
						c+=2;
						break;

					case 'L': // 2x Forward
					case 'M': // 2x Back
						*c     = c2;
						*(c+1) = s1 + 16 + (*(c+1) - 'L');
						c+=2;
						break;

					case '|': // Jump
						*c     = c2;
						*(c+1) = s1 + 18;
						c+=2;
						break;
					case 'O': // Hold
						*c     = c2;
						*(c+1) = s1 + 19;
						c+=2;
						break;
					case '?': // DIR
						*c     = c2;
						*(c+1) = s1 + 20;
						c+=2;
						break;

					case 'Q': // Dragon Punch Forward
					case 'R': // Dragon Punch Back
						*c     = c2;
						*(c+1) = s1 + 21 + (*(c+1) - 'Q');
						c+=2;
						break;

					case '=': // Air
						*c     = c2;
						*(c+1) = s1 + 23;
						c+=2;
						break;
					case '-': // Squatting
						*c     = c2;
						*(c+1) = s1 + 24;
						c+=2;
						break;
					case ']': // Close
						*c     = c2;
						*(c+1) = s1 + 25;
						c+=2;
						break;
					case '[': // Away
						*c     = c2;
						*(c+1) = s1 + 26;
						c+=2;
						break;
					case '~': // Charge
						*c     = c2;
						*(c+1) = s1 + 27;
						c+=2;
						break;

					default:
						c++;
						break;
				}
			}

			else if (*c == '#')
			{
				if ( isLOGO8(LOGO_mbox32_high) )		// 엠박스32 로고(상단)
				{
					iLOGO8(c3, logo_mbox32)
				}
				else if ( isLOGO8(LOGO_mbox32_low) )	// 엠박스32 로고(하단)
				{
					iLOGO8(c3, (logo_mbox32 + 4))
				}

				else if ( isLOGO8(LOGO_second_high) )	// 마메야 로고(상단)
				{
					iLOGO8(c3, logo_second)
				}
				else if ( isLOGO8(LOGO_second_low) )	// 마메야 로고(하단)
				{
					iLOGO8(c3, (logo_second + 4))
				}

				else if ( isLOGO6(LOGO_deco_mbox) )		// 엠박스32 개발자 로고
				{
					iLOGO6(c3, (deco_mbox32))
				}

				else
					c++;
			}

			else if (*c == '\\' && *(c+1) == 'n')
			{
				*c     = ' ';
				*(c+1) = '\n';
				c+=2;
			}
			else
				c++;
		}
	}
}
#undef isLOGO6
#undef isLOGO8
#undef iLOGO6
#undef iLOGO8
