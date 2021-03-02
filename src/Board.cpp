/*
 * Board.cpp
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#include "Board.h"

Board::Board(Players p1, Players p2):dice1(0), dice2(0), player1(p1), player2(p2), player1Off(0), player2Off(0) {

	for(int i = 0; i < 24; i++){
		Case currCase;
		if(i == 1)
			Case currCase(2, 0);
		else if(i == 6)
			Case currCase(0, 5);
		else if(i == 8)
			Case currCase(0, 3);
		else if(i == 12)
			Case currCase(5, 0);
		else if(i == 13)
			Case currCase(0, 5);
		else if(i == 17)
			Case currCase(3, 0);
		else if(i == 19)
			Case currCase(5, 0);
		else if(i == 24)
			Case currCase(0, 2);
		else
			Case currCase;

		mainBoard.push_back(currCase);
	}
}

Board::~Board() {

}

