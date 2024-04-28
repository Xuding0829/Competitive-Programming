#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

signed main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << i + 1 << endl;
            break;
        }
    return 0;
}