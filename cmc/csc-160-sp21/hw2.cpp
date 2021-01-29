// This program gathers the information necessary to find x with teh quadratic formula
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
  // Definition of the variables for use
  int aIn, bIn, cIn;
  double xPos, xNeg;
  string quadOut;

  // Gather the variables for use in the program
  cout << "Quadratic Formual Solver\n";
  cout << "A value: ";
  cin >> aIn;
  cout << "B value: ";
  cin >> bIn;
  cout << "C value: ";
  cin >> cIn;
  cout << "\n";

  // Generating of the different solutions for X
  xPos = (-1.0*(double)bIn+sqrt(pow((double)bIn,2)-4*(double)aIn*(double)cIn))/(2*(double)aIn);
  xNeg = (-1.0*(double)bIn-sqrt(pow((double)bIn,2)-4*(double)aIn*(double)cIn))/(2*(double)aIn);

  // Generating the output of the quadratic formula display
  quadOut = (to_string(aIn) + "x^2");
  if(bIn < 0) quadOut += (to_string(bIn) + "x");
  else quadOut += ("+" + to_string(bIn) + "x");
  if(cIn < 0) quadOut += to_string(cIn);
  else quadOut += ("+" + to_string(cIn));

  // Output of the information to the screen
  cout << "Formula: " << quadOut << "\n";
  cout << "X=" << xPos << "," << xNeg << "\n";
}