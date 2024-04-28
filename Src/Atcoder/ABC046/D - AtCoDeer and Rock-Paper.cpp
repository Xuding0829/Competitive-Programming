#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int res;
// 每回合结束要求 (Paper) ≦ (Rock).
signed main()
{
    string s;
    cin >> s;
    int p = 0, g = 0;
    // p - 布      g - 石头
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'g') // 如果对方出石头
        {
            if (p < g)      // 布的数量小于石头的数量
                res++, p++; // 可以出布，---------胜局
            else            // 布的数量大于等于石头的数量
                g++;        // 不可以出布，只可以出石头 --平局
        }
        else // 如果对方出布
        {
            if (p < g)      // 布的数量小于石头的数量
                p++;        // 可以出布 ----------------平局
            else            // 布的数量大于等于石头的数量
                g++, res--; // 不可以出布，只能出石头--- 败局
        }
    }
    cout << res << endl;
    return 0;
}