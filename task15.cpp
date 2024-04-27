#include <iostream>
using namespace std;

class coord {
    int x, y;

public:
    coord() { x = 0, y = 0; };
    coord(int i, int j) { x = i, y = j; }
    coord operator<<(int i);
    coord operator>>(int i);
    friend ostream &operator<<(ostream &out, const coord &obj);
};

coord coord::operator<<(int i) {
    return coord(x << i, y << i);
}

coord coord::operator>>(int i) {
    return coord(x >> i, y >> i);
}

ostream &operator<<(ostream &out, const coord &obj) {
    out << "(" << obj.x << ", " << obj.y << ")";
    return out;
}

int main() {
    coord a(1, 1);
    coord b(2, 2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a << 1 = " << (a << 1) << endl;
    cout << "b >> 1 = " << (b >> 1) << endl;

    return 0;
}
