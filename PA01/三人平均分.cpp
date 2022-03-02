#include<iostream>
using namespace std;

int main(void) {
	double a, b, c, average;
	cin >> a >> b >> c;
	average = (a + b + c) / 3;
	cout << (int)(average + 0.5) << endl;

	return 0;
}
