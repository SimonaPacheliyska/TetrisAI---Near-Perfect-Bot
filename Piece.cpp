#include "Piece.h"
#include <iostream>

using std::cout;
using std::endl;

const short DIMENSION_ROWS = 4;
const short DIMENSION_COLUMNS = 5; // 1 for '\0' ;)

Piece::Piece(const unsigned & indx)
{
	this->cells = new char*[DIMENSION_ROWS] {0};
	for (int row = 0; row < DIMENSION_ROWS; ++row) {
		this->cells[row] = new char[DIMENSION_COLUMNS] {0};
	}
	createPiece(indx);
}

void Piece::print() const
{
	for (int row = 0; row < DIMENSION_ROWS; ++row) {
		for (int col = 0; col < DIMENSION_COLUMNS - 1; ++col) {
			cout << this->cells[row][col];
		}
		cout << endl;
	}
}

bool Piece::canMoveLeft(const Grid & board) const
{
	return true;
}

void Piece::rotateRight()
{
	switch (this->type) {
	case I:
		for (int row = DIMENSION_ROWS - 1; row >= 0; --row) {
			for(int col =)
			}
		break;
	case J:
		memset(this->cells[0], '\0', 4);
		memset(this->cells[1], '\0', 4);
		this->cells[2][0] = '\0';
		memset(this->cells[2] + 1, '#',3);
		memset(this->cells[3], '\0', 3);
		this->cells[3][3] = '#';
		break;
	case L:
		memset(this->cells[0], '\0', 4);
		memset(this->cells[1], '\0', 4);
		memset(this->cells[2], '\0', 3);
		this->cells[2][3] = '#';
		this->cells[3][0] = 0;
		memset(this->cells[3]+1, '#', 3);
		
		break;
	}
}

void Piece::createPiece(const unsigned & indx)
{
	switch (indx)
	{
	case 1:
		this->type = I;
		for (int row = 0,col=0; row < DIMENSION_ROWS; ++row){
				this->cells[row][col] = '1';
		}
		break;
	case 2:
		this->type = J;
		for (int row = 0,col = 0; row < DIMENSION_ROWS-1; ++row) {
			if (row == 0) {
				this->cells[row][row+1] = '2';
			}
			this->cells[row][col] = '2';
		}
		break;
	case 3:
		this-> type = L;
		for (int row = 0,col = 1; row < DIMENSION_ROWS - 1; ++row) {
			if (row == 0) {
				this->cells[row][row] = '3';
			}
			this->cells[row][col] = '3';
		}
		break;
	case 4:
		this->type = O;
		for (int row = 0, col = 0; row < DIMENSION_ROWS - 2; ++row) {
			this->cells[row][col] = '4';
			this->cells[row][col+1] = '4';
		}
		break;
	case 5:
		this->type = S;
		for (int row = 0, col = 0; row < DIMENSION_ROWS - 2; ++row) {
			this->cells[row][col++] = '5';
			this->cells[col][row] = '5';
		}
		break;
	case 6:
		this->type = T;
		for (int row = 0, col = 0; row < DIMENSION_ROWS-1; ++row) {
			if (row == 1) {
				this->cells[row][col+1] = '6';
			}
			this->cells[row][col] = '6';
		}
		break;
	case 7:
		this->type = Z;
		for (int row = DIMENSION_ROWS - 2, col = 0; row >= 1; --row,++col) {
			this->cells[row][col] = '5';
			this->cells[row - 1][col] = '5';
		}
	}
}
