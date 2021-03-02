/*
 * Players.cpp
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#include "Players.h"
#include <time.h>

Players::Players():score(0) {

}

Players::~Players() {

}

void Players::movePiece(Pieces piece) {

}

const string &Players::getPlayName() const {
    return playName;
}

void Players::setPlayName(const string &playName) {
    Players::playName = playName;
}

int Players::getScore() const {
    return score;
}

void Players::setScore(int score) {
    Players::score = score;
}

const vector<Pieces> &Players::getPieceList() const {
    return pieceList;
}

void Players::setPieceList(const vector<Pieces> &pieceList) {
    Players::pieceList = pieceList;
}

Players::Players(const string &playName) : playName(playName) ,score(0) {

}

void Players::rollDice() {
    srand (time(NULL));
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;
}

int Players::getDice1() const {
    return dice1;
}

int Players::getDice2() const {
    return dice2;
}

