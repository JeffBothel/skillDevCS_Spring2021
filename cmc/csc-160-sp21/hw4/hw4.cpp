// Quadratic solver program that generates a number of statistics from the different quadtracit equations that are provided to the program
#include <iostream>
#include <string>
#include "QuadraticEquation.h"

int main()
{
    // Variables defined to run the program with
    int i, intMaxEquations;
    std::string strInput;
    QuadraticEquation equations[100];

    // Introducing the user to the program
    std::cout << "**Quadratic Equation Solutions Machine***\n";
    std::cout << "This program allows you to solve a number of quadratic equations at once\n";
    std::cout << "You can start entering your equations below, one at a time, with a maxmimum of 100 equations per program run\n";
    std::cout << "When you are done entering, just type \"done\" and the program will complete\n\n";

    // Gathering user input
    i = 0;
    do {
        std::cout << "f(x)[" << i << "]: A=";
        std::cin >> strInput;

        if (strInput == "done") {
            if (i == 0) return 0;
            else
            {
                intMaxEquations = i - 1;
                break;
            }
        }
        else equations[i].setValue(0, std::stod(strInput));

        std::cout << "f(x)[" << i << "]: B=";
        std::cin >> strInput;

        if (strInput == "done") {
            if (i == 0) return 0;
            else
            {
                intMaxEquations = i - 1;
                break;
            }
        }
        else equations[i].setValue(1, std::stod(strInput));

        std::cout << "f(x)[" << i << "]: C=";
        std::cin >> strInput;

        if (strInput == "done") {
            if (i == 0) return 0;
            else
            {
                intMaxEquations = i - 1;
                break;
            }
        }
        else equations[i].setValue(2, std::stod(strInput));

        std::cout << "f(x)[" << i << "]: Range minimum: ";
        std::cin >> strInput;

        if (strInput == "done") {
            if (i == 0) return 0;
            else
            {
                intMaxEquations = i - 1;
                break;
            }
        }
        else equations[i].setValue(3, std::stod(strInput));

        std::cout << "f(x)[" << i << "]: Range maximum: ";
        std::cin >> strInput;

        if (strInput == "done") {
            if (i == 0) return 0;
            else
            {
                intMaxEquations = i - 1;
                break;
            }
        }
        else equations[i].setValue(4, std::stod(strInput));

        std::cout << "f(x)[" << i << "]: Range increment: ";
        std::cin >> strInput;

        if (strInput == "done") {
            if (i == 0) return 0;
            else
            {
                intMaxEquations = i - 1;
                break;
            }
        }
        else equations[i].setValue(5, std::stod(strInput));

        i++;
    } while (i <= 99);

    // Outputting results to the screen for the user based on their input
    // Doing directly there as the operations looked for in this program are handled with functions of the QuadraticEquation class
    std::cout << "\n\nResults output:\n";

    for (i = 0; i <= intMaxEquations; i++) {
        // Displaying the equation
        std::cout << "f(x)[" << i << "]=" << equations[i].getValue(0) << "x^2";
        if (equations[i].getValue(1) < 0.0) std::cout << equations[i].getValue(1) << "x";
        else std::cout << "+" << equations[i].getValue(1) << "x";
        if (equations[i].getValue(2) < 0.0) std::cout << equations[i].getValue(2) << "\n";
        else std::cout << "+" << equations[i].getValue(2) << "\n";

        // Displaying stats on the equations
        std::cout << "Equation stats: min=(" << equations[i].getResultMin()[0] << "," << equations[i].getResultMin()[1] << "); max=(" << equations[i].getResultMax()[0] << "," << equations[i].getResultMax()[1] << "); ";
        std::cout << "Solutions=" << equations[i].getSolutions()[0];
        if (equations[i].getSolutions()[1] < 0.0) std::cout << equations[i].getSolutions()[1] << "i";
        else if (equations[i].getSolutions()[1] != 0.0) std::cout << "+" << equations[i].getSolutions()[1] << "i";
        std::cout << ", " << equations[i].getSolutions()[2];
        if (equations[i].getSolutions()[3] < 0.0) std::cout << equations[i].getSolutions()[3] << "i";
        else if (equations[i].getSolutions()[3] != 0.0) std::cout << "+" << equations[i].getSolutions()[3] << "i";
        
        std::cout << ";\n\n";
    }

    std::cout << "Thanks for using the program!\n";
    return 0;
}