#include<iostream>
#include<iomanip>
using namespace std;

int main(void) {
	double celsius, fahrenheit;

	cin >> celsius;
	fahrenheit = 1.8 * celsius + 32;
	cout << setiosflags(ios::fixed) << setprecision(1) << fahrenheit << endl;

	return 0;
}
