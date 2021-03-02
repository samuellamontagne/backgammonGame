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
	Case(int nbPiece1 = 0, int nbPiece2 = 0);
	virtual ~Case();
	void incrementNbPiecesPlayer1();
	void incrementNbPiecesPlayer2();
	void decrementNbPiecesPlayer1();
	void decrementNbPiecesPlayer2();
	int GetNbPiecesPlayer1();
	int GetNbPiecesPlayer2();

private:
	int nbPiecesPlayer1;
	int nbPiecesPlayer2;
};

#endif /* CASE_H_ */
