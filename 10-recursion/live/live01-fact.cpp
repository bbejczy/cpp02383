// Simple recursive implementation of factorial
#include <iostream>
using namespace std;

unsigned int fact(unsigned int n) {
    if (n == 0) {
        cout << "    fact(" << n << ") = 1.  End of recursion!" << endl ;
        return 1;
    } else {
        cout << "    fact(" << n << ") = " << n << " * fact(" << n-1 << ") " << endl;
        unsigned int ret = n * fact(n-1);
        cout << "    returning fact(" << n << ") = " << ret << endl;
        return ret;
    }
}

int main() {
    unsigned int n;
    
    cout << "Please enter a non-negative number: " ;
    cin >> n;
    cout << "Computing fact(" << n << ")... " << endl;
    unsigned int result = fact(n);
    cout << "The result is: " << result << endl;

    return 0;
}
