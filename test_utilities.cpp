#include <iostream>
#include "utilities.h"
using namespace std;

int main() {
	cout << "add(2,3) == 5: " << (add(2, 3) == 5 ? "PASS" : "FAIL") << endl;
	int x;
	std::cin >> x;
	return 0;
}
