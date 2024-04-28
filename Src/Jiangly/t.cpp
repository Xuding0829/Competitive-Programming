// Author:dd
// #pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fer(i, a, n) for (int i = (a); i <= (n); ++i)
#define rep(i, n, a) for (int i = (n); i >= (a); --i)
#define fi first
#define se second
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define none cout << "-1\n";
#define mul_t  \
    int _t;    \
    cin >> _t; \
    while (_t--)
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define Hash gp_hash_table
#define notall(x) x.begin() + 1, x.end()
#define all(x) x.begin(), x.end()

template <class T>
void writeln(const T &t)
{
    cout << t << '\n';
}
template <class T, class... args>
void writeln(const T &t, const args &...rest)
{
    cout << t << ' ';
    writeln(rest...);
}

template <class T1, class T2>
void writeln(const vector<T1> &v, T2 n)
{
    int sz = v.size();
    if (sz == n)
        for (auto c : v)
            cout << c << ' ';
    else
        for (int i = 1; i <= n; i++)
            cout << v[i] << ' ';
    cout << '\n';
}

template <class T1, class T2>
void writeln(const pair<T1, T2> p)
{
    cout << p.first << ' ' << p.second << '\n';
}

typedef long long ll;
// 求x在树中比几个元素大:t.order_of_key(x);
// 求树中的第k大:t.find_by_order(k),从0开始;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_ll_set;

const int int_inf = 0x3f3f3f3f;
const ll ll_inf = 1000000000000000100;

