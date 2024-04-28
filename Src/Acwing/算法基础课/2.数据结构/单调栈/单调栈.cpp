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
int stk[N];

int main()
{
    int tt = 0, t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x)
            tt--;
        if (tt)
            cout << stk[tt] << " ";
        else
            cout << -1 << " ";
        stk[++tt] = x;
    }
    return 0;
}
