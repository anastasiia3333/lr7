#include <iostream>
#include <cstring>

using namespace std;

class strtype {
private:
    int len;
    char *ptr;

public:
    strtype(const char *s = "");
    strtype(const strtype &obj);
    ~strtype();
    strtype &operator=(const strtype &obj);
    char *get() const { return ptr; }
};

strtype::strtype(const char *s) {
    len = strlen(s) + 1;
    ptr = new char[len];
    if (!ptr) {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(ptr, s);
}

strtype::strtype(const strtype &obj) {
    len = obj.len;
    ptr = new char[len];
    if (!ptr) {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(ptr, obj.ptr);
}

strtype::~strtype() {
    delete[] ptr;
}

strtype &strtype::operator=(const strtype &obj) {
    if (this != &obj) {
        delete[] ptr;
        len = obj.len;
        ptr = new char[len];
        if (!ptr) {
            cout << "Allocation error\n";
            exit(1);
        }
        strcpy(ptr, obj.ptr);
    }
    return *this;
}

void show(const strtype &x) {
    char *s = x.get();
    cout << s << "\n";
}

int main() {
    strtype a("Sunny"), b("day!");
    a = b;
    cout << "Length of a: " << strlen(a.get()) << endl;
    cout << "Length of b: " << strlen(b.get()) << endl;

    *a.get() = 'l';

    cout << "a: ";
    show(a);
    cout << "b: ";
    show(b);

    return 0;
}
