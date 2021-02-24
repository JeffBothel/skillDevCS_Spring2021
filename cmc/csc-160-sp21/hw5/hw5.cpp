// To wokr up the algorithm for this program, I used http://oregonstate.edu/instruct/mth251/cq/Stage4/Lesson/bisection.html as a reference for the method
#include <iostream>
#include <string>
#include <math.h>

// Since I am going to be using the equation over and over again in the application, defining its output as a function to call over and over again simply
double Equation(double dbl_valueX)
{
	// Calculates the equation and 
	double dbl_valueY = std::pow(dbl_valueX, 3.0) - ((double)3.0 * dbl_valueX) - (double)4.0;

	return dbl_valueY;
}

int main()
{
	// Variable decleration for the application
	int int_iterations = 0;
	double dbl_pointA[2], dbl_pointB[2], dbl_pointM[2], dbl_tolerance, dbl_testing;				// Points I am using [0]=X and [1]=Y for the pairs
	std::string str_input;

	// Welcoming the user to the program and giving usage information
	std::cout << "Bisection Method Equation Calculator\n";
	std::cout << "Value A should be less than 0 and value B should be greater than 0.\n\n";

	// Loop to gather valid user input for the bounds
	do {
		// Gather point A
		std::cout << "Enter the value for A (the left bound): ";
		std::cin >> str_input;
		dbl_pointA[0] = std::stod(str_input);

		// Gather point B
		std::cout << "Enter the value for B (the right bound): ";
		std::cin >> str_input;
		dbl_pointB[0] = std::stod(str_input);

		// Ensuring the bounds are appropriate
		if (dbl_pointA[0] > dbl_pointB[0] || dbl_pointA[0] > 0 || dbl_pointB[0] < 0) {
			std::cout << "Invalid bounds. Please try again.\n";
			continue;
		}

		// Ensuring that one of the bounds is not a root
		if (Equation(dbl_pointA[0]) == 0) {
			std::cout << "Bound A being f(" << dbl_pointA[0] << ")=0, this is a root and no iterations are needed.";
			return 0;
		}

		if (Equation(dbl_pointB[0]) == 0) {
			std::cout << "Bound B being f(" << dbl_pointB[0] << ")=0, this is a root and no iterations are needed.";
			return 0;
		}

		// Exiting the loop as acceptable user input bas been received
		break;
	} while (true);

	// Loop to gather valid user input for the tolerance
	do {
		std::cout << "Enter the error tolerance for the solutions: ";
		std::cin >> str_input;
		dbl_tolerance = std::stod(str_input);

		// Ensure the input is valid
		if (dbl_tolerance < 0) {
			std::cout << "Invalid tolerance. Please try again.";
			continue;
		}

		break;
	} while (true);

	// Setting the bounds points for initial values to be used before entering the iterations loop
	dbl_pointA[1] = Equation(dbl_pointA[0]);
	dbl_pointB[1] = Equation(dbl_pointB[0]);

	// Looping until the distance between the points A and B is less than the tolerance
	do {
		int_iterations++;

		// Setting the midpoint for this iteration
		dbl_pointM[0] = ((dbl_pointA[0] + dbl_pointB[0]) / (double)2.0);
		dbl_pointM[1] = Equation(dbl_pointM[0]);

		// Checking if we have a root
		if (dbl_pointM[1] == 0) break;

		dbl_testing = (dbl_pointA[0] + dbl_pointB[0]) / (double)2.0;

		// Checking where to reduce the possible errors
		if (dbl_pointM[1] < 0) {
			dbl_pointA[0] = dbl_pointM[0];
			dbl_pointA[1] = Equation(dbl_pointA[0]);
		}

		if (dbl_pointM[1] > 0) {
			dbl_pointB[0] = dbl_pointM[0];
			dbl_pointB[1] = Equation(dbl_pointB[0]);
		}
		
		// Checking if final loop, and if so set the A value to M for output without at arriving at a true root
		if (abs((dbl_pointA[0] + dbl_pointB[0]) / (double)2.0) < dbl_tolerance) {
			dbl_pointM[0] = dbl_pointA[0];
			dbl_pointM[1] = Equation(dbl_pointM[1]);
		}

	} while (abs((dbl_pointA[0] + dbl_pointB[0]) / (double)2.0) < dbl_tolerance);

	std::cout << "\nFound a root at f(" << dbl_pointM[0] << ")=0 after " << int_iterations << ".\n";

	// Final termination of the program
	return 0;
}