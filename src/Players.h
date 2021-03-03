/*
 * Players.h
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <vector>
#include <iostream>


using namespace std;

const int NumPiece = 15;

class Players {
public:
	Players();

    Players(const string &playName);

    virtual ~Players();

    void rollDice();


    const string &getPlayName() const;

    void setPlayName(const string &playName);

    int getScore() const;

    void setScore(int score);

    int getDice1() const;

    int getDice2() const;



private:
    string playName;
    int score;
    int dice1=0;
    int dice2=0;
    static int playerCount;


};


#endif /* PLAYERS_H_ */
