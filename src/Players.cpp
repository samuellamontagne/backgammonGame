/*
 * Players.cpp
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#include "Players.h"
#include "Case.h"
#include <time.h>

Players::Players():score(0) {
    if(playerCount>2){
        throw "game just allow 2 persons";
    }
    playName="player"+to_string(playerCount);
    playerCount++;
}

Players::~Players() {

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


Players::Players(const string &playName) : playName(playName) ,score(0) {
    if(playerCount>2){
        throw "game just allow 2 persons";
    }
    playerCount++;
}

int Players::playerCount = 1;
