// Demo of the different between successive if and conjoined if

#include <iostream>

using namespace std;

int main() {
  // Definition of the variable
  int vari = 5;
  int variOut1, variOut2;

  // Separate if statements
  variOut1 = vari;
  if(vari > 0 && vari < 10){
    variOut1 += 1;
  }
  if(vari > 3 && vari < 8){
    variOut1 += 1;
  }
  if(vari > 4 && vari < 6){
    variOut1 += 1;
  }

  // Conjoined if statements
  variOut2 = vari;
  if(vari > 0 && vari < 10){
    variOut2 += 1;
  }
  else if(vari > 3 && vari < 8){
    variOut2 += 1;
  }
  else if(vari > 4 && vari < 6){
    variOut2 += 1;
  }

  // Output the results
  cout << "vari=" << vari << "\n" << "variOut1=" << variOut1 << "\n" << "variOut2=" << variOut2;

  // Exit program
  return 0;
}