#include<iostream>
using namespace std;
const float PI = 3.14;

int main(void) {
	int type;
	double area, radius, length, width, side;
	cout << "please select a type(1 for circle, 2 for rectangle, 3 for square)" << endl;  //enter the type
	cin >> type;

	switch (type) {
	case 1:
		cout << "please enter the radius:";  //circle
		cin >> radius;
		area = PI * radius * radius;
		break;
	case 2:
		cout << "please enter the length and width:" << endl;  //rectangle
		cin >> length >> width;
		area = length * width;
		break;
	default:
		cout << "please enter the side:" << endl;  //square
		cin >> side;
		area = side * side;
		break;
	}

	cout << "area is " << area << endl;
	return 0;
}
