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
            currCase.setNbPiecesPlayer1(2);
		else if(i == 5)
            currCase.setNbPiecesPlayer2(5);
		else if(i == 7)
            currCase.setNbPiecesPlayer2(3);
		else if(i == 11)
            currCase.setNbPiecesPlayer1(5);
		else if(i == 12)
            currCase.setNbPiecesPlayer2(5);
		else if(i == 16)
            currCase.setNbPiecesPlayer2(3);
		else if(i == 18)
            currCase.setNbPiecesPlayer1(5);
		else if(i == 23)
            currCase.setNbPiecesPlayer2(2);
/*		//Test case 1 capture
		else if(i == 23){
			currCase.setNbPiecesPlayer2(1);
			captured2 = 1;
		}
		//Test case 2 capture
		else if(i == 23){
			captured2 = 2;
		}*/

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
            mainBoard.at(movedTo -1).decrementNbPiecesPlayer2();
            captured2++;
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
            mainBoard.at(movedTo -1).decrementNbPiecesPlayer1();
            captured1++;
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
    if (playerName == player1.getPlayName()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    } else if (playerName == player2.getPlayName()) {
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
        cout << setw(20) << left << player1.getPlayName();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout << setfill(' ') << setw(21) << right << player2.getPlayName() << endl;
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
        cout << setw(20) << left << "Captured:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout << setfill(' ') << setw(19) << right << ":Captured" << "*" << endl;
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
        basicString=player1.getPlayName();
        basicString1=to_string(num1);
    }else if(num2>0 && num1==0){
        basicString=player2.getPlayName();
        basicString1=to_string(num2);
    }else{
        basicString="none";
        basicString1="0";
    }

}

int Board::getCaptured1() const {
    return captured1;
}

void Board::setCaptured1(int captured1) {
    Board::captured1 = captured1;
}

int Board::getCaptured2() const {
    return captured2;
}

void Board::setCaptured2(int captured2) {
    Board::captured2 = captured2;
}

bool Board::hasCapturedPieces(const string& playerName) {
    if(playerName==player1.getPlayName()){
        return captured1 > 0;
    } else if(playerName==player2.getPlayName()){
        return captured2 > 0;
    }else{
        cout << "Error with player name";
    }
}

bool Board::isCapturedPiecesStucked(const string& playName,const int &d1, const int &d2=0) {

    if(playName==player1.getPlayName()){
       if(mainBoard.at(d1-1).getNbPiecesPlayer2() >1 || d2 != 0 && mainBoard.at(d2 - 1).getNbPiecesPlayer2() > 1){
           return true;
       }else{
           return false;
       }

    } else if(playName==player2.getPlayName()){
        if(mainBoard.at(d1-1).getNbPiecesPlayer1() >1 || d2 != 0 && mainBoard.at(d2 - 1).getNbPiecesPlayer1() > 1){
            return true;
        }else{
            return false;
        }
    }else{
        cout << "Error with player name";
    }
}



