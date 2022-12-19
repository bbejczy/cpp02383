//============================================================================
// Name        : live03-constructors.cpp
// Description : Constructors and inheritance
//============================================================================

#include <iostream>

using namespace std;

class Father {
public:
    Father();
    Father(int u, int v);
    virtual void display(void);
    virtual ~Father() {}; // See https://www.geeksforgeeks.org/virtual-destructor
protected:
    int x;
private:
    int y;
};

class Son : public Father {
public:
    Son(int u, int v);
    void display(void);
private:
    int z;
};

Father::Father() {
    this->x = 101;
    this->y = 101;
}

Father::Father(int u, int v) {
    this->x = u;
    this->y = v;
}

// Note that Son's constructor needs to invoke Father's constructor, if Son
// wants to initialize the private variable y in Father (that Son cannot access)
Son::Son(int u, int v) : Father(u, 42) {
    // this->x = u; // Redundant, because Father's constructor initialises x
    this->z = v;
}

void Father::display(void) {
    cout << "x=" << x << ", y=" << y << endl;
}

void Son::display(void) {
    cout << "x=" << x << ", z=" << z << endl;
}

int main(void) {
    Father f(10, 10);
    Son s(20, 20);

    cout << "Father: ";
    f.display();

    cout << "Son: ";
    s.display();

    f = s;

    cout << "Father (after the assignment f = s): ";
    f.display();

    return 0;
}
