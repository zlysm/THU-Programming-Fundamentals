#include<iostream>
#include<iomanip>
using namespace std;

int main(void) {
	double wage, tax;
	cin >> wage;
	if (wage <= 3500) {
		tax = 0;
	}
	else if (wage > 63500) {
		tax = (wage - 63500) * 0.5 + 14625;
	}
	else if (wage > 43500) {
		tax = (wage - 43500) * 0.3 + 8625;
	}
	else if (wage > 23500) {
		tax = (wage - 23500) * 0.25 + 3625;
	}
	else if (wage > 8500) {
		tax = (wage - 8500) * 0.2 + 625;
	}
	else if (wage > 5500) {
		tax = (wage - 5500) * 0.15 + 175;
	}
	else if (wage > 4000) {
		tax = (wage - 4000) * 0.1 + 25;
	}
	else {
		tax = (wage - 3500) * 0.05;
	}

	cout <<setiosflags(ios::fixed)<<setprecision(1)<< tax << endl;
	return 0;
}