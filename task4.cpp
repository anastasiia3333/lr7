#include <iostream>
using namespace std;

class coord {
	int x, y;
public: 
	coord() { x = 0; y = 0; };
	coord(int i, int j) { x = i; y = j; }
	void get_xy (int &i, int &j) { i = x; j = y; }
	bool operator >(const coord obj);
	bool operator <(const coord obj);	
};

bool coord::operator >(const coord obj) {
	return (x > obj.x) && (y > obj.y);		
}	

bool coord::operator <(const coord obj) {
	return (x < obj.x) && (y < obj.y);		
		
}	

int main() {
	coord obj1(10,4), obj2(5,3), obj3(12, 8);
	if (obj1 > obj2) cout << "obj1 > than obj2\n";
	else cout << "obj1 < than obj2\n";

	if (obj1 > obj3) cout << "obj1 > than obj3\n";
	else cout << "obj1 < than obj3\n";
	return 0;
}
