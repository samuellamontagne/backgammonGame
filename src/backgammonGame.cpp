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

	gameBoard.print();

//	cout << "Greetings " << play1.getPlayName() << " and " << play2.getPlayName() << endl;
//
//	cout << "Good Luck !" << endl;
//
//	cout << "To determine who starts let's roll dices !" << endl;
//
//	//Roll the dices while they are the same to determine who goes first.
//	do{
//		dice1 = rollDice();
//		dice2 = rollDice();
//
//		cout << play1.getPlayName() << " got " << dice1 << " and " << play2.getPlayName() << " got " << dice2 << endl;
//
//		if(dice1 == dice2){
//			cout << " It's a Tie ! Rerolling..." << endl;
//		}
//
//	}while(dice1 == dice2);
//
//	if(dice1 < dice2){
//		cout << play2.getPlayName() << " won and will start !" << endl;
//	} else {
//		cout << play1.getPlayName() << " won and will start !" << endl;
//		turn++;
//	}
//
//	//Check if any player got all his pieces Off board
//	while(gameBoard.GetNbPiecesOffPlayer1() != 15 || gameBoard.GetNbPiecesOffPlayer2() != 15){
//
//		if(turn % 2 == 0){
//			//Player's 1 turn
//
//			//Roll the dices
//
//			//EVENTUALLY check for pieces that have been captured
//
//			//Ask which dice to play
//
//			//Ask which Piece to move for the first dice
//
//			//Move the other dice
//
//			//Ask which piece to move for this second dice
//
//			//Increment the turn so the other player plays
//
//
//		} else {
//			//Player's 2 turn
//
//			//Roll the dices
//
//			//EVENTUALLY check for pieces that have been captured
//
//			//Ask which dice to play
//
//			//Ask which Piece to move for the first dice
//
//			//Move the other dice
//
//			//Ask which piece to move for this second dice
//
//			//Increment the turn so the other player plays
//
//		}
//
//	}
//
//
//	cout << "Which dice do you want to play ? 1 or 2" << endl;
//
//	cin >> diceChoice;
//
//	if(diceChoice == 1)
//		diceValue = dice1;
//	else if(diceChoice == 2)
//		diceValue = dice2;
//	else
//		cout << "Please choose a value between 1 and 2." << endl;
//
//	cout << "Which case do you want to move from? 1-24" << endl;
//
//	cin >> caseChoice;
//
//	gameBoard.movePiecePlayer1(caseChoice, caseChoice + diceValue);
//


	return 0;
}
