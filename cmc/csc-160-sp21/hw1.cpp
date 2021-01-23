#include <iostream>

using namespace std;

int main () {
  // Decleration of the variables for the program
  double dbl_num1, dbl_num2, dbl_num3, dbl_num4;
  string str_noun1, str_noun2, str_verb1, str_verb2, str_assembled;

  // Welcoming users to the porgram
  cout << "Hello and welcome to the progam.\n";
  
  // Collection of the nouns
  cout << "Please enter a noun: ";
  cin >> str_noun1;
  cout << "Please enter another noun: ";
  cin >> str_noun2;

  // Collection of the verbs
  cout << "Please enter a verb: ";
  cin >> str_verb1;
  cout << "Please enter another verb: ";
  cin >> str_verb2;

  // Colleciton of the numbers
  cout << "Please enter a set of 4 numbers, each separated by a space: ";
  cin >> dbl_num1 >> dbl_num2 >> dbl_num3 >> dbl_num4;

  // Assembly of the collected items into the story
  str_assembled = "The day was a balmy " + to_string(dbl_num1) + " day in " + str_noun1 + ".\n";
  str_assembled += "There were " + str_noun2 + " everywhere, doing " + str_verb2 + ".\n";
  str_assembled += "Patrick had the great idea to " + str_verb1 + " while eating " + to_string(dbl_num2 * dbl_num3) + " pounds of cheese cake.\n";
  str_assembled += "Then Jerry " + str_verb1 + " into Patrick's cake and had to pay him " + to_string(dbl_num4 + dbl_num4) + " to replace it.";

  // Display of the assembled story
  cout << str_assembled << endl;
  cout << "Thanks for playing!";
}