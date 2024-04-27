#include <iostream>
using namespace std;

class three_d {
    int x, y, z;

public:
    three_d(int i, int j, int k) : x(i), y(j), z(k) {}
    three_d() : x(0), y(0), z(0) {}
    void get(int &i, int &j, int &k) const { i = x; j = y; k = z; }
    three_d& operator++();
    three_d& operator--();
    three_d operator+(const three_d& obj) const;
    three_d operator-(const three_d& obj) const;
    bool operator==(const three_d& obj) const;
    bool operator!=(const three_d& obj) const;
    bool operator||(const three_d& obj) const;
    three_d operator+(int value) const;
    friend three_d operator+(int value, const three_d& obj);
    friend ostream& operator<<(ostream& out, const three_d& obj);
};

three_d& three_d::operator++() {
    x++;
    y++;
    z++;
    return *this;
}

three_d& three_d::operator--() {
    x--;
    y--;
    z--;
    return *this;
}

three_d three_d::operator+(const three_d& obj) const {
    return three_d(x + obj.x, y + obj.y, z + obj.z);
}

three_d three_d::operator-(const three_d& obj) const {
    return three_d(x - obj.x, y - obj.y, z - obj.z);
}

bool three_d::operator==(const three_d& obj) const {
    return (x == obj.x) && (y == obj.y) && (z == obj.z);
}

bool three_d::operator!=(const three_d& obj) const {
    return !(*this == obj);
}

bool three_d::operator||(const three_d& obj) const {
    return (x || obj.x) || (y || obj.y) || (z || obj.z);
}

three_d three_d::operator+(int value) const {
    return three_d(x + value, y + value, z + value);
}

three_d operator+(int value, const three_d& obj) {
    return three_d(obj.x + value, obj.y + value, obj.z + value);
}

ostream& operator<<(ostream& out, const three_d& obj) {
    out << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
    return out;
}

int main() {
    three_d three1(0, 2, 4);
    three_d three2(1, 3, 5);
    cout << "three1: " << three1 << endl;
    cout << "++three1: " << ++three1 << endl;
    cout << "three2: " << three2 << endl;
    cout << "three1 + three2: " << three1 + three2 << endl;
    cout << "three1 - three2: " << three1 - three2 << endl;
    cout << "\n\n(three1 == three2) is " << (three1 == three2) << endl;
    cout << "(three1 != three2) is " << (three1 != three2) << endl;
    cout << "(three1 || three2) is " << (three1 || three2) << endl;
    cout << "three1 + 7: " << three1 + 5 << endl;
    cout << "5 + three2: " << 10 + three2 << endl;
    return 0;
}
