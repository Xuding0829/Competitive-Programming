#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int f[N];

// 题目大意: 给你一串字符串，问是否存在一个连续的字串，且字串满足有一个字母出现的次数大于字串长度的一半；

// 思路： 即寻找xx x-x 这样的字串

signed main()
{
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cout << i << ' ' << i + 1 << endl;
            flag = false;
            break;
        }
        else if (s[i] == s[i - 2] && i >= 2)
        {
            cout << i - 1 << ' ' << i + 1 << endl;
            flag = false;
            break;
        }
    }

    if (flag)
        puts("-1 -1");
    return 0;
}