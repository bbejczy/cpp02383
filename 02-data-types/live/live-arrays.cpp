#include <iostream>
using namespace std;

void printArray(int length, int array[]){
    cout << "The array contains: ";
    for (int i = 0; i < length; i=i+1){
        cout << array[i] << " ";
    }
    cout << endl;
}

void sumArray(int length, int array[]){
    cout << "The sum of array: " << endl;
    int n = 0;
    for (int i = 0; i < length; i=i+1){
        n = n + array[i];
    }
    cout << "sum is: " << n << endl;

}
int main()
{
    int a[] = {10, 20, 30};
    printArray(3, a);
    sumArray(3, a);

    int b[3];
    cout << "give me 3 intergers: ";
    for (int i =0; i<3; i=i+1){
        cin >> b[i];
    }

    printArray(3, b);
    sumArray(3, b);

    int n;
    cout << "How many elements?";
    cin >> n;
    int *c = new int[n];

    cout << "give me 3 intergers: ";
    for (int i =0; i<n; i=i+1){
        cin >> c[i];
    }

    printArray(n, c);
    sumArray(n, c);

    delete[]c;

    return 0;
}