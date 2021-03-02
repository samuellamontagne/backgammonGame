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

void Board::movePiecePlayer1(int movedFrom, int movedTo){
	if(mainBoard.at(movedFrom -1).GetNbPiecesPlayer1() == 0){
		cout << "No pieces in this space" << endl;
	}
	else{

		if(mainBoard.at(movedTo - 1).GetNbPiecesPlayer2() > 1){
			cout << "Cannot play, because too much pieces from player 2 on case" << endl;
		} else if(mainBoard.at(movedTo - 1).GetNbPiecesPlayer2() == 1){
			//Capture mechanics TO ADD
			mainBoard.at(movedFrom - 1).decrementNbPiecesPlayer1();
			mainBoard.at(movedTo - 1).incrementNbPiecesPlayer1();
		} else {
			mainBoard.at(movedFrom - 1).decrementNbPiecesPlayer1();
			mainBoard.at(movedTo - 1).incrementNbPiecesPlayer1();
		}
		//mainBoard.printBoard();
	}
}

void Board::movePiecePlayer2(int movedFrom, int movedTo){
	if(mainBoard.at(movedFrom -1).GetNbPiecesPlayer2() == 0){
		cout << "No pieces in this space" << endl;
	}
	else{

		if(mainBoard.at(movedTo - 1).GetNbPiecesPlayer1() > 1){
			cout << "Cannot play, because too much pieces from player 1 on case" << endl;
		} else if(mainBoard.at(movedTo - 1).GetNbPiecesPlayer1() == 1){
			//Capture mechanics TO ADD
			mainBoard.at(movedFrom - 1).decrementNbPiecesPlayer2();
			mainBoard.at(movedTo - 1).incrementNbPiecesPlayer2();
		} else {
			mainBoard.at(movedFrom - 1).decrementNbPiecesPlayer2();
			mainBoard.at(movedTo - 1).incrementNbPiecesPlayer2();
		}
		//mainBoard.printBoard();
	}
}

int Board::GetNbPiecesOffPlayer1(){
	return player1Off;
}
int Board::GetNbPiecesOffPlayer2(){
	return player2Off;
}

