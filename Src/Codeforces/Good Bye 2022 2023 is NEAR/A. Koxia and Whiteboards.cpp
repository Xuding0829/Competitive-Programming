#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[110];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m; i++)
        {
            cin >> a[1];
            sort(a + 1, a + n + 1);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans += a[i];
        cout << ans << endl;
        ;
    }
    return 0;
}
