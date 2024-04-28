## A. Medium Number

### 题目描述

输出三个数中的第二大的数

### solution

排序即可

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N];

void solve()
{
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3);
    cout << a[1] << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
```

## B. Atilla's Favorite Problem

### 题目描述

给定一串字符串，输出字符串中最小的字符对应在字母表中的位置

### solution

循环遍历字符串

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N];

void solve()
{
    string s;
    cin >> n >> s;
    int ans = 'a';
   
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= ans)
            ans = s[i];
    }
    cout << ans - 97 + 1 << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
```

## C. Advantage

### 题目描述

给定一个数组，输出每个元素与除去本身的最大值的差

### solution

排序，记录最大值与次大值，遍历数组，如果元素不是最大值则减去最大值，如果是最大值则减去次大值

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N], b[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int maxn1 = b[n];
    int maxn2 = b[n - 1];
    for (int i = 1; i <= n; i++)
    {
        if(a[i] == maxn1)
            cout << a[i] - maxn2 << ' ';
        else
            cout << a[i] - maxn1 << ' ';
    }
    cout << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
```

## D. Challenging Valleys

### 题目描述

给定一串数组，问这个数组a[ l .....r ]是否满足如下性质

>   0 <= l <= r <= n - 1
>
>   a l = a l + 1 = a l + 2......  = ar
>
>   l = 0 or a l - 1 > a l
>
>   r = n - 1 or a r < a r + 1

若满足这些性质，输出YES 否则输出 NO

### solution

观察这些性质，我们可以发现

如果一个数组中所有元素相等  或者  单调  或者 先减后增 都为 YES

如果是先增后减  都为  NO（此处单调不是数学意义上的单调，此处单调是指一种趋势）

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N];

void solve()
{
    cin >> n;
    int cnt;
    for (int i = 0; i < n; i++)
        cin >> a[i];
	//保证res数组中的相邻元素不重复
    vector<int> res;
    res.push_back(a[0]);
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            res.push_back(a[i]);

    int ans = 0;
    for (int i = 0; i < res.size(); i++)
    {
        //由题意模拟
        if ((i == 0 || res[i - 1] > res[i]) && (i == res.size() - 1 || res[i] < res[i + 1]))
            ans++;
    }
    puts(ans == 1 ? "YES" : "NO");
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
```

## E. Binary Inversions

### 题目描述

给定一串二进制数组，把其中一个 1 变成 0 或者 0 变成 1 使得数组逆序对数量最大，问这个最大数量是几

### solution

贪心，要逆序对数量多，应该使得靠前的 0 变 1， 靠后的1 变 0

分别记录原始数组， 操作后的逆序对数量， 比较大小后输出

find函数用于记录逆序对数量，由于是二进制， 逆序对数量即是0前面1的个数

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n;
int a[N];

int find(int a[])
{
    int ans = 0;
    int cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i])
            cnt1++;
        else
            ans += cnt1;
    }
    return ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum1 = 0, sum2 = 0, sum3 = 0;
    sum1 = find(a);
    //前0改1
    for (int i = 1; i <= n; i++)
    {
        if(!a[i])
        {
            a[i] = 1;
            sum2 = find(a);
            a[i] = 0;
            break;
        }
    }
    后1改0
    for (int i = n; i >= 1; i--)
    {
        if(a[i])
        {
            a[i] = 0;
            sum3 = find(a);
            a[i] = 1;
            break;
        }
    }
    cout << max(sum1, max(sum2, sum3)) << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
```

## F. Quests 

### 题目描述

给定一个长度为n的序列a表示有n个任务

每次完成了一个任务就可以获得a[ i ]  个金币 

问最多间隔k天能够在期限为d天的时间内总共获至少 c个金币？ 求最大k

若k无限大输出Infinity ，k不存在输出Impossible, 否则输出最大k值

### solution

贪心，对数组a进行排序，对其进行前缀和处理

如果每天获得最大的金币都小于c 则不可能输出 impossible

如果前d天，不管k多大，前缀和都可以达到c则输出Infinity

二分，在 0，d 中寻找 k  

​			

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n, c, d;
int a[N];
int s[N];

bool cmp(int x, int y)
{
    return x > y;
}

bool check(int k)
{
    int res1 = s[min(n, 1 + k)] * (d / (1 + k));
    //res1 以(1+k)为周期获得的金币
    int res2 = s[min(n, d % (1 + k))];
    //res2 以剩余天数获得的金币
    if ((res1 + res2) >= c)
        return true;
    else
        return false;
}

void solve()
{
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    if (a[1] * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }
    else if (s[min(n, d)] >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    else
    {
        int l = 0, r = d;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            //如果k取mid并且可以在d天内获得c个金币，由于k取最大值，那么应该在mid~r之间寻找k
            else
                r = mid - 1;
            //如果k = mid 不能获得c个金币，那么在  l  ~   r -  1  取得k
        }
        if (l < d)
            cout << l << endl;
    }
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
```

## G. SlavicG's Favorite Problem

### 题目描述

对于一棵树， 每条边对应一个权值w， 问从a到b，允许跳一次， 问是否存在一条路径使得异或结果为0

### solution

从开始不到达b进行一次异或前缀和， 然后从b出发做一遍异或前缀和，如果a出发有一个点u的前缀和跟从b出发的一个点v前缀和相等，那么就从a移动到u， 再从u跳跃到v，再从v移动到b即可

// 这题不与前面几题一起做， 码风差异比较da

```c++
#include<bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bool res = false;
    std::set<int> s;
    s.insert(0);

    auto bfs = [&]() -> void
    {
        std::vector<int> dis(n);
        std::vector<bool> st(n, false);

        std::queue<int> q;
        q.push(a);
        dis[a] = 0;
        while(q.size())
        {
            int u = q.front();
            q.pop();

            if(st[u])
                continue;
            st[u] = true;

            for(auto [v, w] : adj[u])
            {
                if(!st[v] && v != b)
                {
                    dis[v] = dis[u] ^ w;
                    s.insert(dis[v]);
                    q.push(v);
                }
            }
        }
    };

    auto bfs2 = [&]() -> void
    {
        std::vector<int> dis(n);
        std::vector<bool> st(n, false);

        std::queue<int> q;
        q.push(b);
        dis[b] = 0;
        while(q.size())
        {
            int u = q.front();
            q.pop();

            if(st[u])
                continue;
            st[u] = true;

            for (auto [v, w] : adj[u])
            {
                if(!st[v])
                {
                    dis[v] = dis[u] ^ w;
                    if(s.count(dis[v]))
                        res = true;
                    q.push(v);
                }
            }
        }
    };

    bfs();

    bfs2();

    if(res)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
```

