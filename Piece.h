#pragma once
#include "Grid.h"

enum Figure
{
	I,
	J,
	L,
	O,
	S,
	T,
	Z
};

class Piece
{
private:
	char** cells;
	Figure type;
public:
	Piece(const unsigned& indx);

	void print()const;
	bool canMoveLeft(const Grid& board)const;
	void rotateRight();

private:
	void createPiece(const unsigned& indx);
};