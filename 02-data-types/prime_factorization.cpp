#include <iostream>

using namespace std;

int divisionCheck(int n)
{
    for (int i = 2; i <= n; i++)
    {

        if (n == i)
        {
            cout << i;
            return n/i;
        }
        else if (n % i == 0)
        {
            cout << i << " * ";
            return n / i;
        }
    }

    // just to have a solution for the 1 edge-case
    cout << n;
    return n;
}

int main()
{
    int n;
    cin >> n;

    do
    {
        n = divisionCheck(n);
    } while (n!=1);

    return 0;
}