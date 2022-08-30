#include <iostream>
#include <vector>

using namespace std;

int printSum(int n)
{
    vector<float> values;
    float input;
    float result;
    if (n <= 0)
    {
        result = 0;
    }
    for (int i = 0; i < n; i = i + 1)
    {
        cin >> input;
        result = result + input;
    }
    cout << result << endl;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    printSum(n);

    return 0;
}