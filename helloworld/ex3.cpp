#include <iostream>
#include <string>

using namespace std;

int decision(int x, int y)
{
    if (x == y)
    {
        cout << x << " is equal to " << y << endl;
    }
    else if (x > y)
    {
        cout << x << " is bigger than " << y << endl;
    }
    else if (x < y)
    {
        cout << x << " is smaller than " << y << endl;
    }
    return 0;
}

int main()
{

    int x, y;
    cin >> x;
    cin >> y;

    decision(x, y);

    return 0;
}