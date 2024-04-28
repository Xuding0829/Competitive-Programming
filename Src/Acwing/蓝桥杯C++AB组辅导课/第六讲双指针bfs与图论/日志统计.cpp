#include <iostream>
#include <algorithm>
#define int long long
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 2e5 + 100;
int cnt[N];
int n, d, k;
bool st[N];
PII logs[N];

signed main()
{
    scanf("%d%d%d", &n, &d, &k);

    for (int i = 0; i < n; i++)
        scanf("%d%d", &logs[i].x, &logs[i].y);

    sort(logs, logs + n); // 按时间排序

    // for (int i = 0; i < n; i++)
    //     printf("%d %d\n", logs[i].x, logs[i].y);

    for (int i = 0, j = 0; i < n; i++) // i在前，j在后
    {
        int id = logs[i].y;
        cnt[id]++;

        while (logs[i].x - logs[j].x >= d)
        {
            cnt[logs[j].y]--;
            j++;
        }

        if (cnt[id] >= k)
            st[id] = true;
    }

    for (int i = 0; i <= 1e5; i++)
        if (st[i])
            printf("%d\n", i);
    return 0;
}