// get a pow with mod in O(logn)
ll qpow(ll a, ll k, ll mod)
{
    ll res = 1;
    a %= mod;
    while (k)
    {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

// great commone division
template <class T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}
template <class T>
T exgcd(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    T d = exgcd(b, a % b, x, y);
    T temp = x;
    x = y;
    y = temp - a / b * y;
    return d;
}

// get primes smaller than n in O(n)
vector<bool> isnotprime;
vector<int> primes;
void getprime(int n)
{
    isnotprime.resize(n + 1, 0);
    isnotprime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isnotprime[i] == 0)
            primes.push_back(i);
        for (size_t j = 0; j < primes.size() && i * primes[j] <= n; j++)
        {
            isnotprime[i * primes[j]] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}

// combinations
struct combination
{
    combination(int n, ll mo)
    {
        siz = n, mod = mo;
        inv.resize(n + 1, 1), preinv.resize(n + 1, 1), fac.resize(n + 1, 1);
        for (int i = 2; i <= n; i++)
            inv[i] = (mod - mod / i) * inv[mod % i] % mod, preinv[i] = preinv[i - 1] * inv[i] % mod;
        for (long long i = 2; i <= n; i++)
            fac[i] = fac[i - 1] * i % mod;
    }
    ll C(int n, int m)
    {
        if (n == 0 && m == 0)
            return 1;
        if (n < m || m < 0 || n < 0)
            return 0;
        return fac[n] * preinv[m] % mod * preinv[n - m] % mod;
    }
    ll A(int n, int m)
    {
        if (n == 0 && m == 0)
            return 1;
        if (n < m || m < 0 || n < 0)
            return 0;
        return fac[n] * preinv[n - m] % mod;
    }
    vector<ll> inv;
    vector<ll> preinv;
    vector<ll> fac;

private:
    int siz;
    ll mod;
};

// DSU
struct dsu
{
    vector<int> fa, siz;
    dsu(int n)
    {
        fa.resize(n + 1), siz.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i, siz[i] = 1;
    }
    int ffind(int x)
    {
        return x == fa[x] ? x : fa[x] = ffind(fa[x]);
    }
    bool uuion(int x, int y)
    {
        x = ffind(x), y = ffind(y);
        if (x == y)
            return false;
        fa[y] = x, siz[x] += siz[y], siz[y] = 0;
        return true;
    }
    bool check(int x, int y)
    {
        return ffind(x) == ffind(y);
    }
    void init()
    {
        for (size_t i = 1; i <= fa.size() - 1; i++)
            fa[i] = i, siz[i] = 1;
    }
    int getsize(int x)
    {
        return siz[x];
    }
};

// operations with bit
struct Bitcounter
{
    template <class T>
    T reversebit(T x)
    {
        int f = 1;
        if (x < 0)
            x = -x, f = -1;
        vector<int> v;
        while (x)
        {
            v.push_back(x & 1);
            x >>= 1;
        }
        reverse(v.begin(), v.end());
        T now = 1, ans = 0;
        for (auto &x : v)
            ans += x * now, now <<= 1;
        return ans * f;
    }
    template <class T>
    T lowbit(T x)
    {
        return x & -x;
    }
    template <class T>
    int countbit(T x)
    {
        int sum = 0;
        while (x)
            sum += x & 1, x >>= 1;
        return sum;
    }
    template <class T>
    T nextknum(T x, int n)
    {
        if (!x || lowbit(x) >= (T)1 << (n - countbit(x)))
            return 0;
        T a = lowbit(x), b = x + a, c = b ^ x, m = (c >> 2) / a;
        return b | m;
    }
};

// heavy light tree
struct HLD
{
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> adj;
    int cur;

    HLD() {}
    HLD(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0)
    {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u)
    {
        if (parent[u] != -1)
        {
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }

        siz[u] = 1;
        for (auto &v : adj[u])
        {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]])
            {
                swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u)
    {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u])
        {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] > dep[top[v]])
            {
                u = parent[top[u]];
            }
            else
            {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v)
    {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int jump(int u, int k)
    {
        if (dep[u] < k)
        {
            return -1;
        }

        int d = dep[u] - k;

        while (dep[top[u]] > d)
        {
            u = parent[top[u]];
        }

        return seq[in[u] - dep[u] + d];
    }

    bool isAncester(int u, int v)
    {
        return in[u] <= in[v] && in[v] < out[u];
    }

    int rootedParent(int u, int v)
    {
        swap(u, v);
        if (u == v)
        {
            return u;
        }
        if (!isAncester(u, v))
        {
            return parent[u];
        }
        auto it = upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y)
                              { return in[x] < in[y]; }) -
                  1;
        return *it;
    }

    int rootedSize(int u, int v)
    {
        if (u == v)
        {
            return n;
        }
        if (!isAncester(v, u))
        {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }

    int rootedLca(int a, int b, int c)
    {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

// math tools
template <class T1, class T2>
T1 updiv(T1 a, T2 b)
{
    if (a < 0)
        return a / b;
    return a / b + (a % b != 0);
}
template <class T1, class T2>
T1 downdiv(T1 a, T2 b)
{
    if (a > 0)
        return a / b;
    return a / b - (a % b != 0);
}
template <class T1, class T2>
void cmin(T1 &a, T2 b)
{
    a = min<T1>(a, b);
}
template <class T1, class T2>
void cmax(T1 &a, T2 b)
{
    a = max<T1>(a, b);
}

template <const int T>
struct ModInt
{
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {}
    int val() { return x; }
    ModInt operator+(const ModInt &a) const
    {
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    ModInt operator-(const ModInt &a) const
    {
        int x0 = x - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    ModInt operator*(const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator/(const ModInt &a) const { return *this * a.inv(); }
    bool operator==(const ModInt &a) const { return x == a.x; };
    bool operator!=(const ModInt &a) const { return x != a.x; };
    void operator+=(const ModInt &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
    }
    void operator-=(const ModInt &a)
    {
        x -= a.x;
        if (x < 0)
            x += mod;
    }
    void operator*=(const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator/=(const ModInt &a) { *this = *this / a; }
    friend ModInt operator+(int y, const ModInt &a)
    {
        int x0 = y + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    friend ModInt operator-(int y, const ModInt &a)
    {
        int x0 = y - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    friend ModInt operator*(int y, const ModInt &a) { return ModInt(1LL * y * a.x % mod); }
    friend ModInt operator/(int y, const ModInt &a) { return ModInt(y) / a; }
    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x; }
    friend istream &operator>>(istream &is, ModInt &t) { return is >> t.x; }

    ModInt pow(int64_t n) const
    {
        ModInt res(1), mul(x);
        while (n)
        {
            if (n & 1)
                res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    ModInt inv() const
    {
        int a = x, b = mod, u = 1, v = 0;
        while (b)
        {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0)
            u += mod;
        return u;
    }
};

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//-------------------------------------------
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    n++, m++;
    int mxtim = n + m + q + 1;
    map<pii, set<int>> bads;
    fer(i, 1, q)
    {
        int t, d, c;
        cin >> t >> d >> c;
        c++;
        if (d == 1)
            fer(i, 1, m) bads[{c, i}].insert(t);
        else
            fer(i, 1, n) bads[{i, c}].insert(t);
    }
    queue<pair<pair<int, int>, int>> qq;
    vector<vector<int>> tim(n + 1, vector<int>(m + 1, int_inf));
    int tt = 0;
    tim[1][1] = 0;
    set<pair<pair<int, int>, int>> isvis;
    while (tt <= mxtim && !bads[{1, 1}].count(tt))
        qq.push({{1, 1}, tt}), isvis.insert({{1, 1}, tt}), tt++;
    while (!qq.empty())
    {
        auto Z = qq.front();
        qq.pop();
        auto x = Z.fi.fi, y = Z.fi.se, z = Z.se;
        // writeln("x,y,t",x,y,z);cout<<endl;
        int zz = z + 1;
        int z1 = zz, z2 = zz;
        int f1 = 1, f2 = 1;
        if (y < m)
        {
            while (f1 && bads[{x, y + 1}].count(z1))
            {
                // writeln("z1",x,y,z1);cout<<endl;
                if (bads[{x, y}].count(z1))
                    f1 = 0;
                z1++;
            }
            if (f1)
            {
                int ttt = 0;
                while (z1 <= x + y + 2 + q && ttt <= q && z1 <= mxtim && !bads[{x, y + 1}].count(z1) && !isvis.count({{x, y + 1}, z1}))
                {
                    // writeln("z11",x,y,z1);cout<<endl;
                    if (!isvis.count({{x, y + 1}, z1}))
                        qq.push({{x, y + 1}, z1}), cmin(tim[x][y + 1], z1), isvis.insert({{x, y + 1}, z1}), z1++;
                    ++ttt;
                }
            }
        }
        if (x < n)
        {
            while (f2 && bads[{x + 1, y}].count(z2))
            {
                // writeln("z2",x,y,z2);cout<<endl;
                if (bads[{x, y}].count(z2))
                    f2 = 0;
                z2++;
            }
            if (f2)
            {
                int ttt = 0;
                while (z2 <= x + y + 2 + q && ttt <= q && z2 <= mxtim && !bads[{x + 1, y}].count(z2) && !isvis.count({{x + 1, y}, z2}))
                {
                    // writeln("z22",x,y,z2);cout<<endl;
                    if (!isvis.count({{x + 1, y}, z2}))
                        qq.push({{x + 1, y}, z2}), cmin(tim[x + 1][y], z2), isvis.insert({{x + 1, y}, z2}), z2++;
                    ++ttt;
                }
            }
        }
    }
    // fer(i,1,n)fer(j,1,m)cout<<tim[i][j]<<" \n"[j==m];
    writeln(tim[n][m] > mxtim ? -1 : tim[n][m]);
}
signed main()
{
    FASTIO
#define OJ
#ifndef OJ
    freopen("o_0.in", "r", stdin);
    freopen("o_0.out", "w", stdout);
#endif
#define MUL_CASE
#ifdef MUL_CASE
    mul_t solve();
#else
    solve();
#endif
}
/*
  1.深呼吸，不要紧张，慢慢读题，读明白题，题目往往比你想的简单。
  2.暴力枚举:枚举什么，是否可以使用一些技巧加快枚举速度（预处理、前缀和、数据结构、数论分块）。
  3.贪心:需要排序或使用数据结构（pq）吗，这么贪心一定最优吗。
  4.二分：满足单调性吗，怎么二分，如何确定二分函数返回值是什么。
  5.位运算：按位贪心，还是与位运算本身的性质有关。
  6.数学题：和最大公因数、质因子、取模是否有关。
  7.dp：怎么设计状态，状态转移方程是什么，初态是什么，使用循环还是记搜转移。
  8.搜索：dfs 还是 bfs ，搜索的时候状态是什么，需要记忆化吗。
  9.树上问题：是树形dp、树上贪心、或者是在树上搜索。
  10.图论：依靠什么样的关系建图，是求环统计结果还是最短路。
  11.组合数学：有几种值，每种值如何被组成，容斥关系是什么。
  12.交互题：log(n)次如何二分，2*n 次如何通过 n 次求出一些值，再根据剩余次数求答案。
  13.如果以上几种都不是，多半是有一个 point 你没有注意到，记住正难则反。
 */