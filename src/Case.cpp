/*
 * Case.cpp
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#include "Case.h"

Case::Case(int nbPiece1, int nbPiece2) {
    nbPiecesPlayer1=nbPiece1;
    nbPiecesPlayer2=nbPiece2;
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

int Case::getNbPiecesPlayer1() const {
    return nbPiecesPlayer1;
}

int Case::getNbPiecesPlayer2() const {
    return nbPiecesPlayer2;
}

Case::Case():nbPiecesPlayer1(0),nbPiecesPlayer2(0) {

}

void Case::setNbPiecesPlayer1(int nbPiecesPlayer1) {
    Case::nbPiecesPlayer1 = nbPiecesPlayer1;
}

void Case::setNbPiecesPlayer2(int nbPiecesPlayer2) {
    Case::nbPiecesPlayer2 = nbPiecesPlayer2;
}
