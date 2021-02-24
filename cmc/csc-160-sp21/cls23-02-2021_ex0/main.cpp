// Done as an example of what referencing an overflow array value will do on C++

#include <iostream>

using namespace std;

int main() {
	int i, vals[5] = { 1,2,3,4,5 };

	for (i = 0; i <= 5; i++) {
		cout << "values[" << i << "]=" << vals[i] << "\n";
	}
}