#include <iostream>
#include <math.h>

using namespace std;

int main() {
  // Holds the number collected from the user
  double number;
  
  // Gathering input
  cout << "Enter number: ";
  cin >> number;

  // Computation and output
  cout << number << " squared is " << pow(number,2) << "\n";
  cout << "Square root of " << number << " is " << sqrt(number) << "\n";
  
  return 0;
}