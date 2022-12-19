// Sum of arithmetic series 1..n, i.e. 1+..+n
#include <iostream>
using namespace std;

// Smart implementation by Carl Friedrich Gauss (1777-1855) :-)
unsigned int sum_fast(unsigned int n) {
    return (n * (n + 1)) / 2 ;
}

// Iterative implementation
unsigned int sum_iter(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

// A possible recursive implementation
unsigned int sum_rec(unsigned int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum_rec(n-1);
    }
}

// An alternative implementation using an accumulator argument (acc)
//
// Note that this function is in "tail recursive" format: it either returns a
// value (without recursion), or directly returns the result of a
// recursive call.  Functions like this enable very efficient code
unsigned int sum_rec_tailcall(unsigned int n, unsigned int acc = 0) {
    if (n == 0) {
        return acc;
    }
    return sum_rec_tailcall(n-1, n+acc);
}


int main(){
    unsigned int n;

    // Try with with big numbers, e.g. 1000000
    // Compare compilation with and without optimization (g++ option -O3)
    cout << "Give me a non-negative integer: " ;
    cin >> n;
    cout << "Computing sum(1.." << n << ") using sum_fast... ";
    cout << sum_fast(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_iter... ";
    cout << sum_iter(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec_tailcall... ";
    cout << sum_rec_tailcall(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec... ";
    cout << sum_rec(n) << endl;

    return 0;
}
