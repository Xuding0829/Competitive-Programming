// 拉链法
#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 100003;

int T, n, m;
bool flag;
string s;

int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

signed main()
{
    ios;
    memset(h, -1, sizeof(h));
    cin >> n;

    while (n--)
    {
        int x;
        string op;
        cin >> op >> x;
        if (op == "I")
            insert(x);
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("N0");
        }
    }
    return 0;
}
// 开放寻址法
#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];
int T, n, m;

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k++;
        if (k == N)
            k = 0;
    }
    return k;
}

signed main()
{
    ios;
    memset(h, 0x3f, sizeof(h));

    cin >> n;
    while (n--)
    {
        int x;
        string op;
        cin >> op >> x;
        int k = find(x);
        if (op == "I")
            h[k] = x;
        else
        {
            if (h[k] != null)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
