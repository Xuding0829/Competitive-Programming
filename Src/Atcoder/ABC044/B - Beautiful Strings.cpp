#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];

signed main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    for (int i = 'a'; i <= 'z'; i++)
        if (mp[i] % 2)
        {
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
    return 0;
}