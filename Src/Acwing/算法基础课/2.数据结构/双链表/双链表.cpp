#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
int val[N], l[N], r[N], idx;

void inti()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add(int k, int x)
{
    val[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx++;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int t;
    cin >> t;
    inti();
    while (t--)
    {
        string s;
        int x;
        cin >> s;
        if (s == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (s == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (s == "D")
        {
            cin >> x;
            remove(x + 1);
        }
        else if (s == "IL")
        {
            int k;
            cin >> k >> x;
            add(l[k + 1], x);
        }

        else if (s == "IR")
        {
            int k;
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << val[i] << " ";
    cout << endl;

    return 0;
}
