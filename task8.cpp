#include <iostream>
using namespace std;

class coord {
    int x, y;

public:
    coord() { x = 0; y = 0; };
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) const { i = x; j = y; }
    friend coord operator*(const coord &obj, int i); 
    friend coord operator*(int i, const coord &obj);
    friend coord operator--(coord &obj);
    friend coord operator--(coord &obj, int notused);
};

coord operator*(const coord &obj, int i) {
    coord temp;
    temp.x = obj.x * i;
    temp.y = obj.y * i;
    return temp;
}

coord operator*(int i, const coord &obj) {
    coord temp;
    temp.x = obj.x * i;
    temp.y = obj.y * i;
    return temp;
}

coord operator--(coord &obj) {
    --obj.x;
    --obj.y;
    return obj;
}

coord operator--(coord &obj, int notused) {
    coord temp(obj);
    obj.x--;
    obj.y--;
    return temp;
}

int main() {
    coord obj1(20, 10);
    int x, y;
    obj1 = obj1 * 2;
    obj1.get_xy(x, y);
    cout << "(obj1(20, 10) * 2) X: " << x << ", Y: " << y << "\n";

    obj1 = 3 * obj1;
    obj1.get_xy(x, y);
    cout << "(3 * obj1(40,20)) X: " << x << ", Y: " << y << "\n";

    --obj1; // префіксна форма
    obj1.get_xy(x, y);
    cout << "(--obj1) X: " << x << ", Y: " << y << "\n";

    obj1--; //постфіксна форма
    obj1.get_xy(x, y);
    cout << "(obj1--) X: " << x << ", Y: " << y << "\n";
    return 0;
}
