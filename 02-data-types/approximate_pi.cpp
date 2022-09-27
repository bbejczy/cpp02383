#include <iostream>
#include <math.h>

using namespace std;

double leibnitz(int i){

    double result = pow(-1, i)/(2*i+1);

    return result;

}

int main(){
    int n;
    cin >> n;
    double sum = 0;
    double result = 0;

    for (int i = 0; i<n; i++){
        result = leibnitz(i);
        sum = sum + result;
    }
    cout << sum*4;


    return 0;

}