//============================================================================
// Name        : backgammonGame.cpp
// Author      : Samuel Lamontagne &
// Version     :
// Copyright   : Your copyright notice
// Description : backgammon game program
//============================================================================

#include <iostream>
#include "Players.h"
#include "Board.h"

using namespace std;

bool firstPass = true;

int rollDice(){

	if(firstPass){

		firstPass = false;
		auto seed = static_cast<default_random_engine::result_type>(chrono::high_resolution_cliock::now().time_since_epoch().count());
		auto engine = default_random_engine(seed);
		auto gen1to6 = bind(uniform_int_distribution<>{1, 6}, engine);
	}
	return gen1to6();
}


int main() {



	Players play1("jim");
	Players play2;
	Board gameBoard(play1, play2);
	int diceChoice;
	int caseChoice;
	int diceValue;
	int turn = 1;
	int dice1;
	int dice2;

	/*
	if(turn % 2 == 0){
		play1Turn
	} else {
		play2Turn
	}
	*/

	cout << "Which dice do you want to play ? 1 or 2" << endl;

	cin >> diceChoice;

	if(diceChoice == 1)
		diceValue = dice1;
	else if(diceChoice == 2)
		diceValue = dice2;
	else
		cout << "Please choose a value between 1 and 2." << endl;

	cout << "Which case do you want to move from? 1-24" << endl;

	cin >> caseChoice;

	gameBoard.movePiecePlayer1(caseChoice, caseChoice + diceValue);



	return 0;
}
