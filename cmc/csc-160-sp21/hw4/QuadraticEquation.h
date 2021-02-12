#pragma once

class QuadraticEquation
{
// Constructors and deconstructors that are used with the class
public:
	QuadraticEquation();													// Default constructor of the class
	QuadraticEquation(double, double, double);								// Constructor that takes only the equation components to the object
	QuadraticEquation(double, double, double, double, double, double);		// Constructor that takes in all the major inputs for the class object
	~QuadraticEquation();													// Default deconstructor of the class

// Functions that are used with the class
public:
	void setValue(int, double);						// Sets individual values of the equation within the class
	void setEquation(double, double, double);		// Sets the values for A, B, and C within the quadratic all at once
	void setRange(double, double, double);			// Sets the range and incrementation used for that range in the object
	double getValue(int);							// Retrieves a value, given by the int code, for the equation
	double getResult(double);						// Retrieves an f(x) result from the equation
	double * getEquationValues();					// Retrieves the values for A, B, and C from the equation in an array where 0=A, 1=B, and 2=C
	double * getRangeValues();						// Retrieves the values that are stored for the range in an array where 0=range minimum, 1=range maximum, 2=range increment
	double * getSolutions();							// Retrieves solutions for the equation in an array where 0=negative real component, 1=negative imaginary compoonent, 2=positive real component, 3=positive imaginary compoonent
	double * getResultMin();							// Gets the minimum point of the equation in the array form 0=X and 1=Y
	double * getResultMax();							// Gets the maximum point of the equation in the array form 0=X and 1=Y

private:
	double valueA;									// A value for the equation in the form of ax^2+bx+c
	double valueB;									// B value for the equation in the form of ax^2+bx+c
	double valueC;									// C value for the equation in the form of ax^2+bx+c
	double rangeMin;								// minimum range value that is used for the equation
	double rangeMax;								// maximum range value that is used for the equation
	double rangeInc;								// increments of the range that are used
};