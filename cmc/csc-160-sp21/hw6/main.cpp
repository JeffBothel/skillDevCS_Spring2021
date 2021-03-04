#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <regex>

// Main entry point for the program
int main()
{
	// Decleration of the variables for the program
	int int_lineCount, i;
	double* dbl_fileValues;
	double dbl_average = 0, dbl_standardDeviation = 0, dbl_standardDeviationSum = 0;
	std::fstream fstrm_inputFile;
	std::ofstream fstrm_logFile, fstrm_outFile;
	std::string str_inputLine;

	// Setting the file to reference
	fstrm_inputFile.open("inputFile.txt",std::ios::in);
	fstrm_logFile.open("logFile.txt", std::ios::app);

	// Getting the count of lines from the file
	int_lineCount = 0;
	do
	{
		std::getline(fstrm_inputFile, str_inputLine);
		if (std::regex_match(str_inputLine, std::regex("(Average: )(.*)"))) break;
		if (std::regex_match(str_inputLine, std::regex("(Standard Deviation: )(.*)"))) break;
		int_lineCount++;
	} while (!fstrm_inputFile.eof());
	str_inputLine = "";

	// Defining the array to use for the data that is present in the file
	dbl_fileValues = new double[int_lineCount];

	// Reopening the file to input the values into the array
	fstrm_inputFile.close();
	fstrm_inputFile.open("inputFile.txt",std::ios::in);

	// Putting the file values to the array for handling
	i = 0;
	do
	{
		std::getline(fstrm_inputFile, str_inputLine);
		if (std::regex_match(str_inputLine, std::regex("(Average: )(.*)"))) break;
		if (std::regex_match(str_inputLine, std::regex("(Standard Deviation: )(.*)"))) break;
		dbl_fileValues[i] = std::stod(str_inputLine);
		i++;

	} while (i <= (int_lineCount - 1));
	
	// Calculating the average of the values
	for (i = 0; i <= (int_lineCount - 1); i++) dbl_average += dbl_fileValues[i];
	dbl_average /= (double)int_lineCount;

	// Calculating standard deviation
	for (i = 0; i <= (int_lineCount - 1); i++)dbl_standardDeviationSum += std::pow(dbl_fileValues[i] - dbl_average, 2.0);
	dbl_standardDeviation = std::sqrt(dbl_standardDeviationSum / int_lineCount);

	// Writing the Average and Standard Deviation to the file
	fstrm_outFile.open("inputFile.txt", std::ios::app);
	fstrm_outFile << "\nAverage: " << std::to_string(dbl_average);
	fstrm_outFile << "\nStandard Deviation: " << std::to_string(dbl_standardDeviation);
	fstrm_logFile << "Average: " << std::to_string(dbl_average) << "\n";
	fstrm_logFile << "Standard Deviation: " << std::to_string(dbl_standardDeviation) << "\n";
	fstrm_outFile.close();

	// Presenting the resutls on-screen
	std::cout << "Values in File: " << int_lineCount << "\n";
	std::cout << "Average: " << dbl_average << "\n";
	std::cout << "Standard Deviation: " << dbl_standardDeviation << "\n";
	
	// Closing out the program
	fstrm_logFile.close();
	return 0;
}