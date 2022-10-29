#include <iostream>
#include "vector2d.h"

using namespace std;

int main() {
    
    // string *strings[] = {'not', ' '};
    
    v2d a(1, 2);
    v2d b(3, 4);
    
    cout << "Vector addition does " << (&(a + b) == &a) << " change the vector for which it was called\n";
    
    cout << "Vector/scalar addition does " << (&(a * 2) == &a) << " change the vector for which it was called\n";

}