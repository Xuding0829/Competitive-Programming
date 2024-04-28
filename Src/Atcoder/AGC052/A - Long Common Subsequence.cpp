#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 3; i++)
        {
            string s;
            cin >> s;
        }
        for (int i = 1; i <= n; i++)
            cout << '0';
        for (int i = 1; i <= n; i++)
            cout << '1';
        cout << '0' << endl;
    }
    return 0;
}