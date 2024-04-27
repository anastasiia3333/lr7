#include <iostream>
#include <cstring>
using namespace std;

class strtype {
    char *ptr;

public:
    strtype(char const *s);
    strtype(const strtype &obj);
    ~strtype() { delete[] ptr; }
    char &operator[](size_t i);
    char *get() { return ptr; }
};

strtype::strtype(char const *s) {
    int len;
    len = strlen(s) + 1;
    ptr = new char[len];
    if (!ptr) {
        exit(1);
    }
    strcpy(ptr, s);
}

strtype::strtype(const strtype &obj) {
    int len;
    len = strlen(obj.ptr) + 1;
    ptr = new char[len];
    if (!ptr) {
        exit(1);
    }
    strcpy(ptr, obj.ptr);
}

char &strtype::operator[] (size_t i) {
    if (i < 0 || i > strlen(ptr)) {
        cout << "Index out of range!";
        exit(1);
    }
    return ptr[i];
}

void show(strtype x) {
    char *s;
    s = x.get();
    cout << s << endl;
}

int main() {
    strtype s1("Sunny"), s2("day!");
    cout << "s1: ";
    show(s1);
    cout << "s2: ";
    show(s2);
    cout << "s1[0]: " << s1[0] << endl;
    cout << "s2[0]: " << s2[0] << endl;
    
    return 0;
}
