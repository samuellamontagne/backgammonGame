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
	void movePiecePlayer1(int movedFrom, int movedTo);
	void movePiecePlayer2(int movedFrom, int movedTo);
	int GetNbPiecesOffPlayer1();
	int GetNbPiecesOffPlayer2();
	void print();


private:
	int dice1;
	int dice2;
	Players player1;
	Players player2;
	vector<Case> mainBoard;
	int player1Off;
	int player2Off;

    void setColor(string playerName);

    string getName(int id);

    string addZeroForLessThan10(const int &num);

    void getSize(int num1, int num2, string& basicString, string& basicString1);
};

#endif /* BOARD_H_ */
