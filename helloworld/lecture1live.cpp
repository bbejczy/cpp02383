#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>

using namespace std;

int runOperation(string op)
{
    if (op == "add")
    {
        // TODO
        int a, b;
        cin >> a;
        cin >> b;
        int result = a + b;

        cout << "The result is " << result << endl;
        return 0;
    }
    else if (op == "sqrt")
    {
        cout << "Write a number: ";
        float x;
        cin >> x;
        float result = sqrt(x);
        cout << "Square root: " << result << endl;
        return 0;
    }
    else if (op == "fact")
    {
        cout << "Write a number: ";
        float n;
        cin >> n;
        assert(n > 1);
        int result = 1;
        while (n > 1)
        {
            result = result * n;
            n = n - 1;
        }
        cout << "Factorial is " << result << endl;
        return 0;
    }
    else
    {
        cout << "Wrong " << op << endl;
        return 1;
    }
}

int main()
{
    cout << "Hey, wassup!" << endl
         << "Choose one: add, sqrt, fact" << endl;

    while (true)
    {
        string op;
        cin >> op;

        int exitCode = runOperation(op);

        if (exitCode == 0)
        {
            return 0;
        }
        cout << "Try again" << endl;
    }

    return 0;
}