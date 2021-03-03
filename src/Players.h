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

    const string &getPlayName() const;

    void setPlayName(const string &playName);

    int getScore() const;

    void setScore(int score);




private:
    string playName;
    int score;
    static int playerCount;


};


#endif /* PLAYERS_H_ */
