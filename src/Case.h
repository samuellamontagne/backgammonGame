/*
 * Case.h
 *
 *  Created on: Mar. 2, 2021
 *      Author: samuel
 */

#ifndef CASE_H_
#define CASE_H_

class Case {
public:
    void setNbPiecesPlayer1(int nbPiecesPlayer1);

    void setNbPiecesPlayer2(int nbPiecesPlayer2);

    Case();
	Case(int nbPiece1, int nbPiece2 );
	virtual ~Case();
	void incrementNbPiecesPlayer1();
	void incrementNbPiecesPlayer2();
	void decrementNbPiecesPlayer1();
	void decrementNbPiecesPlayer2();
	int GetNbPiecesPlayer1();
	int GetNbPiecesPlayer2();

    int getNbPiecesPlayer1() const;

    int getNbPiecesPlayer2() const;

private:
	int nbPiecesPlayer1;
	int nbPiecesPlayer2;
};

#endif /* CASE_H_ */
