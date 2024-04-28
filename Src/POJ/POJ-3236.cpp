#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

// #define int long long
using namespace std;

const int N = 2e5 + 100;
int c[N], d[N];
// c 数组代表原身高  d 数组代表与最高牛身高的差距
int n, m;
map<pair<int, int>, bool> mp;

signed main()
{
    int n, m, h, r;
    cin >> n >> m >> h >> r;
    // n 牛的数量 i 最高牛的位置 h 最高的身高 r 对关系
    for (int k = 1; k <= r; k++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (mp[make_pair(a, b)])
            continue;
        d[a + 1]--;
        d[b]++;
        mp[make_pair(a, b)] = true;
    }

    for (int i = 1; i <= n; i++)
        c[i] = c[i - 1] + d[i];

    for (int i = 1; i <= n; i++)
        cout << h + c[i] << endl;
    return 0;
}