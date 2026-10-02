/***************************************************************************

  M.A.M.E.32  -  Multiple Arcade Machine Emulator for Win32
  Win32 Portions Copyright (C) 1997-2001 Michael Soderstrom and Chris Kirmse

  This file is part of MAME32, and may only be used, modified and
  distributed under the terms of the MAME license, in "readme.txt".
  By continuing to use, modify or distribute this file you indicate
  that you have read the license and understand and accept it fully.

 ***************************************************************************/
/***************************************************************************
  Original Source from EmeraldMame 185
  2004.5. Modified by DarkCoder for MAME32K PLUS
 ***************************************************************************/

#ifndef MAME32AVI_H
#define MAME32AVI_H

#if defined(MAME_AVI)

//#define AVI_AUDIO
BOOL    AviStartCapture(HWND hwnd, char* filename, struct MAME_AVI_STATUS *AviStatus);

void    AviEndCapture(void);

void    AviAddBitmap(struct mame_bitmap* tBitmap, UINT32* pPalEntries);

void    SetAviFPS(int fps);
int     GetAviCapture(void);

//#ifdef AVI_AUDIO
int		AVI_AudioStream_Start(void);
void	AVI_AudioStream_WriteWaveData(char* lpwav, int len);
//#endif

#endif /* MAME_AVI */

#endif /* MAME32AVI_H */
