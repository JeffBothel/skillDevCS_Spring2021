// Grade calculator with letter assignment
#include <iostream>

using namespace std;

int main() {
  // Definition of the variables necessary in the program
  int earnedPoints, totalPoints;
  double gradePercent;
  string letterGrade;

  // Gather the necessary information
  cout << "Grade calculator and letter assignment\n";
  cout << "How many points are there total in your course? ";
  cin >> totalPoints;
  cout << "How many points have you earned? ";
  cin >> earnedPoints;
  cout << "\n\n";

  // Performing the calculations
  gradePercent = ((double)earnedPoints/(double)totalPoints)*100.0;

  // Generating letter grade
  if(gradePercent >= 93.0){
    letterGrade = "A";
  }
  else if(gradePercent >= 90.0 && gradePercent < 93.0){
    letterGrade = "A-";
  }
  else if(gradePercent >= 87.0 && gradePercent < 90.0){
    letterGrade = "B+";
  }
  else if(gradePercent >= 83.0 && gradePercent < 87.0){
    letterGrade = "B";
  }
  else if(gradePercent >= 80.0 && gradePercent < 83.0){
    letterGrade = "B-";
  }
  else if(gradePercent >= 77.0 && gradePercent < 80.0){
    letterGrade = "C+";
  }
  else if(gradePercent >= 73.0 && gradePercent < 77.0){
    letterGrade = "C";
  }
  else if(gradePercent >= 70.0 && gradePercent < 73.0){
    letterGrade = "C-";
  }
  else if(gradePercent >= 67.0 && gradePercent < 70.0){
    letterGrade = "D+";
  }
  else if(gradePercent >= 63.0 && gradePercent < 67.0){
    letterGrade = "D";
  }
  else if(gradePercent >= 60.0 && gradePercent < 63.0){
    letterGrade = "D-";
  }
  else {
    letterGrade = "F";
  }

  // Output of information
  // cout << earnedPoints << " " << totalPoints << "\n";  // Used for diagnostics of the program
  cout << "Your percentage in the class:" << gradePercent << "\n";
  cout << "Your letter grade in the class:" << letterGrade << "\n";
}