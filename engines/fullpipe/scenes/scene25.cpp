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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "fullpipe/fullpipe.h"

#include "fullpipe/objectnames.h"
#include "fullpipe/constants.h"

#include "fullpipe/gameloader.h"
#include "fullpipe/motion.h"
#include "fullpipe/scenes.h"
#include "fullpipe/statics.h"

#include "fullpipe/interaction.h"
#include "fullpipe/behavior.h"


namespace Fullpipe {

void scene25_showBoardOnRightFar() {
	g_vars->scene25_board->show1(453, 557, MV_BRD25_RIGHT, 0);
	g_vars->scene25_board->_priority = 28;
}

void scene25_showBoardOnRightClose() {
	g_vars->scene25_board->show1(632, 557, rMV_BRD25_RIGHT, 0);
	g_vars->scene25_board->_priority = 28;
}

void scene25_initScene(Scene *sc, int entranceId) {
	g_vars->scene25_var01 = 200;
	g_vars->scene25_var02 = 200;
	g_vars->scene25_var03 = 300;
	g_vars->scene25_var04 = 300;
	g_vars->scene25_water = sc->getStaticANIObject1ById(ANI_WATER25, -1);
	g_vars->scene25_board = sc->getStaticANIObject1ById(ANI_BOARD25, -1);
	g_vars->scene25_drop = sc->getStaticANIObject1ById(ANI_DROP_25, -1);
	g_vars->scene25_water->setAlpha(0xa0);
	g_vars->scene25_drop->setAlpha(0xa0);
	g_vars->scene25_var05 = 0;

	if (g_fp->getObjectState(sO_Pool) < g_fp->getObjectEnumState(sO_Pool, sO_HalfFull)) {
		g_vars->scene25_var06 = 0;

		g_vars->scene25_water->hide();
	} else {
		g_vars->scene25_var06 = 1;

		g_fp->playSound(SND_25_006, 1);
	}

	int boardState = g_fp->getObjectState(sO_Board_25);

	if (entranceId == TrubaRight) {
		if (boardState == g_fp->getObjectEnumState(sO_Board_25, sO_FarAway)) {
			scene25_showBoardOnRightFar();

			g_fp->playSound(SND_25_029, 0);

			g_vars->scene25_var07 = 0;
		} else {
			if (boardState == g_fp->getObjectEnumState(sO_Board_25, sO_Nearby)
				|| boardState == g_fp->getObjectEnumState(sO_Board_25, sO_WithDudeOnRight))
				scene25_showBoardOnRightClose();
			g_vars->scene25_var07 = 0;
		}
	} else {
		if (boardState == g_fp->getObjectEnumState(sO_Board_25, sO_WithDudeOnLeft)) {
			if (!getGameLoaderInventory()->getCountItemsWithId(ANI_INV_BOARD)) {
				getGameLoaderInventory()->addItem(ANI_INV_BOARD, 1);
				getGameLoaderInventory()->rebuildItemRects();
			}
		} else {
			g_vars->scene25_var07 = 1;
		}
	}

	g_vars->scene25_var08 = 0;
	g_vars->scene25_var09 = 0;
}

int scene25_updateCursor() {
	g_fp->updateCursorCommon();

	if (g_vars->scene25_var06) {
		int inv = getGameLoaderInventory()->getSelectedItemId();

		if (g_fp->_objectIdAtCursor == ANI_WATER25) {
			if ((g_vars->scene25_var07 && (!inv || inv == ANI_INV_BOARD)) || (g_vars->scene25_var05 && (inv == ANI_INV_LOPAT || !inv)))
				g_fp->_cursorId = (g_fp->_cursorId != PIC_CSR_DEFAULT) ? PIC_CSR_ITN : PIC_CSR_ITN_INV; // FIXME check
		} else if (g_fp->_objectIdAtCursor == ANI_BOARD25 && (!inv || inv == ANI_INV_SWAB || inv == ANI_INV_BROOM || inv == ANI_INV_LOPAT)) {
			g_fp->_cursorId = (g_fp->_cursorId != PIC_CSR_DEFAULT) ? PIC_CSR_ITN : PIC_CSR_ITN_INV;
		}
	}

	return g_fp->_cursorId;
}

void scene25_setupWater(Scene *a1, int entranceId) {
	if (g_vars->scene25_var06) {
		g_fp->_behaviorManager->setBehaviorEnabled(g_vars->scene25_drop, ST_DRP25_EMPTY, QU_DRP25_TOFLOOR, 0);
		g_fp->_behaviorManager->setBehaviorEnabled(g_vars->scene25_drop, ST_DRP25_EMPTY, QU_DRP25_TOWATER, 1);

		if (entranceId != TrubaRight)
			g_fp->playTrack(g_fp->getGameLoaderGameVar()->getSubVarByName("SC_25"), "MUSIC2", 0);
	} else {
		g_fp->_behaviorManager->setBehaviorEnabled(g_vars->scene25_drop, ST_DRP25_EMPTY, QU_DRP25_TOFLOOR, 1);
		g_fp->_behaviorManager->setBehaviorEnabled(g_vars->scene25_drop, ST_DRP25_EMPTY, QU_DRP25_TOWATER, 0);
	}
}

} // End of namespace Fullpipe