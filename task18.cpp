#include <iostream>
#include <cstring>
using namespace std;

class strtype {
    char *ptr;
    int length;
public:
    strtype(const char *str);
    ~strtype() {
        cout << "Freeing ptr\n";
        delete[] ptr;
    }

    char *get() { return ptr; }
    strtype &operator=(const strtype &obj);

    friend strtype operator+(const strtype &obj1, const strtype &obj2);

    bool operator==(const strtype& obj) const {
        return strcmp(this->ptr, obj.ptr) == 0;
    }
    bool operator>(const strtype& obj) const {
        return strcmp(this->ptr, obj.ptr) > 0;
    }
    bool operator<(const strtype& obj) const {
        return strcmp(this->ptr, obj.ptr) < 0;
    }
};
strtype::strtype(const char *str) {
    length = strlen(str) + 1;
    ptr = new char[length];
    if (!ptr) {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(ptr, str);
}

strtype &strtype::operator=(const strtype &obj) {
    if (this != &obj) {
        delete[] ptr;
        length = obj.length;
        ptr = new char[length];
        if (!ptr) {
            cout << "Allocation error\n";
            exit(1);
        }
        strcpy(ptr, obj.ptr);
    }
    return *this;
}

strtype operator+(const strtype &obj1, const strtype &obj2) {
    int new_length = obj1.length + obj2.length - 1;
    char *newStr = new char[new_length];
    if (!newStr) {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(newStr, obj1.ptr);
    strcat(newStr, obj2.ptr);

    strtype result(newStr);
    delete[] newStr;
    return result;
}

int main() {
    strtype a("Sunny day");
    strtype b("Good day");
    strtype z("Some test");
    strtype x(" for checking the functionality");
    strtype p("");
    if (a > b) {
        cout << "'a' is longer than 'b'." << endl;
    } else {
        cout << "'a' is shorter than 'b'." << endl;
    }

    if (a < b) {
        cout << "'a' is shorter than 'b'." << endl;
    } else {
        cout << "'a' is longer than 'b'." << endl;
    }

    if (a == b) {
        cout << "'a' = 'b'." << endl;
    } else {
        cout << "'a' != 'b'." << endl;
    }
    p = a;
    cout << p.get() << endl;
    strtype q = z + x;
    cout << q.get() << endl;
}

