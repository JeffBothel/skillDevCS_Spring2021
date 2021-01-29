// For creating a program that outputs the resutls of the pythagorean theorem
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  // Definition of the variables that are utilized for the formula
  double a, b, c;
  
  // Gathering user input
  cout << "Enter length A: ";
  cin >> a;
  cout << "Enter length B: ";
  cin >> b;

  // Coputing the value of C and output
  c = sqrt(pow(a,2) + pow(b,2));
  cout << "The Hypotenus is " << c;
}