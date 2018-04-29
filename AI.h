#pragma once

// optimal set of parameters
const double a = -0.510066; // aggregateHeight
const double b = 0.760666; // completeLines
const double c = -0.35663; // holes
const double d = -0.184483; //bumpiness
//

class AI {
private:
	double heightWeight;
	double linesWeight;
	double holesWeight;
	double bumpinessWeight;

public:
	AI(const double& heightWeight, const double& linesWeight, 
			const double& holesWeight, const double& bumpinessWeight);



};