#include <iostream>
#include "fraction.h"

using namespace std;

int main(){

    while(true){
        int num1, num2, denom1, denom2;
        string slash, op;

        if (cin.fail()) {
            return 0;
        }

        cin >> num1;
        cin >> slash;
        cin >> denom1;
        cin >> op;
        cin >> num2;
        cin >> slash;
        cin >> denom2;

        fraction left(num1, denom1);
        fraction right(num2, denom2);

        // fraction result;
        
        if(op == "+"){
            left.add(right);
        }else if (op == "*")
        {
            left.mult(right);
        }else if (op == "div")
        {
            left.div(right);
        }else{
            return 0;
        }
        
        left.display();
    }

    return 0;
}