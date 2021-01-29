// Program to determine the distance between two points
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  // Definition of the variables
  double x1, y1, z1, x2, y2, z2, d;

  // Gathering of the points for use in the forumal
  cout << "Provide the first point with a space between values in (x,y,z) format: ";
  cin >> x1 >> y1 >> z1;
  cout << "Provide the second point with a space between values in (x,y,z) format: ";
  cin >> x2 >> y2 >> z2;

  // Calculating the distance between two points
  d=sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));

  // Presenting the results
  cout << "The distance between the points is " << d;
}