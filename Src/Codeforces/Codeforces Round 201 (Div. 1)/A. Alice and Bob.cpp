#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;
int n;
int a[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int temp = a[0];
    for (int i = 1; i < n; i++)
        temp = __gcd(temp, a[i]);

    int res = a[n - 1] / temp - n;

    if (res & 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;

    return 0;
}
