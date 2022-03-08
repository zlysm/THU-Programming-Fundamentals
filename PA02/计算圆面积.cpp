#include<iostream>
#include<iomanip>
using namespace std;
const double PI = 3.14159265358979323846;

int main(void) {
	double radius, area;
	cin >> radius;
	area = PI * radius * radius;
	cout << setiosflags(ios::fixed) << setprecision(2) << area << endl;
	return 0;
}