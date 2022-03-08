#include<iostream>
using namespace std;

int main(void) {
	int num1, num2, num3, temp;
	cin >> num1 >> num2 >> num3;

	if (num1 > num2) {
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	if (num1 > num3) {
		temp = num1;
		num1 = num3;
		num3 = temp;
	}
	if (num2 > num3) {
		temp = num2;
		num2 = num3;
		num3 = temp;
	}

	cout << num1 << " " << num2 << " " << num3 << endl;
	return 0;
}
