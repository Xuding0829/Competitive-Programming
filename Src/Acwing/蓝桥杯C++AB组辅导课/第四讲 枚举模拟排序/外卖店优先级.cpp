#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 100;
int a[N];
int score[N], last[N];
bool st[N];
PII order[N];

signed main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++)
        cin >> order[i].x >> order[i].y;

    sort(order, order + m);

    for (int i = 0; i < m;)
    {
        int j = i;
        while (j <= m && order[j] == order[i])
            j++;
        // cout << "i " << i << " j " << j << endl;
        int id = order[i].y, t = order[i].x, cnt = j - i;
        i = j; // i 指向了下一条记录
        // cout << "cnt " << cnt << endl;
        score[id] -= t - last[id] - 1;
        score[id] = max(0, score[id]);

        if (score[id] <= 3)
            st[id] = false;

        score[id] += cnt * 2;

        if (score[id] > 5)
            st[id] = true;
        last[id] = t;
    }

    for (int i = 1; i <= n; i++)
    {
        if (last[i] < t)
        {
            score[i] -= t - last[i];
            if (score[i] > 5)
                st[i] = true;
            else if (score[i] <= 3)
                st[i] = false;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += st[i];
    cout << res << endl;
    return 0;
}