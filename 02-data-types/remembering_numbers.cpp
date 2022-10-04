#include <iostream>

using namespace std;

int main()
{

    int storage[1001] = {};

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            return false;
        }
        cout << storage[n] <<endl;
        storage[n] = storage[n] + 1;
        }

    return 0;
}
