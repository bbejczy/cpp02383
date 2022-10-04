#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    int y = 42;

    int *p = &x;

    cout << "Pointer p has value " << p << " and points to " << *p << endl;

    p = &y;

    cout << "Pointer p has value " << p << " and points to " << *p << endl;

    int a[] = {10, 20, 30};

    cout << "Array a has a value " << a << " and the first element is " << a[0] << endl;

    p = a;

    cout << "Pointer p has value " << p << " and points to " << p[1] << endl;

    return 0;
}