#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
int stk[N],tt;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int x;
        if (s == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if (s == "pop")
        {
            tt--;
        }
        else if (s == "empty")
        {
            if (tt)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else if (s == "query")
        {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}
