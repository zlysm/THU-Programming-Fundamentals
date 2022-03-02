#include<iostream>
#include<iomanip>
using namespace std;

int main(void) {
	float sale, rate, tax;

	cin >> sale >> rate;
	tax = sale * rate;
	cout << setiosflags(ios::fixed) << setprecision(2) << tax;

	return 0;
}