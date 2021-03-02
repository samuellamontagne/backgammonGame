//============================================================================
// Name        : backgammonGame.cpp
// Author      : Samuel Lamontagne &
// Version     :
// Copyright   : Your copyright notice
// Description : backgammon game program
//============================================================================

#include <iostream>
#include "Players.h"

using namespace std;

int main() {

 Players play1("jim");
 play1.rollDice();
 cout <<play1.getDice1()<<endl;
 cout <<play1.getDice2()<<endl;
 return 0;
}
