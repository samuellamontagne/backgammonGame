/*
 * Board.h
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Players.h"
#include "Case.h"
#include <vector>

using namespace std;

class Board {
public:
	Board(Players p1, Players p2);
	virtual ~Board();


private:
	int dice1;
	int dice2;
	Players player1;
	Players player2;
	vector<Case> mainBoard;
	int player1Off;
	int player2Off;
};

#endif /* BOARD_H_ */
