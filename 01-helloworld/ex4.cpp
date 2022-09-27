#include <iostream>

using namespace std;

int operation()
{
    double x, y, z, result;
    cin >> x;
    cin >> y;
    cin >> z;

    result = (x + y) - z;

    cout << result << endl;

    return 0;
}

int main()
{

    int exitCode = operation();

    return 0;
}