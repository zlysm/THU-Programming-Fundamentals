#include<iostream>
using namespace std;

int main(void) {
	int num;
	cin >> num;

	int flag2 = 0, flag5 = 0, production = 1;
	for (int i = 2; i <= num; i++) {
		int temp = i;
		for (; temp % 5 == 0; temp /= 5) {
			flag5++;
		}
		for (; temp % 2 == 0; temp /= 2) {
			flag2++;
		}
		production = production * temp % 10;
	}
	for (int i = 0; i < flag2 - flag5; i++) {
		production = production * 2 % 10;
	}
	cout << production << endl;
	return 0;
}
