/***************************************************************************

  M.A.M.E.32  -  Multiple Arcade Machine Emulator for Win32
  Win32 Portions Copyright (C) 1997-2003 Michael Soderstrom and Chris Kirmse

  This file is part of MAME32, and may only be used, modified and
  distributed under the terms of the MAME license, in "readme.txt".
  By continuing to use, modify or distribute this file you indicate
  that you have read the license and understand and accept it fully.

***************************************************************************/

/***************************************************************************

  layout.c

  MAME specific TreeView definitions (and maybe more in the future)

***************************************************************************/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <shellapi.h>
#include <commctrl.h>
#include <stdio.h>  /* for sprintf */
#include <stdlib.h> /* For malloc and free */
#include <string.h>

#include "bitmask.h"
#include "TreeView.h"
#include "M32Util.h"
#include "resource.h"
#include "directories.h"
#include "options.h"
#include "splitters.h"
#include "help.h"
#include "audit32.h"
#include "screenshot.h"
#include "win32ui.h"
#include "properties.h"

static BOOL FilterAvailable(int driver_index);

FOLDERDATA g_folderData[] =
{
	{"모든 게임",       "allgames",          FOLDER_ALLGAMES,     IDI_FOLDER,				0,             0,            NULL,                       NULL,              TRUE },
	{"사용가능한 게임", "available",         FOLDER_AVAILABLE,    IDI_FOLDER_AVAILABLE,     F_AVAILABLE,   0,            NULL,                       FilterAvailable,              TRUE },
#ifdef SHOW_UNAVAILABLE_FOLDER
	{"미 보유",         "unavailable",       FOLDER_UNAVAILABLE,  IDI_FOLDER_UNAVAILABLE,	0,             F_AVAILABLE,  NULL,                       FilterAvailable,              FALSE },
#endif
	{"제작사",          "manufacturer",      FOLDER_MANUFACTURER, IDI_FOLDER_MANUFACTURER,  0,             0,            CreateManufacturerFolders },
	{"제작 년도",       "year",              FOLDER_YEAR,         IDI_FOLDER_YEAR,          0,             0,            CreateYearFolders },
	{"소스",            "source",            FOLDER_SOURCE,       IDI_FOLDER_SOURCE,        0,             0,            CreateSourceFolders },
	{"CPU",             "cpu",               FOLDER_CPU,          IDI_FOLDER,               0,             0,            CreateCPUFolders },
	{"사운드",          "sound",             FOLDER_SND,          IDI_FOLDER,               0,             0,            CreateSoundFolders },
	{"화면 방향",       "orientation",       FOLDER_ORIENTATION,  IDI_FOLDER,               0,             0,            CreateOrientationFolders },
	{"불완전",          "imperfect",         FOLDER_DEFICIENCY,   IDI_FOLDER,               0,             0,            CreateDeficiencyFolders },
	{"실행 가능",       "working",           FOLDER_WORKING,      IDI_WORKING,              F_WORKING,     F_NONWORKING, NULL,                       DriverIsBroken,    FALSE },
	{"실행 불가능",     "nonworking",        FOLDER_NONWORKING,   IDI_NONWORKING,           F_NONWORKING,  F_WORKING,    NULL,                       DriverIsBroken,    TRUE },
	{"원본롬",          "originals",         FOLDER_ORIGINAL,     IDI_FOLDER,               F_ORIGINALS,   F_CLONES,     NULL,                       DriverIsClone,     FALSE },
	{"클론롬",          "clones",            FOLDER_CLONES,       IDI_FOLDER,               F_CLONES,      F_ORIGINALS,  NULL,                       DriverIsClone,     TRUE },
	{"라스터",          "raster",            FOLDER_RASTER,       IDI_FOLDER,               F_RASTER,      F_VECTOR,     NULL,                       DriverIsVector,    FALSE },
	{"벡터",            "vector",            FOLDER_VECTOR,       IDI_FOLDER,               F_VECTOR,      F_RASTER,     NULL,                       DriverIsVector,    TRUE },
	{"트랙볼",          "trackball",         FOLDER_TRACKBALL,    IDI_FOLDER,               0,             0,            NULL,                       DriverUsesTrackball,	TRUE },
	{"라이트건",        "Lightgun",          FOLDER_LIGHTGUN,     IDI_FOLDER,               0,             0,            NULL,                       DriverUsesLightGun,TRUE },
	{"스테레오",        "stereo",            FOLDER_STEREO,       IDI_SOUND,                0,             0,            NULL,                       DriverIsStereo,    TRUE },
 	{"멀티-모니터",     "multimon",          FOLDER_MULTIMON,     IDI_FOLDER,               0,             0,            NULL,                       DriverIsMultiMon,  TRUE },
	{"하드 디스크",     "harddisk",          FOLDER_HARDDISK,     IDI_HARDDISK,             0,             0,            NULL,                       DriverIsHarddisk,  TRUE },
  	{"샘플",    	    "samples",           FOLDER_SAMPLES,      IDI_FOLDER,               0,             0,            NULL,                       DriverUsesSamples,  TRUE },
	{ NULL }
};

/* list of filter/control Id pairs */
FILTER_ITEM g_filterList[] =
{
	{ F_CLONES,       IDC_FILTER_CLONES,      DriverIsClone, TRUE },
	{ F_NONWORKING,   IDC_FILTER_NONWORKING,  DriverIsBroken, TRUE },
	{ F_UNAVAILABLE,  IDC_FILTER_UNAVAILABLE, FilterAvailable, FALSE },
	{ F_RASTER,       IDC_FILTER_RASTER,      DriverIsVector, FALSE },
	{ F_VECTOR,       IDC_FILTER_VECTOR,      DriverIsVector, TRUE },
	{ F_ORIGINALS,    IDC_FILTER_ORIGINALS,   DriverIsClone, FALSE },
	{ F_WORKING,      IDC_FILTER_WORKING,     DriverIsBroken, FALSE },
	{ F_AVAILABLE,    IDC_FILTER_AVAILABLE,   FilterAvailable, TRUE },
	{ 0 }
};

