#include <iostream>

using namespace std;

int main() {
  // Defining the variable for use in the program
  int x;

  // Welcoming into the program
  cout << "Hello, this is the POTUS eligibility test.\nHow old are you? ";
  cin >> x;

  // Check eligibility
  if(x < 35){
    cout << "I'm sorry, you are too young to be POTUS. Please try again later.";
  }
  if(x >= 35){
    cout << "Hello Future POTUS. :)";
  }

  // Exit program
  return 0;
}