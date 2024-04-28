#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1e6;

int a[N];
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "1 " << n << endl;
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
