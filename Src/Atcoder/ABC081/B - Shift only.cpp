#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            cout << res << endl;
            return 0;
        }
    }
    bool is_even = true;
    while (is_even)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] /= 2;
            if (a[i] & 1)
            {
                res++;
                is_even = false;
                cout << res << endl;
                return 0;
            }
        }
        res++;
    }
    return 0;
}