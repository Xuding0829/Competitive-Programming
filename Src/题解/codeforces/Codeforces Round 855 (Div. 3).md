### A - Is It a Cat?

略

```c++
#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> n >> s;
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';

        string t;
        t += s[0];
        for (int i = 1; i < s.size(); i++)
            if (s[i] != s[i - 1])
                t += s[i];

        if (t == "meow")
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
```



### B - Count the Number of Pairs

题意：给定一个字符串，问最多进行k次操作（大写变小写，小写变大写）后，大小写的对数最多是多少

思路：记录下各个字母大小写的数量，遍历26个字母， 每次加上min(大写字母， 小写字母)即不进行操作当前的对数最后再加上k（假设都可以操作），而通过操作最多可以获得的对数是（大写数量+小写数量）/ 2  二者取最小值

```c++
#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;
int lo[26], up[26];

void solve()
{
    memset(lo, 0, sizeof (lo));
    memset(up, 0, sizeof(up));
    string s;
    cin >> n >> m >> s;
    for (auto i : s)
        if (i >= 'A' && i <= 'Z')
            up[i - 'A']++;
        else
            lo[i - 'a']++;

    int maxn = 0;
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        res += min(up[i], lo[i]);
        maxn += (up[i] + lo[i]) / 2;
    }
    res = min(res + m, maxn);
    cout << res << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
```



### C2 - Powering the Hero (hard version)

题意：

英雄牌：战斗力为0，可获得最上面的战力即获得一次战力，之后加入你的队伍

战力牌：可是英雄获得a[i]的战斗力

要求队伍的战力最大

思路：

贪心，优先队列存储战力最大值，对于英雄而言，每次获得队列中最大能量值（实际操作中就是丢弃比下一个最大能量值小的战力牌）才能使最后的总战力最大，之后加入队伍

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    i64 res = 0;
    std::vector<i64> a(n);
    std::priority_queue<i64, std::vector<i64>, std::less<>> q;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if(a[i])
            q.push(a[i]);
        else if(!a[i] && !q.empty())
            res += q.top(), q.pop();
    }

    std::cout << res << '\n';
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



### D - Remove Two Letters

题意：每次移走相邻的两个字符，问能获得多少个不同的字符串

思路：

模拟一下字符串  xxxyz  删去第一二个字符，变成xyz 二三个变成xyz  三四个xxz

不能发现如果  i - 1 和 i + 1 这两个位置的字符串如果一样，那么最后的字符串是一样的。因此就去寻找 i - 1  和 i + 1 位置不同的的字符串

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int res = 0;
    for (int i = 1; i < s.size(); i++)
        if(s[i - 1] != s[i + 1])
            res++;
    std::cout << res << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```

  

### E2 - Unforgivable Curse (hard version)

题意:给定两个长度为n的字符串，你可对两个相距为k或k+1的字符进行交换，问最后能否使得两个字符串相同

思路：

模拟交换操作，可以发现这个操作可以交换每个字符串；若要使得字符串相同，首先字符串所含字符必须相同，其次对于位置相同但字符不同的字符串必须可以进行交换操作。

对于某个位置得字符串可以操作：i - k （左边距离为k的字符）

i + k （右边距离为k的字符）至少有一个在字符串内

为什么是 k ？  i - k 都不在区间里面了，k + 1 更不可能在了

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string s, t;
    std::cin >> s >> t;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i] && i - k < 0 && i + k >= n)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    
    if (s == t)
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
    while (t--)
    {
        solve();
    }
    return 0;
}
```



### F - Dasha and Nightmares

题意：给定n个字符串，问有多少对字符串拼接后，长度为奇数， 只出现了25个字母，每个出现的字母是奇数

思路;

cnt 【n】[26] 记录每个字符串中各个字母出现的次数 这里只需要异或用0，1表示奇偶性即可，之后用26位二进制表示各个字母出出现的情况

枚举每个字母，当前字母不出现的情况 tmp = 1 << 26 - 1 - (1 << i)

遍历每个字母串，此时若第j个字符串的第i位为0， 那么， 它对应的mask可以与（tmp ^ mask）构造出我们想要的字符串，这个（tmp ^ mask ）字符串的数量用f表示 

对于每个字母，我们一开始遍历的时候遇到i位为零的情况会加上1，我们需要恢复

```c++
#include <bits/stdc++.h>

using i64 = long long;

int f[1 << 26];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::vector<std::array<int, 26>> cnt(n);
    std::vector<int> mask(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
        for(auto it : s[i])
            cnt[i][it - 'a']++; // 统计s[i]中各个字母出现的次数
        for (int j = 0; j < 26; j++)
            mask[i] |= (cnt[i][j] % 2) << j;//讲s[i]的各个字母的出现情况转化为01串
    }

    i64 res = 0;
    for (int i = 0; i < 26; i++)
    {
        int tmp = (1 << 26) - 1 - (1 << i); // 枚举缺少每一位的情况
        for (int j = 0; j < n; j++)
        {
            if(cnt[j][i] == 0)
            {
                f[mask[j]]++;
                res += f[mask[j] ^ tmp];
            }
        }

        for (int j = 0; j < n; j++)
            if(cnt[j][i] == 0)
                f[mask[j]]--;
    }
    std::cout << res << '\n';
    
    return 0;
}
```

### G. Symmetree

题意：给你一颗树，判断它是否左右对称

橙题，害怕++

借鉴了[https://zhuanlan.zhihu.com/p/619412980] 这位大佬的文章，万分感谢

思路:

判断数是否左右对称，看看某个节点的子树有多少个，如果有偶数个，偶数个子树必须长一样并且对称，如果有奇数个，先拿走这个多出来的子树，剩下偶数个子树就必须满足上面说过的样子多出来的这个子树插在中间。

这里运用了树哈希来判断子树是否一样   OI wiki [https://oi-wiki.org/graph/tree-hash/]关于树哈希的讲解

```c++
#include <bits/stdc++.h>

using i64 = long long;
using ull = unsigned long long;

constexpr int N = 2e5 + 100;

const unsigned long long seed = (std::chrono::steady_clock::now().time_since_epoch().count());
ull shift(ull x)
{   // 自然溢出
    x ^= seed;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= seed;
    return x;
}

void solve()
{
    int n;
    std::cin >> n;

    // 建图
    std::vector<int> adj[n];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 哈希操作
    std::vector<ull> hash(n);
    std::function<void(int, int)> get_hash = [&] (int u, int fa)
    {
        hash[u] = 1;
        for (auto v : adj[u])
        {
            if(v == fa)
                continue;
            get_hash(v, u);
            hash[u] += shift(hash[v]);
        }
    };

    get_hash(0, -1);

    // dfs check 操作（本质查找某个节点u， 其子树哈希值出现的次数）
    std::map<ull, int> cnt[n];
    std::function<bool(int, int)> dfs = [&](int u, int fa)
    {
        for(auto v : adj[u])
        {
            if(v == fa)
                continue;
            cnt[u][hash[v]]++;
        }

        int count = 0;
        ull idx = 0;
        for(auto [v, w] : cnt[u])
        {
            if(w & 1) // 奇数次
                count++, idx = v;
        }

        if(count > 1) // 奇数个必然不可能组成对称树
            return false;
        else if(count == 0) // 偶数个相同且对称可以
            return true;
        else
        {
            for(auto v : adj[u])
            {
                if(hash[v] == idx)
                    return dfs(v, u); // 递归判断多余的那个子树是否对称
            }
        }
        return true;
    };

    // 输出
    bool res = dfs(0, -1);
    std::cout << (res ? "YES\n" : "NO\n" );
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```

