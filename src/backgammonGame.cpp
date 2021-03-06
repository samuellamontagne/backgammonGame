//============================================================================
// Name        : backgammonGame.cpp
// Author      : Samuel Lamontagne &
// Version     :
// Copyright   : Your copyright notice
// Description : backgammon game program
//============================================================================

#include <iostream>
#include "Players.h"
#include <random>
#include <chrono>
#include <functional>
#include "Board.h"


using namespace std;

int main() {


	auto seed = static_cast<default_random_engine::result_type>(chrono::high_resolution_clock::now().time_since_epoch().count());
	auto engine = default_random_engine(seed);
	auto rollDice = bind(uniform_int_distribution<>{1, 6}, engine);


	int diceChoice;
	int caseChoice;
	int diceValue;
	int turn = 1;
	int dice1;
	int dice2;
	string tempName;

	cout << "Welcome to our backgammon game !" << endl;

	cout << "Enter player's 1 name : " << endl;

	cin >> tempName;

	Players play1(tempName);

	cout << "Enter player's 2 name : " << endl;

	cin >> tempName;

	Players play2(tempName);

	Board gameBoard(play1, play2);

	cout << "Greetings " << play1.getPlayName() << " and " << play2.getPlayName() << endl;

	cout << "Good Luck !" << endl;

	cout << "To determine who starts let's roll dices !" << endl;

	//Roll the dices while they are the same to determine who goes first.
	do{
		dice1 = rollDice();
		dice2 = rollDice();

		cout << play1.getPlayName() << " got " << dice1 << " and " << play2.getPlayName() << " got " << dice2 << endl;

		if(dice1 == dice2){
			cout << " It's a Tie ! Rerolling..." << endl;
		}

	}while(dice1 == dice2);

	if(dice1 < dice2){
		cout << play2.getPlayName() << " won and will start !" << endl;
	} else {
		cout << play1.getPlayName() << " won and will start !" << endl;
		turn++;
	}
	gameBoard.print();

	//Check if any player got all his pieces Off board
	while(gameBoard.GetNbPiecesOffPlayer1() != 15 || gameBoard.GetNbPiecesOffPlayer2() != 15){

		int choice = 0;
		int movedFrom = 0;
		int movedValid = 0;
		int choosedDice = 0;
		int otherDice = 0;
		bool capturedCheck = false;
		bool capturedStuck = false;
		bool otherDiceUsed = false;
		int captured = 0;

		if(turn % 2 == 0){
			//Player's 1 turn

			//Roll the dices

			dice1 = rollDice();
			dice2 = rollDice();
			captured = gameBoard.getCaptured1();

			//Ask which dice to play

			//EVENTUALLY check for pieces that have been captured
			capturedCheck = gameBoard.hasCapturedPieces(play1.getPlayName());

			//EVENTUALLY Check if captured piece is stuck
			capturedStuck = gameBoard.isCapturedPiecesStucked(dice1, dice2, play1.getPlayName());

			//Ask which dice to play

			do{
				if(capturedCheck)
					cout << "You have a captured piece ! You need to play this one !!" << endl;

				cout << play1.getPlayName() <<  " you rolled a " << dice1 << " (1) and a " << dice2 << " (2)." << endl;
				cout << "Which one would you like to play ?" << endl;

				cin >> choice;

				if(choice > 2)
					cout << "Invalid choice, please choose between 1 and 2" << endl;

			} while(choice > 2);


			//Dice choice
			if(choice == 1){
				choosedDice = dice1;
				otherDice = dice2;
				dice1 = 0;
			}
			if(choice == 2){
				choosedDice = dice2;
				otherDice = dice1;
				dice2 = 0;
			}

			if(capturedCheck){

				if(capturedStuck){
					cout << "Your captured piece is stuck, your turn is over !" << endl;
					turn++;
					continue;

				} else {

					movedValid = gameBoard.movePiecePlayer1(0, 0 + choosedDice);

					//if this move with the choosed dice is blocked, we try the other dice, since we know the piece is not stuck
					if(movedValid == -1){
						cout << "Cannot move this piece there, moving with the other dice" << endl;
						movedValid = gameBoard.movePiecePlayer1(0, 0 + otherDice);
						otherDiceUsed = true;
					}
					gameBoard.setCaptured1(captured--);
				}
			}else{
			//Ask which Piece to move for the first dice
				do{

					cout << "Enter the case of the piece you want to move from" << endl;

					cin >> movedFrom;

					if(movedFrom < 1 && movedFrom > 24)
						cout << "Invalid choice, please choose between 1 and 24" << endl;

					movedValid = gameBoard.movePiecePlayer1(movedFrom, movedFrom + choosedDice);

				} while(movedValid == -1);
			}

			gameBoard.print();

			capturedCheck = false;
			capturedStuck = false;

			//Move the other dice
			//Determine the other dice if we used the second dice because of captured

			if(dice1 == 0 && !otherDiceUsed){
				cout << "Now, you move for the second dice, which is : " << dice2 << endl;
				choosedDice = dice2;
				dice2 = 0;
			}
			else if(dice2 == 0 && !otherDiceUsed){
				cout << "Now, you move for the second dice, which is : " << dice1 << endl;
				choosedDice = dice1;
				dice1 = 0;
			}else if(otherDiceUsed){
				cout << "Now, you move for the second dice, which is : " << choosedDice << endl;
			}

			//EVENTUALLY check for pieces that have been captured
			capturedCheck = gameBoard.hasCapturedPieces(play1.getPlayName());

			//EVENTUALLY Check if captured piece is stuck
			capturedStuck = gameBoard.isCapturedPiecesStucked(choosedDice, play1.getPlayName());

			if(capturedCheck){

				cout << "You have a captured piece ! You need to play this one !!" << endl;

				if(capturedStuck){
					cout << "Your captured piece is stuck, your turn is over !" << endl;
					turn++;
					continue;

				} else {

					movedValid = gameBoard.movePiecePlayer1(0, 0 + choosedDice);
					if(movedValid != -1)
						gameBoard.setCaptured1(captured--);

				}

			}else {

			//Ask which piece to move for this second dice

				do{

					cout << "Enter the case of the piece you want to move from" << endl;

					cin >> movedFrom;

					if(movedFrom < 1 && movedFrom > 24)
						cout << "Invalid choice, please choose between 1 and 24" << endl;

					movedValid = gameBoard.movePiecePlayer1(movedFrom, movedFrom + choosedDice);

				} while(movedValid == -1);
			}

			//Increment the turn so the other player plays

			cout << "Your turn is over !" << endl;
			turn++;

			//Print board again
			gameBoard.print();


		} else {
			//Player's 2 turn

			//Roll the dices

			dice1 = rollDice();
			dice2 = rollDice();
//			dice1 = 5;
//			dice2 = 4;
			captured = gameBoard.getCaptured2();

			//Ask which dice to play

			//EVENTUALLY check for pieces that have been captured
			capturedCheck = gameBoard.hasCapturedPieces(play2.getPlayName());

			//EVENTUALLY Check if captured piece is stuck
			capturedStuck = gameBoard.isCapturedPiecesStucked(dice1, dice2, play2.getPlayName());


			do{

				if(capturedCheck)
					cout << "You have a captured piece ! You need to play this one !!" << endl;

				cout << play2.getPlayName() <<  " you rolled a " << dice1 << " (1) and a " << dice2 << " (2)." << endl;
				cout << "Which one would you like to play ?" << endl;

				cin >> choice;

				if(choice > 2)
					cout << "Invalid choice, please choose between 1 and 2" << endl;

			} while(choice > 2);


			//Dice choice
			if(choice == 1){
				choosedDice = dice1;
				otherDice = dice2;
				dice1 = 0;
			}
			if(choice == 2){
				choosedDice = dice2;
				otherDice = dice1;
				dice2 = 0;
			}



			//Ask which Piece to move for the first dice
			if(capturedCheck){

				if(capturedStuck){
					cout << "Your captured piece is stuck, your turn is over !" << endl;
					turn++;
					continue;

				} else {
					//if this move with the choosed dice is blocked, we try the other dice, since we know the piece is not stuck
					movedValid = gameBoard.movePiecePlayer2(25, 25 - choosedDice);
					if(movedValid == -1){
						cout << "Cannot move this piece there, moving with the other dice" << endl;
						movedValid = gameBoard.movePiecePlayer2(25, 25 - otherDice);
						otherDiceUsed = true;
					}
					gameBoard.setCaptured2(captured--);
				}
			}else{
				do{

					cout << "Enter the case of the piece you want to move from" << endl;

					cin >> movedFrom;

					if(movedFrom < 1 && movedFrom > 24)
						cout << "Invalid choice, please choose between 1 and 24" << endl;

					movedValid = gameBoard.movePiecePlayer2(movedFrom, movedFrom - choosedDice);

				} while(movedValid == -1);
			}

			capturedCheck = false;
			capturedStuck = false;

			gameBoard.print();

			//Move the other dice

			if(dice1 == 0 && !otherDiceUsed){
				cout << "Now, you move for the second dice, which is : " << dice2 << endl;
				choosedDice = dice2;
				dice2 = 0;
			}
			else if(dice2 == 0 && !otherDiceUsed){
				cout << "Now, you move for the second dice, which is : " << dice1 << endl;
				choosedDice = dice1;
				dice1 = 0;
			} else if(otherDiceUsed){
				cout << "Now, you move for the second dice, which is : " << choosedDice << endl;
			}

			//EVENTUALLY check for pieces that have been captured
			capturedCheck = gameBoard.hasCapturedPieces(play2.getPlayName());

			//EVENTUALLY Check if captured piece is stuck
			capturedStuck = gameBoard.isCapturedPiecesStucked(choosedDice, play2.getPlayName());

			//Ask which piece to move for this second dice

			if(capturedCheck){

				cout << "You have a captured piece ! You need to play this one !!" << endl;

				if(capturedStuck){
					cout << "Your captured piece is stuck, your turn is over !" << endl;
					turn++;
					continue;

				} else {

					movedValid = gameBoard.movePiecePlayer2(25, 25 - choosedDice);
					if(movedValid != -1)
						gameBoard.setCaptured1(captured--);
				}
			}else{

				do{

					cout << "Enter the case of the piece you want to move from" << endl;

					cin >> movedFrom;

					if(movedFrom < 1 && movedFrom > 24)
						cout << "Invalid choice, please choose between 1 and 24" << endl;

					movedValid = gameBoard.movePiecePlayer2(movedFrom, movedFrom - choosedDice);

				} while(movedValid == -1);
			}

			//Increment the turn so the other player plays

			cout << "Your turn is over !" << endl;
			turn++;

			//Print board again
			gameBoard.print();

		}
	}

	gameBoard.print();

	//Congratulate the winner and close the game
	if(gameBoard.GetNbPiecesOffPlayer1() == 15){
		cout << endl << endl;
		cout << play1.getPlayName() << ", congratulation, you won the game !" << endl;
		return EXIT_SUCCESS;
	}
	if(gameBoard.GetNbPiecesOffPlayer2() == 15){
		cout << endl << endl;
		cout << play2.getPlayName() << ", congratulation, you won the game !" << endl;
		return EXIT_SUCCESS;
	}


	return 0;
}
