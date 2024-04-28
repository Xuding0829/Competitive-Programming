#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
int a[N];

signed main()
{
    int n, l;
    cin >> n >> l;
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    cout << endl;
    return 0;
}