#pragma once
#include <iostream>

using std::cout;
using std::endl;

const short ROWS = 20;
const short COLUMNS = 10;

class Grid
{
private:
	char** grid;

	Grid(const Grid&) = delete;
	Grid& operator=(const Grid&) = delete;
public:
	Grid();
	~Grid();

	void print()const;

	//heuristics
	friend unsigned aggregateHeight(const Grid&);
	friend unsigned completeLines(const Grid&);
	friend unsigned holes(const Grid&);
	friend unsigned bumpiness(const Grid&);


	void fillIn();
	short columnHeight(short column)const;

private:
	void init();
	void clear();
};