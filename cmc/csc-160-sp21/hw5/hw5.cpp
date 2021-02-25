// To work up the algorithm for this program, I used http://oregonstate.edu/instruct/mth251/cq/Stage4/Lesson/bisection.html as a reference for the method
#include <iostream>
#include <string>
#include <math.h>

// Putting the equation into a function to allow it to operate effectively
double Equation(double dbl_valueX)
{
	double dbl_valueY = pow(dbl_valueX, 3.0) - ((double)3.0 * dbl_valueX) - (double)4.0;
	return dbl_valueY;
}

bool SignNegative(double dbl_value)
{
	bool bin_return;
	
	if (dbl_value < 0) bin_return = true;
	else bin_return = false;

	return bin_return;
}

int main()
{
	// Variable declerations
	int int_iterations;
	double dbl_valueL[2], dbl_valueR[2], dbl_valueM[2], dbl_tolerance;
	std::string str_input;

	// Gretting users to the program
	std::cout << "<<< Bisection Method Root Solving Calculator for f(x)=x^3-3x-4 >>>\n";
	std::cout << "Enter the interval to look at and bisection with, as well the level of confidence for that solution.\n\n";

	// Loop for gathering the interval from the user
	do
	{
		// Gather the left bound for the interval
		std::cout << "Enter the left bound: ";
		std::cin >> str_input;
		dbl_valueL[0] = std::stod(str_input);
		dbl_valueL[1] = Equation(dbl_valueL[0]);

		// Gather the right bound for the interval
		std::cout << "Enter the right bound: ";
		std::cin >> str_input;
		dbl_valueR[0] = std::stod(str_input);
		dbl_valueR[1] = Equation(dbl_valueR[0]);

		// Determining if the left of the bounds is a root
		if (dbl_valueL[1] == 0) 
		{
			std::cout << "\n\nRoot for the equation found at f(" << dbl_valueL[0] << ")=" << dbl_valueL[1] << "; no iterations needed.";
			return 0;
		}

		// Determining if the left of the bounds is a root
		if (dbl_valueR[1] == 0) 
		{
			std::cout << "\n\nRoot for the equation found at f(" << dbl_valueR[0] << ")=" << dbl_valueR[1] << "; no iterations needed.";
			return 0;
		}

		// Ensure the inputs are effective for the analysis
		if (SignNegative(dbl_valueL[1]) == SignNegative(dbl_valueR[1]))
		{
			std::cout << "Invalid interval. Please enter a new interval.\n";
			continue;
		}

		break;

	} while (true);

	// Loop for gathering the tolerance from the user
	do
	{
		std::cout << "Enter the right bound: ";
		std::cin >> str_input;
		dbl_tolerance = std::stod(str_input);

		// Evaluate if a relevant tolerance
		if (abs(dbl_tolerance) > (double)1.0)
		{
			std::cout << "Invalid tolerance. Please enter a new tolerance.\n";
			continue;
		}

		break;
	} while (true);

	// Loop for performing the bisections to the root
	int_iterations = 0;
	do
	{
		// Count the iterations that the program runs
		int_iterations++;

		// Find the values for midpoint of the interval
		dbl_valueM[0] = (dbl_valueL[0] + dbl_valueR[0]) / (double)2.0; 
		dbl_valueM[1] = Equation(dbl_valueM[0]);

		// If a root at the midpoint
		if (dbl_valueM[1] == 0) break;

		// If the result of the equation is on the positive side of the X-axis still and if so bring the left bound closer to the X-axis
		if (dbl_valueM[1] < 0) {
			dbl_valueL[0] = dbl_valueM[0];
			dbl_valueL[1] = Equation(dbl_valueL[0]);
		}

		// If the result of the equation is on the negative side of the X-axis still and if so bring the right bound closer to the X-axis
		if (dbl_valueM[1] > 0) {
			dbl_valueR[0] = dbl_valueM[0];
			dbl_valueR[1] = Equation(dbl_valueR[0]);
		}

	} while (std::abs(dbl_valueR[0] - dbl_valueL[0]) > dbl_tolerance);

	// Output the result information to the user
	std::cout << "\n\nRoot for the equation found at f(" << dbl_valueM[0] << ")=" << dbl_valueM[1] << "; found after " << int_iterations << " for a iterations.\n\n\n";
	return 0;
}