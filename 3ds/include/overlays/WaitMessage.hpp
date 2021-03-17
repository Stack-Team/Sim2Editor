/*
*   This file is part of Sim2Editor
*   Copyright (C) 2020-2021 Universal-Team
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#ifndef _SIM2EDITOR_WAIT_MESSAGE_HPP
#define _SIM2EDITOR_WAIT_MESSAGE_HPP

#include "Pointer.hpp"
#include <string>
#include <vector>

class WaitMessage {
public:
	WaitMessage(const std::string &Msg); // Also just accept a single string as constructor.
	WaitMessage(const std::vector<std::string> &Msgs) : MMessages(true), Msgs(Msgs) { };
	void Action();
private:
	mutable bool Done = false, MMessages = false;
	mutable int MsgPage = 0;
	std::vector<std::string> Msgs = { };

	void OK();
	void PrevMsg();
	void NextMsg();

	const std::vector<PointerStr> Positions = {
		{ 10, 37, 25, 191, [this]() { this->PrevMsg(); } }, // Prev Message if multiple.
		{ 150, 198, 100, 20, [this]() { this->OK(); } }, // Confirmation with 'OK'.
		{ 365, 37, 25, 191, [this]() { this->NextMsg(); } } // Next Message if multiple.
	};

	/* Same as above, but on the bottom for touch compatibility! */
	const std::vector<PointerStr> BottomPos = {
		{ 70, 75, 25, 90, [this]() { this->PrevMsg(); } },
		{ 123, 109, 74, 22, [this]() { this->OK(); } },
		{ 225, 75, 25, 90, [this]() { this->NextMsg(); } }
	};
};

#endif