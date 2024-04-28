#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

signed main()
{
    cin >> n;
    for (int i = 0; i < 5 * n; i++)
        cin >> a[i];
    sort(a, a + 5 * n);
    double sum = 0;
    for (int i = n; i < 4 * n; i++)
        sum += a[i];
    double average = sum / 3 / n;
    cout << average << endl;
    return 0;
}