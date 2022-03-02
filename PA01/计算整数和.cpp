#include<iostream>
using namespace std;

int main(void) {
	int max, min;
	int j = 0;
	cin >> min >> max;

	for (int i = min; i <= max; i++) {
		j += i;
	}
	cout << j;
	return 0;
}
