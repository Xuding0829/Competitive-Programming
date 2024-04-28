#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    if (s[0] != 'Y' && s[0] != 'e' && s[0] != 's')
    {
        cout << "NO" << endl;
        return;
    }
    if (s[0] == 'e')
        s = 'Y' + s;
    if (s[0] == 's')
        s = "Ye" + s;
    string ans;
    ans = "Yes";
    int l = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (ans[l] != s[i])
        {
            cout << "NO" << endl;
            return;
        }
        l++;
        if (l == 3)
            l = 0;
    }
    cout << "Yes" << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
