/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef SHERLOCK_SCALPEL_FIXED_TEXT_H
#define SHERLOCK_SCALPEL_FIXED_TEXT_H

#include "sherlock/fixed_text.h"

namespace Sherlock {

namespace Scalpel {

enum FixedTextId {
	// Window buttons
	kFixedText_Window_Exit = 0,
	kFixedText_Window_Up,
	kFixedText_Window_Down,
	// Inventory buttons
	kFixedText_Inventory_Exit,
	kFixedText_Inventory_Look,
	kFixedText_Inventory_Use,
	kFixedText_Inventory_Give,
	// Journal text
	kFixedText_Journal_WatsonsJournal,
	kFixedText_Journal_Page,
	// Journal buttons
	kFixedText_Journal_Exit,
	kFixedText_Journal_Back10,
	kFixedText_Journal_Up,
	kFixedText_Journal_Down,
	kFixedText_Journal_Ahead10,
	kFixedText_Journal_Search,
	kFixedText_Journal_FirstPage,
	kFixedText_Journal_LastPage,
	kFixedText_Journal_PrintText,
	// Journal search
	kFixedText_JournalSearch_Exit,
	kFixedText_JournalSearch_Backward,
	kFixedText_JournalSearch_Forward,
	kFixedText_JournalSearch_NotFound,
	// Press key text
	kFixedText_PressKey_ForMore,
	kFixedText_PressKey_ForMoreHotkey,
	kFixedText_PressKey_ToContinue,
	kFixedText_PressKey_ToContinueHotkey,
	// Initial inventory
	kFixedText_InitInventory_Message,
	kFixedText_InitInventory_HolmesCard,
	kFixedText_InitInventory_Tickets,
	kFixedText_InitInventory_CuffLink,
	kFixedText_InitInventory_WireHook,
	kFixedText_InitInventory_Note,
	kFixedText_InitInventory_OpenWatch,
	kFixedText_InitInventory_Paper,
	kFixedText_InitInventory_Letter,
	kFixedText_InitInventory_Tarot,
	kFixedText_InitInventory_OrnateKey,
	kFixedText_InitInventory_PawnTicket,
	// People names
	kFixedText_People_SherlockHolmes,
	kFixedText_People_DrWatson,
	kFixedText_People_InspectorLestrade,
	kFixedText_People_ConstableOBrien,
	kFixedText_People_ConstableLewis,
	kFixedText_People_SheilaParker,
	kFixedText_People_HenryCarruthers,
	kFixedText_People_Lesley,
	kFixedText_People_AnUsher,
	kFixedText_People_FredrickEpstein,
	kFixedText_People_MrsWorthington,
	kFixedText_People_TheCoach,
	kFixedText_People_APlayer,
	kFixedText_People_Tim,
	kFixedText_People_JamesSanders,
	kFixedText_People_Belle,
	kFixedText_People_CleaningGirl,
	kFixedText_People_Wiggins,
	kFixedText_People_Paul,
	kFixedText_People_TheBartender,
	kFixedText_People_ADirtyDrunk,
	kFixedText_People_AShoutingDrunk,
	kFixedText_People_AStaggeringDrunk,
	kFixedText_People_TheBouncer,
	kFixedText_People_TheCoroner,
	kFixedText_People_ReginaldSnipes,
	kFixedText_People_GeorgeBlackwood,
	kFixedText_People_Lars,
	kFixedText_People_TheChemist,
	kFixedText_People_InspectorGregson,
	kFixedText_People_JacobFarthington,
	kFixedText_People_Mycroft,
	kFixedText_People_OldSherman,
	kFixedText_People_Richard,
	kFixedText_People_TheBarman,
	kFixedText_People_ADandyPlayer,
	kFixedText_People_ARoughlookingPlayer,
	kFixedText_People_ASpectator,
	kFixedText_People_RobertHunt,
	kFixedText_People_Violet,
	kFixedText_People_Pettigrew,
	kFixedText_People_Augie,
	kFixedText_People_AnnaCarroway,
	kFixedText_People_AGuard,
	kFixedText_People_AntonioCaruso,
	kFixedText_People_TobyTheDog,
	kFixedText_People_SimonKingsley,
	kFixedText_People_Alfred,
	kFixedText_People_LadyBrumwell,
	kFixedText_People_MadameRosa,
	kFixedText_People_JosephMoorehead,
	kFixedText_People_MrsBeale,
	kFixedText_People_Felix,
	kFixedText_People_Hollingston,
	kFixedText_People_ConstableCallaghan,
	kFixedText_People_SergeantDuncan,
	kFixedText_People_LordBrumwell,
	kFixedText_People_NigelJaimeson,
	kFixedText_People_Jonas,
	kFixedText_People_ConstableDugan
};

struct FixedTextActionEntry {
	const char *const *fixedTextArray;
	int   fixedTextArrayCount;
};

struct FixedTextLanguageEntry {
	Common::Language language;
	const char *const *fixedTextArray;
	const FixedTextActionEntry *actionArray;
};

class ScalpelFixedText: public FixedText {
private:
	const FixedTextLanguageEntry *_curLanguageEntry;
public:
	ScalpelFixedText(SherlockEngine *vm);
	virtual ~ScalpelFixedText() {}

	/**
	 * Gets text
	 */
	virtual const char *getText(int fixedTextId);

	/**
	 * Get action message
	 */
	virtual const Common::String getActionMessage(FixedTextActionId actionId, int messageIndex);
};

} // End of namespace Scalpel

} // End of namespace Sherlock

#endif
