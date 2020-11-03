#include <iostream>
using namespace std;
int factorial(int number);

int main() {
	int number;
	cin >> number;
	
	cout << factorial(number) << endl;
	return (0);
}

int factorial(int number) {
	if (number <= 1)
		return (1);
	return (number * factorial(number - 2));
}