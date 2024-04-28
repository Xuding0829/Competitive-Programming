#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int res;
string s;

int f(int l, int r) // 计算l~r这段区间的数字
{
    int t;
    for (int i = l; i <= r; i++)
        t = t * 10 + s[i] - '0';
    return t;
}

signed main()
{
    cin >> s;
    int len = s.size();                      // 字符串的长度
    for (int i = 0; i < 1 << (len - 1); i++) // 枚举【1<<(len - 1)】种情况  // 插空法，长度为len，中间有len - 1个空可插
    {
        int tmp = s[0] - '0'; // 取出第一位
        for (int j = 0; j < len - 1; j++)
        {
            if (i >> j & 1) // 判断i的j位是否是1，如果是1，表示这个位置放+
            {
                res += tmp; // 如果这个位置放+，加上前面数
                tmp = s[j + 1] - '0';// tmp 指向下一位
            }
            else
                tmp = tmp * 10 + s[j + 1] - '0';
        }
        if (tmp) // 后面不放+，加上后面一段的数字
            res += tmp;
    }
    cout << res << endl;
    return 0;
}