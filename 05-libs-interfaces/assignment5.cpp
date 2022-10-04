#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> master;
typedef vector<int> dataset;

enum action
{
    data_a,
    data_b,
    none
};

void display_e1(const master &ms)
{
    for (auto i : ms)
    {
        sort(i.begin(), i.end());
        for (auto e : i)
        {
            cout << e << " ";
        }
    }
}

void display_e2(const master &ms)
{
    int longer = 0;
    if (ms[0].size() > ms[1].size())
    {
        longer = ms[0].size();
    }
    else if (ms[0].size() < ms[1].size())
    {
        longer = ms[1].size();
    }
    else
    {
        longer = ms[0].size();
    }
    for (int i = 0; i <= longer; i++)
    {
        if (ms[0][i] != 0)
        {
            cout << ms[0][i] << " ";
        }
        if (ms[1][i] != 0)
        {
            cout << ms[1][i] << " ";
        }
    }
}

void display_e3(const master &ms)
{
    int longer = 0;
    int diff = 0;
    int r = 0;
    dataset result;

    if (ms[0].size() > ms[1].size())
    {
        longer = ms[0].size();
        diff = ms[0].size() - ms[1].size();
        // for (int k = 0; k <= diff; k++){
        //     ms[1].push_back(0);
        // }
    }
    else if (ms[0].size() < ms[1].size())
    {
        longer = ms[1].size();
        diff = ms[1].size() - ms[0].size();
        // for (int j = 0; j <= diff; j++){
        //     ms[0].push_back(0);
        // }
    }
    else
    {
        longer = ms[0].size();
    }

    for (int i = 0; i <= longer; i++)
    {
        // if (ms[0][i]!=0){
        //     cout << ms[0][i] << " ";
        // }
        // if (ms[1][i]!=0){
        //     cout << ms[1][i] << " ";
        // }
        result.push_back(ms[0][i] * ms[1][i]);
    }

    for (auto l : result)
    {
        r = l + r;
    }

    cout << r;
}

action str2action(string s)
{
    if (s == "a")
        return data_a;
    if (s == "b")
        return data_b;
    return none;
}

void readValues(action act, dataset &a, dataset &b)
{
    int temp;
    cin >> temp;
    if (!cin.fail())
    {
        switch (act)
        {
        case data_a:
        {
            a.push_back(temp);
            break;
        }
        case data_b:
        {
            b.push_back(temp);
            break;
        }
        case none:
        {
            break;
        }
        }
    }
}

int main()
{

    master ms;
    dataset a;
    dataset b;
    string actStr;
    action act;

    while (true)
    {
        cin >> actStr;
        if (cin.fail())
        {

            ms.push_back(a);
            ms.push_back(b);

            // display_e1(ms);
            // display_e2(ms);
            display_e3(ms);
            return 0;
        }
        else
        {
            act = str2action(actStr);
            readValues(act, a, b);
        }
    }

    return 0;
}
