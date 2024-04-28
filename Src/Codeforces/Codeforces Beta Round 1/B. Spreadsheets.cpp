#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e4;

int a[N];
int T, n, m;

// 5
// R228C494
// RZ228
// R26C26
// AZ26
// A26

// 判断哪种形式的转换
bool judge(string s)
{
    if (s[0] == 'R' && s[1] >= '0' && s[1] <= '9')
    {
        for (int i = 2; i < s.length(); i++)
        {
            if (s[i] == 'C')
                return 1;
        }
    }
    return 0;
}

void solve()
{
    string s;
    cin >> s;

    int row = 0, col = 0;
    // 第一种情况  R23C55  ————>  BC23
    if (judge(s))
    {
        int i;
        for (i = 1; s[i] >= '0' && s[i] <= '9'; i++)
        {
            row = row * 10 + s[i] - '0';
        }
        for (i += 1; s[i] >= '0' && s[i] <= '9'; i++)
        {
            col = col * 10 + s[i] - '0';
        }
        // 输出col
        int t = col, k = 0;
        while (t)
        {
            a[k++] = t % 26;
            // 注意这里
            t = (t - 1) / 26;
        }
        for (int i = --k; i >= 0; i--)
        {
            printf("%c", 'A' + (a[i] - 1 + 26) % 26);
        }
        // 输出row
        cout << row;
    }
    // 第二种情况  BC23    ————>  R23C55
    else
    {
        int i;
        string str;
        for (i = 0; s[i] >= 'A' && s[i] <= 'Z'; i++)
        {
            col = col * 26 + s[i] - 'A' + 1;
        }
        for (i; s[i] >= '0' && s[i] <= '9'; i++)
        {
            row = row * 10 + s[i] - '0';
        }
        cout << "R" << row << "C" << col;
    }
    cout << endl;
}

int main()
{
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
