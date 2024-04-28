#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 100;
const int mod197 = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, m, k, q;
PII Node[N];
int ans[11];
int dx[] = {0, 1, 0, -1, -1, -1, 1, 1}; // 偏移量
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1}; // 偏移量
map<PII, int> mp;

void solve()
{
    int h, w, n;
    cin >> h >> w >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        Node[i] = {a, b};
        mp[Node[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int tx = Node[i].x + dx[j];
            int ty = Node[i].y + dy[j];
            if (tx < 1 || tx > h || ty < 1 || ty > w)
                continue; // 越界
            PII tmp = {tx, ty};
            mp[tmp]++;
        }
    }

    int sum = 0;                   // 非零矩阵的数量
    int totol = (h - 2) * (w - 2); // 3*3的矩形总数
    for (auto it : mp)
    {
        int tx = it.x.x; // 点的横坐标
        int ty = it.x.y; // 点的纵坐标
        int cnt = it.y;  // 当前点被统计到的次数
        if (tx >= 2 && tx <= h - 1 && ty >= 2 && ty <= w - 1)
        {
            ans[cnt]++; // 此处只考虑中间点，不考虑周围边上的点， 即使边上有点涂黑，涂黑的贡献已经加给它周围的点了
            sum++;
        }
    }

    ans[0] = totol - sum; // ans[0] == 矩形总数减去所有非零的矩形
    for (int i = 0; i < 10; i++)
        cout << ans[i] << endl;
}

signed main()
{
    ios;
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
