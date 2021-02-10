// Quadrattic equation solver mini program
#include <iostream>
#include <complex>

// Setting the default namespace for the program to standard to allow for easier function and type utilization
using namespace std;

int main() {
	// Definition of the variables for use in the program
	int i, intMaxValues;																		// Variables for iteration through loops
	float fltEqValues[100][7];																	// Multi-dimensional array that stores all the permanent values for the equations entered and their results
																								// 0=A, 1=B, 2=C, 3=Solution 1 Real, 4=Solution 1 Imaginary, 5=Solution 2 Real, 6=Solution 2 Imaginary
	complex<float> cmplxFlt_aValue, cmplxFlt_bValue, cmplxFlt_cValue, cmplxFlt_tempResult;		// Variables to perform the calculations for the equation with and then have outputs capable of going back to the array
	string strInput;

	// Introducing the user to the program
	cout << "Quadratic Equation Mass Solver\n";
	cout << "Enter each equation, one at a time, with the values entered one at a time per line.\n\n";

	// Gathering the user input on the equations to solve
	i = 0;
	while (true) {
		if (i == 100) break;						// Break if the rotation is going to exceed the max equations count

		cout << "f[" << i << "](x): A=";			// Gathering of the information from the user
		cin >> strInput;

		if (strInput == "done") {					// Confirming that the loop is not terminating, but if it is, terminating it early appropriately
			intMaxValues = i - 1;
			break;
		}

		if (strInput == "") strInput = "0";			// Setting the string to 0 if there is nothing entered

		fltEqValues[i][0] = stof(strInput);			// Setting the value from the string to the appropriate repository of variables

		cout << "f[" << i << "](x): B=";			// Gathering of the information from the user
		cin >> strInput;

		if (strInput == "done") {					// Confirming that the loop is not terminating, but if it is, terminating it early appropriately
			intMaxValues = i - 1;
			break;
		}

		if (strInput == "") strInput = "0";			// Setting the string to 0 if there is nothing entered

		fltEqValues[i][1] = stof(strInput);			// Setting the value from the string to the appropriate repository of variables

		cout << "f[" << i << "](x): C=";			// Gathering of the information from the user
		cin >> strInput;

		if (strInput == "done") {					// Confirming that the loop is not terminating, but if it is, terminating it early appropriately
			intMaxValues = i - 1;
			break;
		}

		if (strInput == "") strInput = "0";			// Setting the string to 0 if there is nothing entered

		fltEqValues[i][2] = stof(strInput);			// Setting the value from the string to the appropriate repository of variables

		i++;										// Incrementing of the equation lines in the program
	}

	// Performing the calculation to determine the solutions to the equation, with and without real numbers
	for (i = 0; i <= intMaxValues; i++) {
		cmplxFlt_aValue = fltEqValues[i][0];		// Setting the A value from the main storage array to the A complex value to perform the calculation
		cmplxFlt_bValue = fltEqValues[i][1];		// Setting the B value from the main storage array to the B complex value to perform the calculation
		cmplxFlt_cValue = fltEqValues[i][2];		// Setting the C value from the main storage array to the C complex value to perform the calculation

		cmplxFlt_tempResult = ((complex<float>) - 1.0 * cmplxFlt_bValue + sqrt((complex<float>)pow(cmplxFlt_bValue, 2.0) - (complex<float>)4.0 * cmplxFlt_aValue * cmplxFlt_cValue)) / ((complex<float>)2.0 * cmplxFlt_aValue);
		fltEqValues[i][3] = real(cmplxFlt_tempResult);
		fltEqValues[i][4] = imag(cmplxFlt_tempResult);

		cmplxFlt_tempResult = ((complex<float>) - 1.0 * cmplxFlt_bValue - sqrt((complex<float>)pow(cmplxFlt_bValue, 2.0) - (complex<float>)4.0 * cmplxFlt_aValue * cmplxFlt_cValue)) / ((complex<float>)2.0 * cmplxFlt_aValue);
		fltEqValues[i][5] = real(cmplxFlt_tempResult);
		fltEqValues[i][6] = imag(cmplxFlt_tempResult);
	}

	// Outputting the results and formulas to the screen
	cout << "\n***Equation Results***\n";

	for (i = 0; i <= intMaxValues; i++) {
		cout << "f[" << i << "](x): " << fltEqValues[i][0] << "x^2";						// Outputs the A component of the equation

		if (fltEqValues[i][1] < 0) cout << fltEqValues[i][1] << "x";						// Outputs the B component of the equation
		else if (fltEqValues[i][1] > 0) cout << "+" << fltEqValues[i][1] << "x";

		if (fltEqValues[i][2] < 0) cout << fltEqValues[i][2];								// Outputs the C component of the equation
		else if (fltEqValues[i][2] > 0) cout << "+" << fltEqValues[i][2];

		cout << "=0; ";																		// Outputs the sum component of the equation

		if (fltEqValues[i][4] != 0) {														// Determines if there is an imaginary solution
			cout << fltEqValues[i][3];														// Outputs the real number component of the imaginary solution
			if (fltEqValues[i][4] < 0) cout << fltEqValues[i][4] << "i";					// Outputs the imaginary number component of the imaginary solution
			else cout << "+" << fltEqValues[i][4] << "i";
		}
		else cout << fltEqValues[i][3];														// Outputs the numebr if it is real

		cout << ", ";																		// Separates the solutions to the equation
		
		if (fltEqValues[i][4] != 0) {														// Determines if there is an imaginary solution
			cout << fltEqValues[i][5];														// Outputs the real number component of the imaginary solution
			if (fltEqValues[i][6] < 0) cout << fltEqValues[i][6] << "i";					// Outputs the imaginary number component of the imaginary solution
			else cout << "+" << fltEqValues[i][6] << "i";
		}
		else cout << fltEqValues[i][5];														// Outputs the numebr if it is real

		cout << "\n";

		// cout << "[0]=" << fltEqValues[i][0] << ",[1]=" << fltEqValues[i][1] << ",[2]=" << fltEqValues[i][2] << ",[3]=" << fltEqValues[i][3] << ",[4]=" << fltEqValues[i][4] << ",[5]=" << fltEqValues[i][5] << ",[6]=" << fltEqValues[i][6] << "\n";		// Diagnostic line to see values from the equation outputs
	}
}