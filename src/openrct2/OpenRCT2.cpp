/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "OpenRCT2.h"

sint32 gExitCode;
sint32 gOpenRCT2StartupAction = STARTUP_ACTION_TITLE;
utf8 gOpenRCT2StartupActionPath[512] = { 0 };
utf8 gExePath[MAX_PATH];
utf8 gCustomUserDataPath[MAX_PATH] = { 0 };
utf8 gCustomOpenrctDataPath[MAX_PATH] = { 0 };
utf8 gCustomRCT2DataPath[MAX_PATH] = { 0 };
utf8 gCustomPassword[MAX_PATH] = { 0 };

bool gOpenRCT2Headless = false;
bool gOpenRCT2NoGraphics = false;

bool gOpenRCT2ShowChangelog;
bool gOpenRCT2SilentBreakpad;

uint32 gCurrentDrawCount = 0;
uint8 gScreenFlags;
uint32 gScreenAge;
uint8 gSavePromptMode;
