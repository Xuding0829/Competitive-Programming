#include <iostream>
const int maxn = 1e6 + 10;
int a[maxn];
int l, n;
int u, v;
int sum = 0;
using namespace std;
int main()
{
    for (int i = 0; i < maxn; i++)
        a[i] = 1;
        
    cin >> l >> n;
    while (n--)
    {
        cin >> u >> v;
        for (int i = u; i <= v; i++)
            a[i] = 0;
    }
    for (int i = 0; i <= l; i++)
        sum += a[i];
    cout << sum << endl;
    return 0;
}