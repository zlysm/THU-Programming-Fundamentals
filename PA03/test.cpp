#include<iostream>
using namespace std;

int main(void) {
	int num;
	int sum = 0, counter = 0;
	cin >> num;
	for (int i = 1; counter < num; i++) {
		int isPrime = 0;
		for (int j = 2; j <= i; j++) {
			if (i % j == 0) {
				isPrime++;
			}
		}
		if (isPrime == 1) {
			sum += i;
			counter++;
		}
	}
	cout << sum << endl;
	return 0;
}