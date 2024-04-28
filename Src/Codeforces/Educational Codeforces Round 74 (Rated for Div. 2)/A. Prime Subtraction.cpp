#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll T, x, y;
    cin >> T;
    while (T--)
    {
        cin >> x >> y;
        if (x - y == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
