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

    int getCaptured1() const;

    void setCaptured1(int captured1);

    int getCaptured2() const;

    void setCaptured2(int captured2);

    bool hasCapturedPieces(const string& playerName);

    bool isCapturedPiecesStucked(const int& d1, const int& d2, const string& PlayerName );

    bool isCapturedPiecesStucked(const int &d, const string &playName);

private:
	int dice1;
	int dice2;
	Players player1;
	Players player2;
	vector<Case> mainBoard;
	int player1Off;
	int player2Off;

	int captured1 = 0;
	int captured2 =0;

    void setColor(string playerName);

    string getName(int id);

    string addZeroForLessThan10(const int &num);

    void getSize(int num1, int num2, string& basicString, string& basicString1);


};

#endif /* BOARD_H_ */
