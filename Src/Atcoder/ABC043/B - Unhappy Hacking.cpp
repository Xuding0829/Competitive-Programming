#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];

signed main()
{
    string s, ans;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            ans += '0';
        else if (s[i] == '1')
            ans += '1';
        else if (s[i] == 'B' && ans.size())
            ans.pop_back();
    }
    cout << ans << endl;
    return 0;
}