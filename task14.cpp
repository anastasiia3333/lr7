#include <iostream>
#include <stdexcept>
using namespace std;

class dynarray {
private:
    int *ptr;
    int size;

public:
    dynarray(int s) : ptr(new int[s]), size(s) {
        if (s <= 0) {
            throw invalid_argument("Array size must be positive");
        }
    }

    ~dynarray() {
        delete[] ptr;
    }

    dynarray(const dynarray &other) : ptr(new int[other.size]), size(other.size) {
        copy(other.ptr, other.ptr + size, ptr);
    }

    dynarray &operator=(const dynarray &other) {
        if (this != &other) {
            delete[] ptr;
            size = other.size;
            ptr = new int[size];
            copy(other.ptr, other.ptr + size, ptr);
        }
        return *this;
    }

    int &operator[](int i) {
        if (i < 0 || i >= size) {
            throw out_of_range("Index out of range");
        }
        return ptr[i];
    }
};

int main() {
    try {
        dynarray arr(10);
        for (int i = 0; i < 10; ++i) {
            arr[i] = i * 5;
        }
        for (int i = 0; i < 10; ++i) {
            cout << "Element [" << i << "]: " << arr[i] << endl;
        }

        dynarray arr1 = arr;
        arr[1] = 20;
        cout << "\nElement [1] of arr: " << arr[1] << endl;
        cout << "Element [1] of arr1: " << arr1[1] << endl;
    }
    catch (const exception &ex) {
        cerr << "Exception: " << ex.what() << endl;
    }
    return 0;
}
