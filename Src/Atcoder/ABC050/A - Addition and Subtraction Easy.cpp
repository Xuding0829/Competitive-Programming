#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

signed main()
{
    char op;
    cin >> n >> op >> m;
    if (op == '+')
        cout << n + m << endl;
    else
        cout << n - m << endl;
    return 0;
}