#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}
    Counter(int initialCount) : count(initialCount) {}
    friend Counter &operator++(Counter &c) {
        c.count++;
        return c;
    }

    friend Counter operator++(Counter &c, int notused) {
        Counter old = c;
        c.count++;
        return old;
    }

    int getCount() const {
        return count;
    }

    friend ostream &operator<<(ostream &out, const Counter &obj) {
        out << obj.count;
        return out;
    }
};

int main() {
    Counter a(8);
    cout << "a = " << a << endl;
    cout << "(a++) = " << a++ << endl;
    cout << "After (a++) = " << a << endl;
    cout << "(++a) = " << ++a << endl;
    cout << "After (++a) = " << a << endl;
    return 0;
}
