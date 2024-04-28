#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef __int128 int28;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int state[N];
int a[N];
int que[N];

int main()
{
    int tt = -1, hh = 0;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            que[++tt] = x;
        }
        else if (s == "empty")
        {
            if (hh <= tt)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else if (s == "pop")
        {
            hh++;
        }
        else if (s == "query")
        {
            cout << que[hh] << endl;
        }
    }
    return 0;
}