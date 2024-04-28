#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << a[n - 1] << endl;
    return 0;
}