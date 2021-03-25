#include <iostream>
#include <fstream>
#include <string>

int main() {
	// Decleration of the variables for the program
	int i = 0, int_fileLineCount = 0, int_swapCount = 0;
	double* dbl_fileInNumbers;
	std::string str_lineForInput, str_fileInName, str_fileOutName;
	std::ifstream strm_inputFile;
	std::ofstream strm_outputFile, strm_logFile;

	// Greeting users to the program
	std::cout << "#### Mass Number Sorter ####\nThis program takes an input list of line separated numbers, sorts them, and outputs them to a file.\n\n";

	// Starting the logging of the program
	strm_logFile.open("logs.txt", std::ios::app);
	strm_logFile << "Begin program run.\n";

	// Gathering user input for what files to use
	std::cout << "Enter the file name for input: ";
	std::cin >> str_fileInName;
	std::cout << "Enter the file name for output: ";
	std::cin >> str_fileOutName;

	strm_logFile << "Input file name = " << str_fileInName << "\n";
	strm_logFile << "Output file name = " << str_fileOutName << "\n";

	// Counting the lines in the file
	strm_inputFile.open(str_fileInName);
	while (!strm_inputFile.eof())
	{
		std::getline(strm_inputFile, str_lineForInput);
		int_fileLineCount++;
	}
	strm_logFile << "File has " << int_fileLineCount << "lines\n";
	strm_inputFile.close();
	strm_inputFile.open(str_fileInName);

	// Gatheirng the lines from the file and turning them into doubles
	dbl_fileInNumbers = new double[int_fileLineCount];
	while (i <= (int_fileLineCount - 1))
	{
		std::getline(strm_inputFile, str_lineForInput);
		dbl_fileInNumbers[i] = std::stod(str_lineForInput);
		strm_logFile << "Writing line " << i << " to array successful (" << dbl_fileInNumbers[i] << ")\n";
		i++;
	}
	strm_inputFile.close();

	// Sorting of the lines to get a listing smallest to greatest in the array
	i = (int_fileLineCount - 1);
	do {
		if (dbl_fileInNumbers[i - 1] > dbl_fileInNumbers[i])
		{
			strm_logFile << "dbl_fileInNumbers[" << (i - 1) << "]=" << dbl_fileInNumbers[i - 1] << " > dbl_fileInNumbers[" << i << "]=" << dbl_fileInNumbers[i] << "\n";
			std::swap(dbl_fileInNumbers[i - 1], dbl_fileInNumbers[i]);
			int_swapCount++;
			i = (int_fileLineCount - 1);
		}
		else i--;
	} while (i >= 0);
	strm_logFile << "Sorting complete after " << int_swapCount << " swaps performed\n";
	for (i = 0; i <= (int_fileLineCount - 1); i++) strm_logFile << "dbl_fileLineCount[" << i << "]=" << dbl_fileInNumbers[i] << "\n";

	// Output the numbers to file
	strm_outputFile.open(str_fileOutName, std::ios::out);
	for (i = 0; i <= (int_fileLineCount - 1); i++) strm_outputFile << dbl_fileInNumbers[i] << "\n";
	strm_outputFile.close();
	strm_logFile << "Numbers output to logs file successfully\n";

	// Give the users the final run information
	std::cout << "Sorting and output of the numbers to " << str_fileOutName << " complete.\n";
	std::cout << int_swapCount << " swaps were performed.\n";

	// Close out program and logging
	strm_logFile << "End of program execution.\n";
	strm_logFile.close();
	return 0;
}