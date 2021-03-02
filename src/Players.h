/*
 * Players.h
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_
#include "Pieces.h"
#include <vector>
#include <iostream>
using namespace std;

class Players {
public:
	Players();

    Players(const string &playName);

    virtual ~Players();
	void movePiece(Pieces piece);

    void rollDice();


    const string &getPlayName() const;

    void setPlayName(const string &playName);

    int getScore() const;

    void setScore(int score);

    const vector<Pieces> &getPieceList() const;

    void setPieceList(const vector<Pieces> &pieceList);

    int getDice1() const;

    int getDice2() const;


private:
    string playName;
    int score;
    vector<Pieces> pieceList;
    int dice1=0;
    int dice2=0;
};


#endif /* PLAYERS_H_ */
