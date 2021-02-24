#include <iostream>
#include <string>

using namespace std;

int main() {
	int i, vals[100], max[2] = { 0,0 }, total, sum = 0, avg = 0;
	string input;

	cout << "Maximum Number Finder\n\n";

	// Gather user input
	for (i = 0; i <= 99; i++) {
		cout << "f(" << i << ")=";
		cin >> input;

		// Address if the user types the end sequence
		if (input == "end") {
			total--;
			break;
		}

		// Determine if what was input was the max value
		if (stoi(input) > max[1]) {
			max[0] = i;
			max[1] = stoi(input);
		}
		vals[i] = stoi(input);
		total = i;
	}

	// Gatheirng avearage
	for (i = 0; i <= total; i++) {
		sum += vals[i];
	}
	avg = sum / total;

	// Output of the information
	cout << "max=" << max[1] << "; avg=" << avg << ";\n\n";
}