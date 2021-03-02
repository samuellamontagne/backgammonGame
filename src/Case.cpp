/*
 * Case.cpp
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#include "Case.h"

Case::Case(int nbPiece1, int nbPiece2):nbPiecesPlayer1(nbPiece1), nbPiecesPlayer2(nbPiece2) {
	// TODO Auto-generated constructor stub

}

Case::~Case() {
	// TODO Auto-generated destructor stub
}

void Case::incrementNbPiecesPlayer1(){
	nbPiecesPlayer1++;
}

void Case::incrementNbPiecesPlayer2(){
	nbPiecesPlayer2++;
}

void Case::decrementNbPiecesPlayer1(){
	nbPiecesPlayer1--;
}

void Case::decrementNbPiecesPlayer2(){
	nbPiecesPlayer2--;
}

int Case::GetNbPiecesPlayer1(){
	return nbPiecesPlayer1;
}
int Case::GetNbPiecesPlayer2(){
	return nbPiecesPlayer2;
}
