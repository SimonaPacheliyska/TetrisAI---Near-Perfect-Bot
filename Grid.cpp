#include "Grid.h"
#include <cmath>

Grid::Grid()
{
	this->init();
}

Grid::~Grid()
{
	this->clear();
}

void Grid::print() const
{
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

void Grid::fillIn()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			if (j == 3 && i == 1 || j == 6 && i == 0) {
				continue;
			}
			grid[ROWS -i-1][j] = '#';
		}
	}
}

short Grid::columnHeight(short column) const
{
	short emptyCells = 0;
	short row = 0;

	for (; ROWS && this->grid[row][column] == 0; ++row, ++emptyCells);
	return ROWS - row;
}

void Grid::init()
{
	this->grid = new char*[ROWS];

	for (int row = 0; row < ROWS; ++row) {
		this->grid[row] = new char[COLUMNS] {0};
		for (int col = 0; col < COLUMNS; ++col) {
			this->grid[row][col] = ' ';
		}
	}
}

void Grid::clear()
{
	for (int i = 0; i < ROWS; ++i) {
		delete[] this->grid[i];
	}
}

unsigned aggregateHeight(const Grid & tetris)
{
	unsigned totalHeight = 0;

	for (int col = 0; col<COLUMNS; ++col) {
		for (int row = 0; row<ROWS; ++row) {
			if (tetris.grid[row][col] != ' ') {
				++totalHeight;
			}
		}
	}
	return totalHeight;
}

unsigned completeLines(const Grid & tetris)
{
	unsigned cmpLines = 0;
	bool isComplete = true;

	for (short row = 0; row < ROWS; ++row) {
		for (short col = 0; col < COLUMNS; ++col) {
			if (tetris.grid[row][col] == ' ') {
				isComplete = false;
				break;
			}
		}
		if (isComplete) {
			++cmpLines;
		}
		isComplete = true;
	}
	return cmpLines;
}

unsigned holes(const Grid & tetris)
{
	unsigned holesCnt = 0;
	bool isTopReached = true;

	for (int row = ROWS-1; row >= 0; --row) {
		for (int col = 0; col < COLUMNS; ++col) {
			if (tetris.grid[row][col] == ' ') {
				++holesCnt;
			}
			else {
				isTopReached = false;
			}
		}
		if (isTopReached) {
			return holesCnt - 10; // subtracts the elements, which were wrong counted 
								  // (the first line without elements from bottom to top) 
		}
		isTopReached = true;
	}
	return holesCnt;
}

unsigned bumpiness(const Grid & tetris)
{
	unsigned bumpiness = 0;
	int helper = 0;

	for (int col = 0; col < COLUMNS-1; ++col) {
		helper = tetris.columnHeight(col) - tetris.columnHeight(col + 1);
		bumpiness += abs(helper);
	}
	return bumpiness;
}
