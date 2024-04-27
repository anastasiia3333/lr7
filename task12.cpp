#include <iostream>
#include <cstdlib>
using namespace std;

class arraytype{
    int size;
    int *p;

public:
    arraytype(int num);
    ~arraytype() { delete[] p; }
    int &operator[](int i);
};

arraytype::arraytype(int num) {
    p = new int[num];
    if (!p) {
        cout << " Allocation error \n";
        exit(1);
    }
    size = num;
}

int &arraytype::operator[](int i) {
    if (i < 0 || i >= size) {
        cout << "Index value of " << i << " is out of bounds.\n";
        exit(1);
    }
    return p[i];
}

int main() {
    arraytype arr(10);
    arr[1] = 5;
    arr[2] = 10;
    cout << "arr[3] = " << arr[1] << endl;
    cout << "arr[4] = " << arr[2] << endl;
    arr[15] = 3;
    return 0;
}
