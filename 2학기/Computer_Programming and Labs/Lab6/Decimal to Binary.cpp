#include <iostream>
using namespace std;
void Binary(int Decimal_Num);

int main() {
	int Decimal;
	cin >> Decimal;
	Binary(Decimal);
	return(0);
}

void Binary(int Decimal_Num) {
	if (Decimal_Num > 0)
	{
		Binary(Decimal_Num / 2);
		cout << Decimal_Num % 2;
	}
}
