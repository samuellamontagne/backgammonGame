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

	//Return -1 if there is no pieces to move from the choosed space
	//Return 1 if the pieces has been moved
	int movePiecePlayer1(int movedFrom, int movedTo);
	int movePiecePlayer2(int movedFrom, int movedTo);
	int GetNbPiecesOffPlayer1();
	int GetNbPiecesOffPlayer2();
	void print();

    int getCaptuted1() const;

    void setCaptuted1(int captuted1);

    int getCaptuted2() const;

    void setCaptuted2(int captuted2);

    bool hasCapturedPieces(string playerName);

    bool isCapturedPiecesStucked(const int& d1, const int& d2, const string& PlayerName );

private:
	int dice1;
	int dice2;
	Players player1;
	Players player2;
	vector<Case> mainBoard;
	int player1Off;
	int player2Off;

	int captured1 = 0;
	int captured2 = 0;

    void setColor(string playerName);

    string getName(int id);

    string addZeroForLessThan10(const int &num);

    void getSize(int num1, int num2, string& basicString, string& basicString1);
};

#endif /* BOARD_H_ */