DIRECTORYINFO g_directoryInfo[] =
{
	{ "롬(ROM)",                  GetRomDirs,      SetRomDirs,      TRUE,  DIRDLG_ROMS		},
	{ "샘플(Samples)",            GetSampleDirs,   SetSampleDirs,   TRUE,  DIRDLG_SAMPLES	},
	{ "Ini 파일",                 GetIniDir,       SetIniDir,       FALSE, DIRDLG_INI		},
	{ "Config",                   GetCfgDir,       SetCfgDir,       FALSE, DIRDLG_CFG		},
	{ "High Scores",              GetHiDir,        SetHiDir,        FALSE, DIRDLG_HI		},
	{ "스냅샷",                   GetImgDir,       SetImgDir,       FALSE, DIRDLG_IMG		},
	{ "Input files (*.inp)",      GetInpDir,       SetInpDir,       FALSE, DIRDLG_INP		},
#ifdef MAME_AVI
	{ "AVI 파일 (*.avi)",         GetAviDir,       SetAviDir,       FALSE, DIRDLG_AVI		},
#endif
	{ "State",                    GetStateDir,     SetStateDir,     FALSE, 0 },
	{ "Artwork",                  GetArtDir,       SetArtDir,       FALSE, 0 },
	{ "메모리 카드",              GetMemcardDir,   SetMemcardDir,   FALSE, 0 },
	{ "광고 전단",                GetFlyerDir,     SetFlyerDir,     FALSE, 0 },
	{ "게임기(Cabinets)",         GetCabinetDir,   SetCabinetDir,   FALSE, 0 },
	{ "게임기 표지(Marquees)",    GetMarqueeDir,   SetMarqueeDir,   FALSE, 0 },
	{ "타이틀",                   GetTitlesDir,    SetTitlesDir,    FALSE, 0 },
	{ "제어판",                   GetControlPanelDir,SetControlPanelDir, FALSE, 0 },
	{ "NVRAM",                    GetNvramDir,     SetNvramDir,     FALSE, 0 },
	{ "컨트롤러 파일",            GetCtrlrDir,     SetCtrlrDir,     FALSE, DIRDLG_CTRLR },
	{ "하드 드라이브 Difference", GetDiffDir,      SetDiffDir,      FALSE, 0 },
	{ "아이콘",                   GetIconsDir,     SetIconsDir,     FALSE, 0 },
	{ "배경 이미지",              GetBgDir,        SetBgDir,        FALSE, 0 },
	{ NULL }
};

const SPLITTERINFO g_splitterInfo[] =
{
	{ 0.25,	IDC_SPLITTER,	IDC_TREE,	IDC_LIST,		AdjustSplitter1Rect },
	{ 0.5,	IDC_SPLITTER2,	IDC_LIST,	IDC_SSFRAME,	AdjustSplitter2Rect },
	{ -1 }
};

const MAMEHELPINFO g_helpInfo[] =
{
	{ ID_HELP_CONTENTS,		TRUE,	MAME32HELP "::/html/mame32_overview.htm" },
	{ ID_HELP_WHATS_NEW32,	TRUE,	MAME32HELP "::/html/mame32_changes.htm" },
	{ ID_HELP_TROUBLE,		TRUE,	MAME32HELP "::/html/mame32_support.htm" },
	{ ID_HELP_RELEASE,		FALSE,	"windows.txt" },
	{ ID_HELP_WHATS_NEW,	TRUE,	MAME32HELP "::/docs/whatsnew.txt" },
	{ -1 }
};

const PROPERTYSHEETINFO g_propSheets[] =
{
	{ FALSE,	NULL,					IDD_PROP_GAME,			GamePropertiesDialogProc },
	{ FALSE,	NULL,					IDD_PROP_AUDIT,			GameAuditDialogProc },
	{ TRUE,		NULL,					IDD_PROP_DISPLAY,		GameOptionsProc },
	{ TRUE,		NULL,					IDD_PROP_ADVANCED,		GameOptionsProc },
	{ TRUE,		NULL,					IDD_PROP_DIRECT3D,		GameOptionsProc },
	{ TRUE,		NULL,					IDD_PROP_SOUND,			GameOptionsProc },
	{ TRUE,		NULL,					IDD_PROP_INPUT,			GameOptionsProc },
	{ TRUE,		NULL,					IDD_PROP_MISC,			GameOptionsProc },
	{ TRUE,		PropSheetFilter_Vector,	IDD_PROP_VECTOR,		GameOptionsProc },
#ifdef M32K_PLUS
	{ TRUE,		NULL,					IDD_PROP_PLUS,			GameOptionsProc },
#endif
	{ FALSE }
};

const ICONDATA g_iconData[] =
{
	{ IDI_WIN_NOROMS,			"noroms" },
	{ IDI_WIN_ROMS,				"roms" },
	{ IDI_WIN_UNKNOWN,			"unknown" },
	{ IDI_WIN_CLONE,			"clone" },
	{ IDI_WIN_REDX,				"warning" },
	{ 0 }
};

const char g_szPlayGameString[] = "%s 실행(&P)";
const char g_szGameCountString[] = "%d 게임들";
const char g_szHistoryFileName[] = "history.dat";
const char g_szMameInfoFileName[] = "mameinfo.dat";

static BOOL FilterAvailable(int driver_index)
{
	return IsAuditResultYes(GetRomAuditResults(driver_index));
}
