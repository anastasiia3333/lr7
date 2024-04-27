#include <iostream>
#include <math.h>
using namespace std;

class coord {
	int x, y;
public: 
	coord() { x = 0; y = 0; };
	coord(int i, int j) { x = i; y = j; }
	void get_xy (int &i, int &j) { i = x; j = y; }
	int operator %(const coord &obj);
};

int coord::operator %(const coord &obj) {
	return x % obj.x;
}

int main (){
	coord obj1(10,10), obj2(2,5), obj3;
	int x,y;
	obj3 = obj1 % obj2;
	obj3.get_xy(x,y);
	cout << "(obj1 % obj2) X: " << x << ", Y: " << y << "\n";
	return 0;
}

