#include <iostream>
using namespace std;

class three_d {
	int x, y, z;
public:
	three_d(int i, int j, int k) {x = i; y = j; z = k;}
	three_d() {x = 0; y = 0; z = 0;}
	void get(int &i, int &j, int &k) {i = x; j = y; k = z;}
	three_d operator+(three_d obj) {
		return three_d(x + obj.x, y + obj.y, z + obj.z);
	}

	three_d operator-(three_d obj) {
        return three_d(x - obj.x, y - obj.y, z - obj.z);
    }


	three_d& operator ++() {
		x++;
		y++;
		z++;
		return *this;
	}

	three_d& operator--() {
		x--;
		y--;
		z--;
		return *this;
	}
};

int main() {
    three_d three1(1, 2, 3);
    int x, y, z;

    three1.get(x, y, z);
    cout << "three: " << x << ", " << y << ", " << z << endl;

    three_d three2 = ++three1;

    three2.get(x, y, z);
    cout << "++three: " << x << ", " << y << ", " << z << endl;

    three1 = three_d(1, 2, 3);
    three1.get(x, y, z);
    cout << "three: " << x << ", " << y << ", " << z << endl;

    three2 = --three1;

    three2.get(x, y, z);
    cout << "--three: " << x << ", " << y << ", " << z << endl;

    three1 = three_d(8, 9, 10);
    three2 = three_d(4, 5, 6);
    
    three1.get(x, y, z);
    cout << "\nthree1: " << x << ", " << y << ", " << z << endl;
    
    three2.get(x, y, z);
    cout << "three2: " << x << ", " << y << ", " << z << endl;

    three_d three3 = three1 + three2;
    three_d three4 = three1 - three2;
    
    three3.get(x, y, z);
    cout << "three1 + three2: " << x << ", " << y << ", " << z << endl;

    three4.get(x, y, z);
    cout << "three1 - three2: " << x << ", " << y << ", " << z << endl;

    return 0;
}
