#include "QuadraticEquation.h"
#include <complex>
#include <math.h>


// Default constructror of the class
QuadraticEquation::QuadraticEquation()
{
	valueA = 0.0;
	valueB = 0.0;
	valueC = 0.0;
	rangeMin = 0.0;
	rangeMax = 0.0;
	rangeInc = 0.0;
}

// Constructor that takes only the equation components to the object
QuadraticEquation::QuadraticEquation(double inA, double inB, double inC)
{
	valueA = inA;
	valueB = inB;
	valueC = inC;
	rangeMin = 0.0;
	rangeMax = 0.0;
	rangeInc = 0.0;
}


// Constructor that takes in all the major inputs for the class object
QuadraticEquation::QuadraticEquation(double inA, double inB, double inC, double inMin, double inMax, double inInc)
{
	valueA = inA;
	valueB = inB;
	valueC = inC;
	rangeMin = inMin;
	rangeMax = inMax;
	rangeInc = inInc;
}

// Default deconstructor of the class
QuadraticEquation::~QuadraticEquation()
{
}

// Sets individual values of the equation within the class
void QuadraticEquation::setValue(int valueCode, double inValue)
{
	switch (valueCode) {
	case 0:
		valueA = inValue;
		break;
	case 1:
		valueB = inValue;
		break;
	case 2:
		valueC = inValue;
		break;
	case 3:
		rangeMin = inValue;
		break;
	case 4:
		rangeMax = inValue;
		break;
	case 5:
		rangeInc = inValue;
		break;
	}
}

// Sets the values for A, B, and C within the quadratic all at once
void QuadraticEquation::setEquation(double inA, double inB, double inC)
{
	valueA = inA;
	valueB = inB;
	valueC = inC;
}

// Sets the range and incrementation used for that range in the object
void QuadraticEquation::setRange(double inMin, double inMax, double inInc)
{
	rangeMin = inMin;
	rangeMax = inMax;
	rangeInc = inInc;
}

// Retrieves a value, given by the int code, for the equation
double QuadraticEquation::getValue(int valueCode)
{
	double result = 0.0;

	switch (valueCode) {
	case 0:
		result = valueA;
		break;
	case 1:
		result = valueB;
		break;
	case 2:
		result = valueC;
		break;
	case 3:
		result = rangeMin;
		break;
	case 4:
		result = rangeMax;
		break;
	case 5:
		result = rangeInc;
		break;
	}

	return result;
}

// Retrieves an f(x) result from the equation
double QuadraticEquation::getResult(double x)
{
	double result;

	result = valueA * pow(x, 2) + valueB * x + valueC;

	return result;
}

// Retrieves the values for A, B, and C from the equation in an array where 0=A, 1=B, and 2=C
double * QuadraticEquation::getEquationValues()
{
	double result[3];

	result[0] = valueA;
	result[1] = valueB;
	result[2] = valueC;

	return result;
}

// Retrieves the values that are stored for the range in an array where 0=range minimum, 1=range maximum, 2=range increment
double * QuadraticEquation::getRangeValues()
{
	double result[3];

	result[0] = rangeMin;
	result[1] = rangeMax;
	result[2] = rangeInc;

	return result;
}

// Retrieves solutions for the equation in an array where 0=negative real component, 1=negative imaginary compoonent, 2=positive real component, 3=positive imaginary compoonent
double * QuadraticEquation::getSolutions()
{
	double result[4];
	std::complex<double> eqA = valueA;
	std::complex<double> eqB = valueB;
	std::complex<double> eqC = valueC;
	std::complex<double> fxPos, fxNeg;

	fxNeg = (-eqB - std::sqrt(pow(eqB, 2.0) - 4.0 * eqA * eqC)) / (2.0 * eqA);
	fxPos = (-eqB + std::sqrt(pow(eqB, 2.0) - 4.0 * eqA * eqC)) / (2.0 * eqA);

	result[0] = std::real(fxNeg);
	result[1] = std::imag(fxNeg);
	result[2] = std::real(fxPos);
	result[3] = std::imag(fxPos);

	return result;
}

// Gets the minimum point of the equation in the array form 0=X and 1=Y
double * QuadraticEquation::getResultMin()
{
	double result[2];
	double x, fx;

	result[0] = rangeMin;
	result[1] = valueA * pow(rangeMin, 2) + valueB * rangeMin + valueC;

	for (x = rangeMin; x <= rangeMax; x += rangeInc)
	{
		fx = valueA * pow(x, 2) + valueB * x + valueC;
		if (fx < result[1]) {
			result[0] = x;
			result[1] = fx;
		}
	}

	return result;
}

// Gets the maximum point of the equation in the array form 0=X and 1=Y
double * QuadraticEquation::getResultMax()
{
	double result[2];
	double x, fx;

	result[0] = rangeMin;
	result[1] = valueA * pow(rangeMin, 2) + valueB * rangeMin + valueC;

	for (x = rangeMin; x <= rangeMax; x += rangeInc)
	{
		fx = valueA * pow(x, 2) + valueB * x + valueC;
		if (fx > result[1]) {
			result[0] = x;
			result[1] = fx;
		}
	}

	return result;
}
