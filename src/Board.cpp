/*
 * Board.cpp
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#include "Board.h"
#include <iomanip>
#include "windows.h"

Board::Board(Players p1, Players p2):dice1(0), dice2(0), player1(p1), player2(p2), player1Off(0), player2Off(0) {

	for(int i = 0; i < 24; i++){
		Case currCase;
		if(i == 0)
			Case currCase(2, 0);
		else if(i == 5)
			Case currCase(0, 5);
		else if(i == 7)
			Case currCase(0, 3);
		else if(i == 11)
			Case currCase(5, 0);
		else if(i == 12)
			Case currCase(0, 5);
		else if(i == 16)
			Case currCase(3, 0);
		else if(i == 18)
			Case currCase(5, 0);
		else if(i == 23)
			Case currCase(0, 2);
		else
			Case currCase;

		mainBoard.push_back(currCase);
	}
}

Board::~Board() {

}

int Board::movePiecePlayer1(int movedFrom, int movedTo){

	int rtn = -1;
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
			rtn = 1;
		} else {
			mainBoard.at(movedFrom - 1).decrementNbPiecesPlayer1();
			mainBoard.at(movedTo - 1).incrementNbPiecesPlayer1();
			rtn = 1;
		}
		//mainBoard.printBoard();
	}
	return rtn;
}

int Board::movePiecePlayer2(int movedFrom, int movedTo){

	int rtn = -1;
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
			rtn = 1;
		} else {
			mainBoard.at(movedFrom - 1).decrementNbPiecesPlayer2();
			mainBoard.at(movedTo - 1).incrementNbPiecesPlayer2();
			rtn = 1;
		}
		//mainBoard.printBoard();
	}
	return rtn;
}

int Board::GetNbPiecesOffPlayer1(){
	return player1Off;
}
int Board::GetNbPiecesOffPlayer2(){
	return player2Off;
}

string Board::addZeroForLessThan10(const int &num) {
    if (num < 10) {
        return "0" + to_string(num);
    } else {
        return to_string(num);
    }
}


string Board::getName(int id) {
    if (id == 1) {
        return "player1";
    } else if (id == 2) {
        return "player2";
    } else {
        return "none";
    }
}


void Board::setColor(string playerName) {
    if (playerName == "player1") {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    } else if (playerName == "player2") {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

void Board::print() {
        cout << setfill('*') << setw(41) << right << "" << endl;
        cout << setfill(' ');
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << setw(20) << left << "Player1:red";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout << setfill(' ') << setw(21) << right << "Player2:green" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << setfill('*') << setw(41) << right << "" << endl;
        int player1PieceNum;
        int player2PieceNum;

        string playerName;
        string pieces;
        for (int i = 0; i < 6; i++) {

            player1PieceNum = mainBoard[12 + i].getNbPiecesPlayer1();
            player2PieceNum = mainBoard[12 + i].getNbPiecesPlayer2();
            getSize(player1PieceNum,player2PieceNum,playerName,pieces);
            setColor(playerName);
            cout << setfill(' ');
            cout << setw(20) << left << "* " + to_string(13 + i) + "|" + pieces << " ";


            player1PieceNum = mainBoard[11 - i].getNbPiecesPlayer1();
            player2PieceNum = mainBoard[11 - i].getNbPiecesPlayer2();
            getSize(player1PieceNum,player2PieceNum,playerName,pieces);

            setColor(playerName);
            cout << setw(20) << right <<pieces + "|" + addZeroForLessThan10(12 - i) + " *" << endl;
            setColor("None");
        }
        cout << "*";
        cout << setfill('-') << setw(39) << right << "" << "*" << endl;
        cout << "*";
        cout << setfill(' ');
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << setw(20) << left << "Player1:red";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout << setfill(' ') << setw(19) << right << "Player2:green" << "*" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "*";
        cout << setfill('-') << setw(39) << right << "" << "*" << endl;


        for (int i = 0; i < 6; i++) {

            player1PieceNum = mainBoard[18 + i].getNbPiecesPlayer1();
            player2PieceNum = mainBoard[18 + i].getNbPiecesPlayer2();
            getSize(player1PieceNum,player2PieceNum,playerName,pieces);

            setColor(playerName);
            cout << setfill(' ');
            cout << setw(20) << left << "* " + to_string(19 + i) + "|" + pieces << " ";

            player1PieceNum = mainBoard[5 -i].getNbPiecesPlayer1();
            player2PieceNum = mainBoard[5 -i].getNbPiecesPlayer2();
            getSize(player1PieceNum,player2PieceNum,playerName,pieces);

            setColor(playerName);
            cout << setw(20) << right << pieces + "|" + addZeroForLessThan10(6 - i) + " *" << endl;
            setColor("None");
        }

        cout << setfill('*') << setw(41) << right << "" << endl;

}

void Board::getSize(int num1, int num2, string& basicString, string& basicString1) {
    if(num1>0 && num2==0){
        basicString="player1";
        basicString1=to_string(num1);
    }else if(num2>0 && num1==0){
        basicString="player1";
        basicString1=to_string(num2);
    }else{
        basicString="none";
        basicString1="0";
    }

}

