#include <iostream>
#include <cmath>
using namespace std;

class coord {
    int x, y;

public:
    coord() { x = 0; y = 0; };
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) const { i = x; j = y; }
    coord operator+(const coord &obj) const; // бінарний плюс
    coord operator+() const; // унарний плюс
};

coord coord::operator+(const coord &obj) const {
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

coord coord::operator+() const {
    return coord(abs(x), abs(y));
}

int main() {
    coord obj1(-4, 10), obj2(-20, 6), obj3;
    int x, y;
    
    obj3 = obj1 + obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = +obj1;
    obj3.get_xy(x, y);
    cout << "(|obj1(-4, 10)|) X: " << x << ", Y: " << y << "\n";
    
    return 0;
}
