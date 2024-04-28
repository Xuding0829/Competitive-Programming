### 文章目录

-   [前言](#_2)
-   [1.排序](#1_11)
-   -   -   [(1) 快速排序](#1__12)
        -   [(2) 归并排序（求逆序对）](#2__37)
-   [2.基础算法](#2_68)
-   -   -   [(1) 二分](#1__69)
-   [3.数学](#3_110)
-   -   -   [(1) 线性筛（朴素，最小质因子，因子数，欧拉函数）](#1__111)
        -   -   [\- 朴素线性筛](#__112)
            -   [\- 最小质因子筛](#__141)
            -   [\- 因子数筛](#__170)
            -   [\- 欧拉函数筛](#__212)
        -   [(2) 快速幂 (龟速乘)](#2____246)
        -   [(3) 欧几里得算法 (gcd, exgcd)](#3__gcd_exgcd_282)
        -   [(4) jiangly的模板元板子](#4_jiangly_311)
        -   [(5) jiangly的组合数板子](#5_jiangly_398)
        -   [(6) ygg的组合数板子](#6_ygg_549)
-   [4.数据结构](#4_585)
-   -   -   [(1) 单调队列 (单调递减，递增)](#1___586)
        -   [(2) 树状数组（前缀和，差分）](#2__609)
        -   [(3) 线段树（维护区间和模板）](#3__668)
        -   [(4) 重链剖分（维护树结构）](#4__733)
        -   [(5) 分块（维护区间和模板）](#5__796)
        -   [(6) 并查集](#6__856)
        -   [(7) 可持久化线段树（维护区间和）](#7__890)
        -   [(8) 珂朵莉树（ODT）](#8_ODT_1004)
        -   [(9) 莫队模板](#9__1083)
        -   [(10) 主席树模板（静态查询区间第 k 小）](#10__k__1135)
-   [5.图论](#5_1234)
-   -   -   [(1) Dijkstra （堆优化）](#1_Dijkstra__1236)
        -   [(2) Spfa](#2_Spfa_1274)
        -   -   [\- 朴素](#__1275)
            -   [\- SLF优化](#_SLF_1318)
            -   [\- LLL优化](#_LLL_1364)
            -   [\- SLF + LLL 优化](#_SLF__LLL__1417)
        -   [(3) Kruskal最小生成树](#3_Kruskal_1468)
        -   [(4) 最近公共祖先LCA (倍增，重链剖分)](#4_LCA___1516)
        -   -   [\- 倍增](#__1517)
            -   [\- 重链剖分](#__1550)
        -   [(5) 求树的重心](#5__1595)
        -   [(6) Johnson全源最短路](#6_Johnson_1622)
        -   [(7) 匈牙利算法 (二分图匹配)](#7___1713)
        -   [(8) Tarjan](#8_Tarjan_1755)
        -   -   [\- 缩点 / 强连通分量](#____1756)
            -   [\- 割点 / 割顶](#____1811)
            -   [\- 桥](#__1850)
            -   [\- 点双连通分量](#__1893)
            -   [\- 边双连通分量](#__1980)
-   [6.网络流](#6_2055)
-   -   -   [(1) 网络最大流](#1__2056)
        -   -   [\- Dinic（当前弧优化）](#_Dinic_2057)
            -   [\- ISAP（当前弧优化）](#_ISAP_2148)
        -   [(2) 最小费用最大流](#2__2240)
        -   -   [\- Dinic + SPFA（LLL+SLF）](#_Dinic__SPFALLLSLF_2241)
-   [7.字符串](#7_2352)
-   -   -   [(1) KMP字符串匹配](#1_KMP_2353)
        -   [(2)Trie 字典树](#2Trie__2399)
        -   [(3) 字符串双哈希](#3__2461)
-   [8.杂项](#8_2514)
-   -   -   [(1) 快读快写模板](#1__2515)

# 前言

该篇文章创立旨意在于保存博主个人常用的一些模板，便于在遗忘时回顾查看，或者需要时方便回顾，思考到放在博客里可以反复查看，也更利于有需要的人学习使用，于是该博客就诞生了。

该博客的模板由于是博主个人归纳和总结的，所以可能不免会出现一些使用上的问题或者程序内的漏洞，如果存在此类漏洞，可以私信博主进行更改。

代码可以任意转载使用，遇到问题也可以私信博主。

# 1.排序

### (1) 快速排序

```cpp
int arr[N], n;
//arr数组 n元素个数
inline void quicksort(int l, int r)
{
	if (l >= r) return;
	int x = arr[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j)
	{
		do ++i; while (arr[i] < x);
		do --j; while (arr[j] > x);
		if (i < j) swap(arr[i], arr[j]);
	}
	quicksort(l, j), quicksort(j + 1, r);
}

使用: 
-quicksort(0, n - 1) <排序区间[0, n - 1]>
-quicksort(1, n) <排序区间[1, n]>

均为闭区间 对应数组第一个元素和最后一个元素下标

123456789101112131415161718192021
```

* * *

### (2) 归并排序（求逆序对）

```cpp
int arr[N], tmp[N], n;
//arr数组 tmp临时数组 n元素个数
inline void mergesort(int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    mergesort(l, mid), mergesort(mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++], ans = ans + mid - i + 1;//ans是逆序对
        
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++], ans = ans + mid - i + 1;//ans是逆序对
    
    for (i = l, j = 0; i <= r; ++i, ++j) arr[i] = tmp[j];
}

使用: 
-mergesort(0, n - 1) <排序区间[0, n - 1]>
-mergesort(1, n) <排序区间[1, n]>
-ans <逆序对数>

均为闭区间 对应数组第一个元素和最后一个元素下标

1234567891011121314151617181920212223242526
```

* * *

* * *

# 2.基础算法

### (1) 二分

```cpp

bool check(int mid)
{
	return true;
	//return false;
}

void solve()
{
	//板子1
    int l = x, r = y;
    while (l < r)//求区间[x, y]上满足性质的最小值
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l; //此时l == r

	//板子2
	int l = x, r = y;
    while (l < r)//求区间[x, y]满足性质的最大值
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
	cout << l; //此时l == r
}


使用: 给出区间[x, y]
求出满足性质的 <最小值> 用 <板子1>
求出满足性质的 <最大值> 用 <板子2>

1234567891011121314151617181920212223242526272829303132333435
```

* * *

* * *

# 3.数学

### (1) 线性筛（朴素，最小质因子，因子数，欧拉函数）

#### \- 朴素线性筛

```cpp

const int N = 1e6 + 10;//筛时候记得减去10
vector<int> primes;//存质数
bool minp[N];//素性判断 false为质数 true为合数

void getprimes()
{
	primes.reserve(maxn);//预处理空间
	for (int i = 2; i <= N - 10; ++i)
	{
		if (!minp[i]) primes.emplace_back(i);
		for (auto& p : primes)
		{
			if (p * i > N - 10) break;
			minp[i * p] = true;
			if (i % p == 0) break;
		}
	}
}

使用:
*getprimes() <预处理>

-if(minp[idx]) <对idx进行素性判断，详见上方>
-primes[idx]

1234567891011121314151617181920212223242526
```

#### \- 最小质因子筛

```cpp

const int N = 1e6 + 10;//筛时候记得减去10
vector<int> primes;//存质数
int minp[N];//存最小质因子

void getprimes()//朴素+最小质因子
{
	primes.reserve(maxn);//预处理空间
	for (int i = 2; i <= N - 10; ++i)
	{
		if (!minp[i]) minp[i] = i, primes.emplace_back(i);
		for (auto& p : primes)
		{
			if (p * i > N - 10) break;
			minp[i * p] = p;
			if (i % p == 0) break;
		}
	}
}

使用:
*getprimes() <预处理>

-minp[idx] <数字idx的最小质因子>
-primes[idx]

1234567891011121314151617181920212223242526
```

#### \- 因子数筛

```cpp

const int N = 1e6 + 10;//筛时候记得减去10
vector<int> primes;
int cnt[N], fac[N];//cnt最小质因子数 fac因子数
bool minp[N];

void getprimes()//朴素 + 筛因子数目
{
	fac[1] = 1;
	primes.reserve(maxn);//预处理空间
	for (int i = 2; i <= N - 10; ++i)
	{
		if (!minp[i]) primes.emplace_back(i), fac[i] = 2, cnt[i] = 1;
		for (auto& p : primes)
		{
			if (p * i > N - 10) break;
			minp[i * p] = true;
			if (i % p == 0)
			{
				fac[i * p] = fac[i] / (cnt[i] + 1) * (cnt[i] + 2);
				cnt[i * p] = cnt[i] + 1;
				break;
			}
			else
			{
				fac[i * p] = fac[i] * fac[p];
				cnt[i * p] = 1;
			}
		}
	}
}

使用:
*getprimes() <预处理>

-fac[idx] <数字idx的因子数>
-primes[idx]

1234567891011121314151617181920212223242526272829303132333435363738
```

* * *

#### \- 欧拉函数筛

```cpp

const int N = 1e6 + 10;//筛时候记得减去10
vector<int> primes;
int phi[N];
bool minp[N];

void getprimes() {
    phi[1] = 1;
    primes.reserve(2e5);
    for (int i = 2; i <= N - 10; ++i) {
        if (!minp[i]) minp[i] = true, primes.emplace_back(i), phi[i] = i - 1;
        for (auto& p : primes) {
            if (i * p > N - 10) break;
            minp[i * p] = true;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}


使用:
*getprimes() <预处理>

-phi[idx] <数字idx的欧拉函数值>
-primes[idx]

123456789101112131415161718192021222324252627282930
```

* * *

### (2) 快速幂 (龟速乘)

```cpp
using i64 = long long;
const int mod = 998244353;
//快速幂
i64 qpow(i64 a, i64 b)//a为底数 b为质数 mod为模数
{
	i64 res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

//龟速乘
i64 smul(i64 a, i64 b)//a 和 b 为因数 mod为模数
{
	i64 res = 0;
	while (b)
	{
		if (b & 1) res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}

使用:
-qpow(a, b) <a的b次方>
-smul(a, b) <a乘b>

1234567891011121314151617181920212223242526272829303132
```

### (3) 欧几里得算法 (gcd, exgcd)

```cpp
using i64 = long long;

//朴素gcd
i64 gcd(i64 a, i64 b)
{
	return b ? gcd(b, a % b) : a;
}

//exgcd
i64 x, i64 y;
i64 exgcd(i64 a, i64 b, i64& x, i64& y)
{
	i64 res;
	if (!b) { x = 1, y = 0; return a; }
	else res = exgcd(b, a % b, y, x), y -= a / b * x;
	return res;
}

使用:
朴素gcd: 
-gcd(a, b)

exgcd求逆元:
-exgcd(a, mod, x, y), x = (x % mod + mod) % mod

12345678910111213141516171819202122232425
```

* * *

### (4) jiangly的模板元板子

```cpp
constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};


1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950515253545556575859606162636465666768697071727374757677787980818283
```

* * *

### (5) jiangly的组合数板子

```cpp

using i64 = long long;
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % P)} {}
    
    constexpr int norm(int x) const {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr MInt &operator*=(MInt rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 998244353;
using Z = MInt<P>;
 
struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100101102103104105106107108109110111112113114115116117118119120121122123124125126127128129130131132133134135136137138139140141142143144145146147
```

* * *

### (6) ygg的组合数板子

```cpp

using i64 = long long;
const int mod = 1e9 + 7;
struct Comb {
    const int N;
    vector<i64> fac, invfac;
    Comb(int n) : N(n), fac(n + 2), invfac(n + 2) { init(); };
    i64 qpow(i64 x, i64 p) {
        i64 res = 1 % mod; x %= mod;
        for (; p; p >>= 1, x = x * x % mod)
            if (p & 1) res = res * x % mod;
        return res;
    }
    i64 inv(i64 x) { return qpow(x, mod - 2); };
    void init() {
        fac[0] = 1;
        for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i % mod;
        invfac[N] = inv(fac[N]);
        for (int i = N - 1; i >= 0; --i) invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
    }
    i64 C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
    }
    i64 A(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac[n] * invfac[n - m] % mod;
    }
};

123456789101112131415161718192021222324252627282930
```

* * *

* * *

# 4.数据结构

### (1) [单调队列](https://so.csdn.net/so/search?q=%E5%8D%95%E8%B0%83%E9%98%9F%E5%88%97&spm=1001.2101.3001.7020) (单调递减，递增)

```cpp
void solve()
{
	int n, k;//n为数组长度 k为区间长度
	vector<int> arr(n), q(n);//arr为元素 q为单调队列
	
	int hh = 0, tt = -1;//hh为队头指针 tt为队尾指针
	for (int i = 0; i < n; ++i)
	{
		while (hh <= tt && q[hh] + k <= i) ++hh;//判断过期
		while (hh <= tt && arr[i] <= arr[q[tt]]) --tt;//对递减:弹出不满足元素
		//while (hh <= tt && arr[i] >= arr[q[tt]]) --tt;//对递增:弹出不满足元素
		q[++tt] = i;//更新队尾 存下标
		if (i >= k - 1) //操作
	}
}

使用:
如 solve() 函数所示

12345678910111213141516171819
```

* * *

### (2) 树状数组（前缀和，差分）

```cpp
using i64 = long long;
int tree[N], n;//tree存树 n为数组下标

int lowbit(int x)
{
	return x & -x;
}

i64 qry(int x)//查询闭区间 [1,x] 的前缀和
{
	i64 res = 0;
	for (int i = x; i > 0; i -= lowbit(i)) 
		res += tree[i];
	return res;
}

void upd(int l, int z)//向闭区间 [l,n] 加上数值 z
{
	for (int i = l; i <= n; i += lowbit(i))
		tree[i] += z;
}

void solve()
{
    //构造前缀和树状数组
    for (int i = 1, z; i <= n; ++i)
    {
        cin >> z;
        upd(i, z);
    }
    //构造差分树状数组
    for (int i = 1, num, last = 0; i <= n; ++i)
    {
        cin >> num;
        upd(i, num - last);
        last = num;
    }
    //用已有数组构造
    for (int i = 1, num, last = 0; i <= n; ++i)
    {
    	upd(i, arr[i]);//前缀和
    	upd(i, arr[i] - arr[i - 1])//差分
    }
}

使用: 
前缀和树状数组:
-upd(i, z) <使区间 [i,n] 加上 z>
-qry(y) - qry(x - 1) <查询[x,y]的区间和>

差分树状数组:
-upd(x, z), upd(y + 1, -z) <同时使用，使区间 [x,y] 每个数都加上 z>
-qry(x) <查询数组下标为 x 的值>

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354
```

* * *

* * *

### (3) 线段树（维护区间和模板）

```cpp
using i64 = long long;

#define lson k << 1, l, mid//宏定义减少代码量
#define rson k << 1 | 1, mid + 1, r
i64 seg[N << 2], lazy[N << 2];//四倍空间

void pushdown(int k, int l, int r)
{
	//左儿子有mid - l + 1个元素 右儿子有 r - mid个元素
	//lt为左儿子下标 rt为右儿子下标
	int mid = l + r >> 1, lt = k << 1, rt = k << 1 | 1;
	seg[lt] += lazy[k] * (mid - l + 1), seg[rt] += lazy[k] * (r - mid);//更新seg
	lazy[lt] += lazy[k], lazy[rt] += lazy[k], lazy[k] = 0;//更新懒标记
}

void build(int k, int l, int r)//构建线段树
{
	lazy[k] = 0;
	if (l == r) return void(cin >> seg[k]);//直接构建
	//if (l == r) return void(seg[k] = arr[l]);用已有数组构建
	//if (l == r) return void (seg[k] = arr[id[l]]);重链剖分建树
	int mid = l + r >> 1;
	build(lson), build(rson);
	seg[k] = seg[k << 1] + seg[k << 1 | 1];
}

void upd(int k, int l, int r, int x, int y, i64 z)//用 z 更新闭区间[x, y]
{
	if (l >= x && r <= y)
	{
		lazy[k] = lazy[k] + z;
		seg[k] += z * (r - l + 1);
		return;
	}
	int mid = l + r >> 1;
	if (lazy[k]) pushdown(k, l, r);
	if (x <= mid) upd(lson, x, y, z);
	if (y > mid) upd(rson, x, y, z);
	seg[k] = seg[k << 1] + seg[k << 1 | 1];
}

i64 qry(int k, int l, int r, int x, int y)//查询闭区间[x, y]
{
	if (l >= x && r <= y) return seg[k];
	if (lazy[k]) pushdown(k, l, r);
	int mid = l + r >> 1;
	i64 res = 0;
	if (x <= mid) res += qry(lson, x, y);
	if (y > mid) res += qry(rson, x, y);
	return res;
}

使用: 
*build(1, 1, n) (建树)

-upd(1, 1, n, x, y, z) (如上)
-qry(1, 1, n, x, y) (如上)

前三个1, 1, n为固定输入 n为数组最后一个元素下标 数组区间严格为[1, n]
后三个x y z分别代表区间 [x,y] 和 增添修改的值(查询时不用z)

12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849505152535455565758596061
```

* * *

### (4) 重链剖分（维护树结构）

```cpp
int siz[N], dep[N], son[N], fa[N];//dfs1相关
//siz 以该节点为树的大小 dep节点的深度 son节点的重儿子 fa节点的父亲
int dfn[N], id[N], top[N], cnt;//dfs2相关
//dfn 剖分序 id建树回溯原下标 top节点的重链头 cnt维护dfn序

inline void dfs1(int u, int ufa)//跑dfs1相关 预处理dfs2
{
	siz[u] = 1, dep[u] = dep[ufa] + 1, fa[u] = ufa;
	for (auto& x : g[u])
	{
		if (x == ufa) continue;
		dfs1(x, u), siz[u] += siz[x];
		if (siz[x] > siz[son[u]]) son[u] = x;
	}
}

inline void dfs2(int u, int tp)//跑dfn序
{
	top[u] = tp, id[++cnt] = u, dfn[u] = cnt;
	if (son[u]) dfs2(son[u], tp);
	for (auto& x : g[u])
		if (x == fa[u] || x == son[u]) continue;
		else dfs2(x, x);
}

void updlink(int x, int y, i64 z)//对节点x->y的最短链上每个节点都加上z
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		upd(1, 1, n, dfn[top[x]], dfn[x], z);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	upd(1, 1, n, dfn[x], dfn[y], z);
}

i64 qrylink(int x, int y)//询问节点x->y的最短链上每个节点的和
{
	i64 res = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		res += qry(1, 1, n, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	res += qry(1, 1, n, dfn[x], dfn[y])
	return res;
}

使用: 给出树上两点(x, y) 和 根(root)
*build(1, 1, n) <预处理线段树 建树如线段树所示>
*dfs1(root, 0), dfs2(root, root) <剖分 root为根>

-updlink(x, y, z) <给 x 到 y 最短链上的所有节点加上 z>
-qrylink(x, y) <查询从 x 到 y 最短链上所有节点的和>
-upd(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, z) <给以节点x为根的子树都加上z>
-qry(1, 1, n, dfn[x], dfn[x] + siz[x] - 1) <查询以节点x为根的子树上所有节点的和>

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960
```

### (5) 分块（维护区间和模板）

```cpp

using i64 = long long;
i64 arr[N], n;//arr是原数组 n是数组长度
// len 块长 tot 块数;
i64 len, tot;
// sum 单块的和
// lt,rt 这个块的左右下标
// pos 数组下标 [i] 所在的块编号
// lazy 懒标记
i64 sum[M], lt[M], rt[M], lazy[M], pos[N];

void build()
{
    len = (i64)sqrt(n), tot = (n - 1) / len + 1;
    // 处理区间left block, right block下标
    for (int i = 1; i <= tot; ++i) lt[i] = rt[i - 1] + 1, rt[i] = i * len;
    rt[tot] = n;// 末端特判
    for (int i = 1; i <= tot; ++i)//初始化tot个块
        for (int j = lt[i]; j <= rt[i]; ++j)
            pos[j] = i, sum[i] += arr[j];
}

void upd(int x, int y, i64 z)// 对区间[x, y] 加上值z
{
    int lb = pos[x], rb = pos[y];//lb rb 代表左右两块的编号
    if (lb == rb)// 区间[x, y]在同块内时
    {
        for (int i = x; i <= y; ++i) arr[i] += z, sum[lb] += z;
        return;
    }
    for (int i = lb + 1; i <= rb - 1; ++i) sum[i] += len * z, lazy[i] += z;//更新[x, y]中间的整块 和 懒标记
    for (int i = x; i <= rt[lb]; ++i) arr[i] += z, sum[lb] += z;//补上小段[x , rt[lb]]
    for (int i = y; i >= lt[rb]; --i) arr[i] += z, sum[rb] += z;//补上小段[lt[rb] , y]
}

i64 qry(int x, int y)//查询 [x, y] 区间的和
{
    int lb = pos[x], rb = pos[y]; i64 res = 0;
    if (lb == rb)// 区间[x, y]在同块内时
    {
        for (int i = x; i <= y; ++i) res += arr[i] + lazy[lb];
        return res;
    }
    for (int i = lb + 1; i <= rb - 1; ++i) res += sum[i];// 区间[x, y]中间的整块
    for (int i = x; i <= rt[lb]; ++i) res += arr[i] + lazy[lb];//补上小段[x , rt[lb]]
    for (int i = y; i >= lt[rb]; --i) res += arr[i] + lazy[rb];//补上小段[lt[rb] , y]
    return res;
}



使用: 给出区间[x, y]
*build() <预处理分块>

-upd(x, y, z) <将[x, y]上的数字都加上z>
-qry(x, y) <查询[x, y]的区间和>

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657
```

### (6) [并查集](https://so.csdn.net/so/search?q=%E5%B9%B6%E6%9F%A5%E9%9B%86&spm=1001.2101.3001.7020)

```cpp

int fa[N], siz[N];//fa是父亲 siz是所在并查集大小

int find(int x)//查询父节点
{
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}
//查询 x 所在并查集大小
int size(int x) { return siz[find(x)]; }
//查询是否在同一区间 
bool same(int x, int y) { return find(x) == find(y); }

bool merge(int x, int y)//合并 x 和 y 所在并查集
{
    x = find(x), y = find(y);
    if (x == y) return false;
    siz[x] += siz[y];
    fa[y] = x;
    return true;
}

使用: 给出两点 (x, y)
*for(int i = 1; i <= n; ++i) siz[i] = 1, fa[i] = i; <预处理并查集>

-find(x) <查询 x 节点的父亲>
-size(x) <查询 x 节点所在并查集大小>
-same(x, y) <查询 x 节点和 y 节点是否在同一并查集内>
-merge(x, y) <合并 x 节点和 y 节点的并查集>

123456789101112131415161718192021222324252627282930
```

* * *

### (7) 可持久化线段树（维护区间和）

```cpp

using i64 = long long;

const int N = 4e6 + 5, M = 1e5 + 5;

//seg是树的值 ls是左儿子 rs是右儿子 lazy是懒标记
//lson rson 用来优化代码量
#define seg(x) tree[x].val
#define ls(x) tree[x].l
#define rs(x) tree[x].r
#define lson(x) tree[x].l, l, mid
#define rson(x) tree[x].r, mid + 1, r
#define lazy(x) tree[x].lazy

//ver代表着每一次修改的根节点下标 idx辅助开点
int ver[M], idx, n, m;

struct Segtree {
    i64 val;
    int l, r, lazy;
}tree[N];

void build(int k, int l, int r) {
    seg(k) = lazy(k) = 0;//多测清空
    if (l == r) return void(cin >> seg(k));//构建方式可参考线段树
    int mid = l + r >> 1;
    //动态开点确保空间复杂度
    ls(k) = ++idx, rs(k) = ++idx;
    build(lson(k)), build(rson(k));
    seg(k) = seg(ls(k)) + seg(rs(k));
}

//pre代表着历史版本
void upd(int pre, int k, int l, int r, int x, int y, int z) {
    tree[k] = tree[pre];//先让其等于历史值
    if (l >= x && r <= y) {
        lazy(k) += z;
        seg(k) += z * (r - l + 1);
        return;
    }
    int mid = l + r >> 1;
    //在修改的同时动态开点
    if (x <= mid) ls(k) = ++idx, upd(ls(pre), lson(k), x, y, z);
    if (y > mid) rs(k) = ++idx, upd(rs(pre), rson(k), x, y, z);
    seg(k) = seg(ls(k)) + seg(rs(k)) + lazy(k) * (r - l + 1);//注意同时加上懒标记
}

//因为空间大小原因不可下放标记 利用永久化标记 mark 辅助查询
i64 qry(int k, int l, int r, int x, int y, i64 mark) {
    if (l >= x && r <= y) return seg(k) + (r - l + 1) * mark;
    int mid = l + r >> 1;
    i64 res = 0;
    if (x <= mid) res += qry(lson(k), x, y, mark + lazy(k));
    if (y > mid) res += qry(rson(k), x, y, mark + lazy(k));
    return res;
}

void solve() {

    cin >> n >> m;

    idx = 0;
    ver[0] = ++idx;
    build(ver[0], 1, n);

    char op; int x, y, z, now = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> op;
        if (op == 'C') {
            cin >> x >> y >> z;
            ver[++now] = ++idx;
            upd(ver[now - 1], ver[now], 1, n, x, y, z);
        }
        else if (op == 'Q') {
            cin >> x >> y;
            cout << qry(ver[now], 1, n, x, y, 0) << '\n';
        }
        else if (op == 'H') {
            cin >> x >> y >> z;
            cout << qry(ver[z], 1, n, x, y, 0) << '\n';
        }
        else if (op == 'B'){
            cin >> now;
        }
    }
}


使用：给出一个区间 <[x, y]> 和 <历史版本z> 或 <修改值z>

<预处理线段树，版本从 0 开始>
*idx = 0, ver[0] = ++idx，build(ver[now], 1, n) 

<使当前版本的区间 [x, y] 同时加上一个值 z ，并更新当前版本> (Change)
-ver[++now] = ++idx <更新版本>
-upd(ver[now - 1], ver[now], 1, n, x, y, z); 

<查询当前版本区间 [x, y] 的数字的和> (Query)
-qry(ver[now], 1, n, x, y, 0)

<查询第 z 次修改的版本区间 [x, y] 的数字的和> (History)
-qry(ver[z], 1, n, x, y, 0)

<将当前版本回溯至第 z 次修改的版本> (Back)
-now = z

以上四种操作分别对应 solve() 中: op = C, Q, H, B。
单次修改需要的空间开销很大，请不要吝啬空间，能开多大则开多大。
<除动态开点及宏定义外，其他内容与线段树结构相似>

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100101102103104105106107108109110
```

* * *

### (8) 珂朵莉树（ODT）

```cpp

using i64 = long long;

struct Node {
    i64 l, r;
    mutable i64 v;
    Node(i64 l, i64 r, i64 v) : l(l), r(r), v(v) {}
    bool operator<(const Node& t) const { return l < t.l; };
};

set<Node> ODT;
//拆分区间操作 <ODT核心>
set<Node>::iterator split(i64 pos) {
    auto it = ODT.lower_bound(Node(pos, 0, 0));
    if (it != ODT.end() && it->l == pos) return it;
    i64 l = (--it)->l, r = it->r, v = it->v;
    ODT.erase(it);
    ODT.emplace(l, pos - 1, v);
    return ODT.emplace(pos, r, v).first;
}
//区间赋值操作
void assign(i64 l, i64 r, i64 v) {
    auto end = split(r + 1), begin = split(l);
    ODT.erase(begin, end);
    ODT.emplace(l, r, v);
}
//区间加
void add(i64 l, i64 r, i64 v) {
    auto end = split(r + 1);
    for (auto it = split(l); it != end; ++it)
        it->v += v;
}
//快速幂模板
i64 qpow(i64 a, i64 b, i64 Mod) {
    i64 res = 1 % Mod; a %= Mod;
    for (; b; b >>= 1, a = a * a % Mod)
        if (b & 1) res = res * a % Mod;
    return res;
}
//区间平方和
i64 rangepow(i64 l, i64 r, i64 x, i64 y) {
    i64 res = 0;
    auto end = split(r + 1);
    for (auto it = split(l); it != end; ++it)
        res = (res + qpow(it->v, x, y) * (it->r - it->l + 1)) % y;
    return res;
}
//区间第k小数
i64 kth(i64 l, i64 r, i64 k) {
    auto end = split(r + 1);
    vector<pair<i64, i64>> rnk;
    for (auto it = split(l); it != end; ++it)
        rnk.emplace_back(it->v, it->r - it->l + 1);
    sort(rnk.begin(), rnk.end());
    int rnksz = rnk.size();
    for (int i = 0; i < rnksz; ++i) {
        k -= rnk[i].second;
        if (k <= 0) return rnk[i].first;
    }
    return -1;
}


使用: 给出数组 <arr>，区间 <[l, r]>，<数字x> 和 <模数y>

*利用for循环插入数组中的每一个点 <预处理>
	for (int i = 1; i <= n; ++i) {
	    ODT.emplace(i, i, arr[i]);
	}

-assign(l, r, x) <将闭区间 [l, r] 内所有数字改为 x>
-add(l, r, x) <将闭区间 [l, r] 内所有数字加上 x>
-kth(l, r, x) <求出闭区间 [l, r] 内第 x 小的数字>
-rangepow(l, r, x, y) <求出闭区间 [l, r] 内所有数字在模 y 下的 x 次方之和>

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475
```

* * *

### (9) 莫队模板

```cpp

i64 tot;//每一块的长度
struct Ask {
    int l, r, id;
    bool operator<(const Ask& t) const {
        if (l / tot != t.l / tot) return l < t.l;
        if (l / tot & 1) return r > t.r;
        return r < t.r;
    }
};

void solve() {

    int n, q;
    cin >> n >> q;

    tot = n / sqrtl(n);//算出块长

    vector<int> ans(q);//答案
    vector<Ask> ask(q);//离线
    sort(ask.begin(), ask.end());

    int cur = 0;//当前的答案贡献
    auto add = [&](int pos) {
        //加入的贡献
    };

    auto del = [&](int pos) {
        //删除的贡献
    };

    int i = 1, j = 0;
    for (int now = 0; now < q; ++now) {
        int l = ask[now].l, r = ask[now].r, id = ask[now].id;
        while (i > l) add(--i);
        while (j < r) add(++j);
        while (i < l) del(i++);
        while (j > r) del(j--);
        ans[id] = cur;//等于答案贡献
    }
    //多测清空
    while (j < n) add(++j);
    while (i <= n) del(i++);

}


1234567891011121314151617181920212223242526272829303132333435363738394041424344454647
```

* * *

### (10) 主席树模板（静态查询区间第 k 小）

```cpp

const int N = 2e5 + 10;//数组长度

int idx;
struct Segtree {
    int cnt, l, r;
}tree[N << 5];//32倍空间

//宏定义减少代码量
#define seg(k) tree[k].cnt
#define ls(k) tree[k].l
#define rs(k) tree[k].r
#define lson(k) tree[k].l, l, mid
#define rson(k) tree[k].r, mid + 1, r

//创建新节点
int creat(int pre) {
    tree[++idx] = tree[pre];
    return idx;
}

//更新版本
int upd(int& pre, int l, int r, int x, int y) {
    int cur = creat(pre);
    if (l >= x && r <= y) {
        ++seg(cur);
        return cur;
    }
    int mid = l + r >> 1;
    if (x <= mid) ls(cur) = upd(ls(pre), l, mid, x, y);
    if (y > mid) rs(cur) = upd(rs(pre), mid + 1, r, x, y);
    seg(cur) = seg(ls(cur)) + seg(rs(cur));
    return cur;
}

//区间第 k 小
int kth_small(int& pre, int& k, int l, int r, int rnk) {
    if (l == r) return l;
    int mid = l + r >> 1, cnt = seg(ls(k)) - seg(ls(pre));
    if (rnk <= cnt) return kth_small(ls(pre), lson(k), rnk);
    else return kth_small(rs(pre), rson(k), rnk - cnt);
}

//区间第 k 大
int kth_big(int& pre, int& k, int l, int r, int rnk) {
    if (l == r) return l;
    int mid = l + r >> 1, cnt = seg(rs(k)) - seg(rs(pre));
    if (rnk <= cnt) return kth_big(rs(pre), rson(k), rnk);
    else return kth_big(ls(pre), lson(k), rnk - cnt);
}

void solve() {

    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        b[i] = arr[i];
    }

    //离散化下标
    b[0] = INT32_MIN;//初始化为负无穷 便于离散化下标从 1 开始
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int len = b.size() - 1;

    //版本数组
    vector<int> ver(n + 1);

    //把每一个版本记录下来
    for (int i = 1; i <= n; ++i) {
        int pos = lower_bound(b.begin(), b.end(), arr[i]) - b.begin();
        //更新版本
        ver[i] = upd(ver[i - 1], 1, len, pos, pos);
    }

    int l, r, k;
    for (int i = 1; i <= m; ++i) {
        cin >> l >> r >> k;
        //获得第 k 小的数字离散化的下标
        int pos = kth_small(ver[l - 1], ver[r], 1, len, k);

        //输出第 k 小数
        cout << b[pos] << '\n';
    }
}


使用: 给出数组 <arr>，区间 <[l, r]>，<数字k>

如 solve() 函数所示

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293
```

* * *

* * *

# 5.图论

### (1) Dijkstra （堆优化）

```cpp
using i64 = long long;
using PII = pair<i64, int>;
vector<int> dist(N, inf);
int h[N], ne[N], w[N], e[N], idx;//h 初始化为0
//ne下一个点 w边权 e该点 idx索引
bool vis[N];

void dijkstra()
{
	//s为起点
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0, s });
	dist[s] = 0;
	
	while (heap.size())
	{
		auto [dis, u] = heap.top(); heap.pop();
		if (vis[t.y]) continue;
		vis[t.y] = true;
		for (int i = h[u]; i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dis + w[i])
				dist[j] = dis + w[i],
				heap.push({ dist[j], j });
		}
	}
}

使用: 
*dijkstra() <最短路>

-dist[idx]

12345678910111213141516171819202122232425262728293031323334
```

* * *

### (2) Spfa

#### \- 朴素

```cpp

vector<int> dist(N, inf);
int h[N], ne[N], w[N], e[N], idx;
//ne下一个点 w边权 e该点 idx索引
bool vis[N];

bool spfa()
{
	//s为起点
	queue<int> que;
	que.push(s);
	dist[s] = 0;

	while (que.size())
	{
		int t = que.front(); que.pop();
		visit[t] = false;
		for (int i = h[t]; i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				//cnt[j] = cnt[t] + 1;判负环
				//if (cnt[j] > n) return true;
				if (!visit[j]) 
					que.push(j),
					visit[j] = true;
			}
		}
	}
	//return false;判负环
}

使用:
*spfa() <最短路>

-if(spfa()) <判负环>
-dist[idx]

12345678910111213141516171819202122232425262728293031323334353637383940
```

#### \- SLF优化

```cpp

//Small Label First
bool spfa()
{
    //s为起点
    deque<int> deq;//改为双端队列
    deq.push_back(s);
    dist[s] = 0;

    while (deq.size())
    {
        int t = deq.front(); deq.pop_front();
        visit[t] = false;
        for (int u = h[t]; u; u = ne[u])
        {
            int v = e[u];
            if (dist[v] > dist[t] + w[u])
            {
                dist[v] = dist[t] + w[u];
                //cnt[v] = cnt[t] + 1;判负环
                //if (cnt[v] > n) return true;
                if (!visit[v])
                {
                    //SLF优化：比队头距离小就放入队头 否则队尾
                    if (deq.size() && dist[v] < dist[deq.front()])
                        deq.push_front(v);
                    else
                        deq.push_back(v);
                    //---
                    visit[v] = true;
                }
            }
        }
    }
    //return false;判负环
}

使用:
*spfa() <最短路>

-if(spfa()) <判负环>
-dist[idx]

12345678910111213141516171819202122232425262728293031323334353637383940414243
```

#### \- LLL优化

```cpp

//Large Label Last
bool spfa()
{
    //s为起点
    queue<int> que;
    que.push(s);
    dist[s] = 0;
    i64 sum = 0, num = 1;//多创建两个变量维护

    while (que.size())
    {
        int t = que.front();
        // LLL优化：队头要是比对内平均值大 先放后面 否则出队
        while (dist[t] * num > sum)
        {
            que.pop();
            que.push(t);
            t = que.front();
        }
        que.pop();
        sum -= dist[t], --num;
        //---
        visit[t] = false;
        for (int u = h[t]; u; u = ne[u])
        {
            int v = e[u];
            if (dist[v] > dist[t] + w[u])
            {
                dist[v] = dist[t] + w[u];
                //cnt[v] = cnt[t] + 1;判负环
                //if (cnt[v] > n) return true;
                if (!visit[v])
                {
                    que.push(v);
                    visit[v] = true;
                    sum += dist[v], ++num;//注意补上入队值
                }
            }
        }
    }
    //return false;判负环
}

使用:
*spfa() <最短路>

-if(spfa()) <判负环>
-dist[idx]

1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950
```

#### \- SLF + LLL 优化

```cpp

//Small Label First & Large Label Last
bool spfa()//老老实实用SLF好像会比SLF+LLL快
{

    deque<int> que;
    que.push_back(s);
    dist[s] = 0;
    i64 sum = dist[s], num = 1;//LLL

    while (que.size())
    {
        auto t = que.front();

        while (dist[t] * num > sum) //LLL
        {
            que.pop_front();
            que.push_back(u);
            t = que.front();
        }
        sum -= dist[t], --num;
        que.pop_front();

        visit[t] = false;
        for (int u = h[t]; u; u = ne[u])
        {
            int v = e[u];
            if (dist[v] > dist[t] + w[u])
            {
                dist[v] = dist[u] + w[u];
                //cnt[v] = cnt[t] + 1;判负环
                //if (cnt[v] > n) return true;
                if (!visit[v])
                {
                    visit[v] = true;
                    if (que.size() && dist[que.front()] > dist[v])//SLF
                        que.push_front(v);
                    else
                        que.push_back(v);
                    sum += dist[v], ++num;//LLL
                }
            }
        }
    }
    //return false;判负环
}

1234567891011121314151617181920212223242526272829303132333435363738394041424344454647
```

* * *

### (3) Kruskal最小生成树

```cpp

int n, fa[N];
//n节点数 fa并查集
struct node
{
	int u, v, w;//u点 v邻点 w边权
	bool operator < (const node& other) const {
		return w < other.w;
	}
}g[M];//存图

int find(int x)
{
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

bool kruskal()
{
	sort(g, g + m);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	//res是树的大小 cnt是节点数
	int res = 0, cnt = 0;
	for (auto t : g)
	{
		int a = find(t.u), b = find(t.v);
		if (a != b)
		{
			fa[a] = b;
			res += t.w;
			++cnt;
		}
	}
	if (cnt < n - 1) return false;//判图是否联通
	return true;
}

使用:
*kruskal() <处理生成树>

-if(kruskal()) <判联通图>
-res

12345678910111213141516171819202122232425262728293031323334353637383940414243
```

* * *

### (4) 最近公共祖先[LCA](https://so.csdn.net/so/search?q=LCA&spm=1001.2101.3001.7020) (倍增，重链剖分)

#### \- 倍增

```cpp
int h[N], e[N << 1], ne[N << 1], idx, root;
int d[N], pre[N][21];//d为深度 pre为倍增预处理

inline void getpre(int u, int fa)//递归处理pre
{
	d[u] = d[fa] + 1;
	pre[u][0] = fa;
	for (int i = 1; (1 << i) <= d[u]; ++i)
		pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (int i = h[u]; i; i = ne[i])
		if (!d[e[i]]) getpre(e[i], u);
}

int lca(int a, int b)//查询lca
{
	if (d[a] > d[b]) swap(a, b);
	for (int i = 20; ~i; --i)
		if (d[a] <= d[b] - (1 << i)) b = pre[b][i];
	if (a == b) return a;
	for (int i = 20; ~i; --i)
		if (pre[a][i] != pre[b][i])
			a = pre[a][i], b = pre[b][i];
	return pre[a][0];
}

使用: 
*getpre(root, 0) <初始化 root为根>

-lca(a, b)

123456789101112131415161718192021222324252627282930
```

#### \- 重链剖分

```cpp
vector<int> g[N]//vector存图
int dep[N], siz[N], son[N], fa[N], root;//dfs1相关
int top[N];//dfs2相关

inline void dfs1(int u, int ufa)//
{
	siz[u] = 1, dep[u] = dep[ufa] + 1, fa[u] = ufa;
	for (auto& x : g[u])
	{
		if (x == ufa) continue;
		dfs1(x, u), siz[u] += siz[x];
		if (siz[x] > siz[son[u]]) son[u] = x;
	}
}

inline void dfs2(int u, int tp)
{
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (auto& x : g[u])
		if (x == fa[u] || x == son[u]) continue;
		else dfs2(x, x);
}

int lca(int x, int y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}


使用: 给出两个点(x, y)
*dfs1(root, 0), dfs2(root, root) <预处理 root为根>

-lca(x, y)

1234567891011121314151617181920212223242526272829303132333435363738394041
```

* * *

### (5) 求树的重心

```cpp
int cnt[N], mx[N], cent[2], n;
//cnt代表以u为节点不包含父上级的节点数
//mx代表以u为节点包含父上级的最大重量
//cnt存两个重心
inline void getcent(int u, int fa)
{
	cnt[u] = 1, mx[u] = 0;
	for (auto& x : g[u])
		if (x != fa)
			getcent(x, u),
			cnt[u] += cnt[x],
			mx[u] = max(mx[u], cnt[x]);
	mx[u] = max(mx[u], n - cnt[u]);
	if (mx[u] <= n / 2)
		cent[cent[0] != 0] = u;
}

使用: 
*getcent(1, -1) <初始化>

-cent[0], cent[1] <两个重心>

12345678910111213141516171819202122
```

* * *

### (6) Johnson全源最短路

```cpp
using i64 = long long;
using PII = pair<int, int>;

//dist为正图的最短路 一维为起点 二维为终点
vector<vector<i64>> dist(N, vector<i64>(N, 0x3f3f3f3f));
vector<i64> d(N, 0x3f3f3f3f);//势能
vector<PII> g[N];//存图
int cnt[N], n, m;//n为点数 m为边数
bool vis[N];

bool spfa()//跑虚拟图
{
	queue<int> que;
	que.push(0);
	d[0] = 0;
	while (que.size())
	{   
		//t为当前点
		auto t = que.front(); que.pop();
		vis[t] = false;
		//u为邻点 w为边权
		for (auto& [u, w] : g[t])
			if (d[u] > d[t] + w)
			{
				d[u] = d[t] + w;
				cnt[u] = cnt[t] + 1;//判负环
				if (cnt[u] > n) return true;
				if (!vis[u])
					que.push(u),
					vis[u] = true;
			}
	}
	return false;
}

void dijkstra(int s)//以s为起点跑最短路
{
	for (int i = 0; i <= n; ++i) vis[i] = false;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0, s });
	dist[s][s] = 0;

	while (heap.size())
	{
		//dist为当前点距离 t为点标号
		auto [dis, t] = heap.top(); heap.pop();
		
		if (vis[t]) continue;
		vis[t] = true;
		//u为邻点 w为边权
		for (auto& [u, w] : g[t])
			if (dist[s][u] > dis + w)
				dist[s][u] = dis + w,
				heap.push({ dist[s][u], u });
	}
}

void solve()
{
	for (int i = 0, x, y, z; i < m; ++i)
	{
		cin >> x >> y >> z;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}
	
	for (int i = 1; i <= n; ++i) //建势能图
		g[0].emplace_back(i, 0);
	
	if (spfa())//跑势能图+判负环
		return void(cout << -1 << '\n');
		
	for (int i = 1; i <= n; ++i)//重定义边权
		for(auto& [u, w] : g[i]) 
			w += d[i] - d[u];//i为起点 u为终点
	//跑n次dijkstra
	for (int i = 1; i <= n; ++i)
		dijkstra(i);

	for (int i = 1; i <= n; ++i)//输出正确的最短路
		for (int j = 1; j <= n; ++j)
			cout << dist[i][j] + d[j] - d[i] << " \n"[j == n];
}

使用: 
如 solve() 函数所示

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687
```

* * *

### (7) 匈牙利算法 (二分图匹配)

```cpp

const int N = 2e5 + 10;
int rmatch[N], n, res = 0;//rmatch存右部匹配的左部点
vector<int> g[N];//存图
queue<int> que;//辅助清空vis
bool vis[N];

bool match(int u)
{
    for (auto& x : g[u])
    {
        if (vis[x]) continue;
        vis[x] = true, que.push(x);
        //右部没匹配 或者存在增广路则更新
        if (rmatch[x] == 0 || match(rmatch[x]))
        {
            rmatch[x] = u;
            return true;
        }
    }
    return false;
}

void hangarian()
{
    for (int i = 1; i <= n; ++i)//n是左部的点数
    {
        while (que.size()) //清空vis
            vis[que.front()] = false, que.pop();
        if (match(i)) ++res;
    }
}


使用: 
-hangarian()
-res <最大匹配数/最小点覆盖>

1234567891011121314151617181920212223242526272829303132333435363738
```

* * *

### (8) Tarjan

#### \- 缩点 / 强连通分量

```cpp

vector<int> g[N], g2[N];//g是原图 g2是缩点图
stack<int> stk;
//low是能到达的最小dfn节点 scc是点所在强连通分量 cscc是强连通分量数
int dfn[N], low[N], scc[N], cnt, cscc, n;
//instk 点是否在栈内
bool instk[N];

void tarjan(int u)
{
	low[u] = dfn[u] = ++cnt;
	instk[u] = true;
	stk.push(u);//访问时进栈
	for (auto& x : g[u])
		if (!dfn[x])//未访问则递归继续访问
		{
			tarjan(x);
			low[u] = min(low[u], low[x]);
		}
		else if (instk[x])//访问过 且 u 可达 x
			low[u] = min(low[u], dfn[x]);
	if (low[u] == dfn[u])//记录强连通分量
	{
		++cscc;
		int top;
		do
		{
			top = stk.top();//记录时出栈
			stk.pop();
			instk[top] = false;
			scc[top] = cscc;//记录该点的强连通分量
		} while (top != u);
	}
}

void solve()
{
	//原图不一定联通 对每个未访问的点都跑一次 Tarjan
	for(int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
		
	//将强连通分量缩为一点
	for (int u = 1; u <= n; ++u)
		for (auto& x : g[u])
			if (scc[u] != scc[x])//不归属一连通分量内
				g2[scc[u]].emplace_back(scc[x]);

}

使用: 如 solve() 函数所示

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051
```

#### \- 割点 / 割顶

```cpp

vector<int> g[N];
vector<int> cut;//cut 存割点

int low[N], dfn[N], cnt, n;

void tarjan(int u, bool root = true)//root 判是否是根
{
	int tot = 0;
	dfn[u] = low[u] = ++cnt;
	for (auto& x : g[u])
	{
		if (!dfn[x])
		{
			tarjan(x, false);
			low[u] = min(low[u], low[x]);
			tot += (low[x] >= dfn[u]);//统计满足条件的子节点
		}
		else
			low[u] = min(low[u], dfn[x]);
	}
	if (tot > root)//是根则需大于1 否则大于0
		cut.emplace_back(u);
}

void solve()
{
	//原图不一定联通 对每个未访问的点都跑一次 Tarjan
	for(int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
}

使用: 如 solve() 函数所示

-cut[x]

123456789101112131415161718192021222324252627282930313233343536
```

#### \- 桥

```cpp

using PII = pair<int, int>;

vector<PII> bridge;//存 桥
vector<int> g[N];

//此时low跑前向边时不包括fa <-> u的边
int low[N], dfn[N], fa[N], cnt, n;

void tarjan(int u)
{
	int tot = 0;
	dfn[u] = low[u] = ++cnt;
	for (auto& x : g[u])
	{
		if (!dfn[x])
		{
			fa[x] = u;//额外记录点的父亲
			tarjan(x);
			low[u] = min(low[u], low[x]);
			if (low[x] > dfn[u])
				bridge.emplace_back(u, x);
		}
		else if(fa[u] != x) //不包括父亲节点时
			low[u] = min(low[u], dfn[x]);
	}
}

void solve()
{
	//原图不一定联通 对每个未访问的点都跑一次 Tarjan
	for(int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
}

使用: 如 solve() 函数所示

-bridge[x]

123456789101112131415161718192021222324252627282930313233343536373839
```

#### \- 点双连通分量

```cpp

const int N = 5e5 + 10, M = 2e6 + 10;

int h[N], e[M << 1], ne[M << 1], idx;

void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

//root：根  id：辅助dfn和low  dcc：点双数目
int dfn[N], low[N], root, id, dcc;
vector<int> vDCC[N];//存每个点双的点
stack<int> stk;//和普通tarjan同
bool cut[N];//存割点，可用set

void tarjan(int u) {
    dfn[u] = low[u] = ++id;
    stk.push(u);
    int cnt = 0;

    for (int i = h[u]; i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);

            if (dfn[u] <= low[v]) {
                ++cnt;
                if (u != root || cnt > 1) {
                    cut[u] = true;//判割点
                }
                ++dcc;//边双数量+1
                int top;
                do {
                    top = stk.top(); stk.pop();
                    vDCC[dcc].emplace_back(top);//栈内节点
                } while (top != v);
                vDCC[dcc].emplace_back(u);//当前节点也是
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    //孤立点特判
    if (u == root && cnt == 0) {
        cut[u] = true;
        vDCC[++dcc].emplace_back(u);
        return;
    }
}

void solve() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }

	//原图不一定联通 对每个未访问的点都跑一次 Tarjan
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) root = i, tarjan(i);
    }

    cout << dcc << '\n';
    for (int i = 1; i <= dcc; ++i) {
        cout << vDCC[i].size() << ' ';
        for (auto& v : vDCC[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }
}

使用: 如 solve() 函数所示

-vDCC[idx] <第 idx 个点双连通分量内的点>
-cut[idx] <判断 idx 是否是割点>

1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950515253545556575859606162636465666768697071727374757677787980818283
```

* * *

#### \- 边双连通分量

```cpp

int h[N], e[M << 1], ne[M << 1], idx = 1;

void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

//root：根  id：辅助dfn和low  dcc：边双数目
int dfn[N], low[N], root, id, dcc;
vector<int> eDCC[N];//存每个边双的点
stack<int> stk;//和普通tarjan同
bool bridge[M << 1];//存桥

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++id;
    stk.push(u);
    for (int i = h[u]; i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]) {
                bridge[i] = bridge[i ^ 1] = true;//判桥
            }
        }
        else if ((i ^ 1) != from) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        ++dcc;
        int top;
        do {
            top = stk.top(); stk.pop();
            eDCC[dcc].emplace_back(top);
        } while (top != u);
    }
}

void solve() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) root = i, tarjan(i, 0);
    }

    cout << dcc << '\n';
    for (int i = 1; i <= dcc; ++i) {
        cout << eDCC[i].size() << ' ';
        for (auto& v : eDCC[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }
}

使用: 如 solve() 函数所示

-vDCC[idx] <第 idx 个边双连通分量内的点>
-bridge[idx] <判断第 idx 编号的边是否是割边>


12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849505152535455565758596061626364656667686970
```

* * *

* * *

# 6.网络流

### (1) 网络最大流

#### \- Dinic（当前弧优化）

```cpp

using i64 = long long;

const int N = 1e4 + 10, M = 2e5 + 10;

struct edge 
{
    int e, ne;
    i64 f;
}E[M];//邻接表

int h[N], idx = 1, n, m, s, t;
int dist[N], cur[N], que[N];
//dist分层 cur当前弧优化 que模拟队列

bool bfs() 
{
    int hh = 0, tt = 1;
    memset(dist, -1, sizeof dist);
    que[0] = s, dist[s] = 0, cur[s] = h[s];
    
    while (hh != tt) 
    {
        int u = que[hh++];
        if (hh == N) hh = 0;
        for (int i = h[u]; i; i = E[i].ne) 
        {
            i64 v = E[i].e, f = E[i].f;
            if (f && dist[v] == -1) 
            {
                dist[v] = dist[u] + 1;
                cur[v] = h[v];
                if (v == t) return true;
                que[tt++] = v;
                if (tt == N) tt = 0;
            }
        }
    }
    return false;
}

i64 dfs(int u = s, i64 flow = INT32_MAX) 
{
    if (u == t) return flow;
    i64 last = flow;//该点剩余的流
    for (int i = cur[u]; i && last; i = E[i].ne) 
    {
        cur[u] = i;//当前弧优化
        i64 v = E[i].e, f = E[i].f;
        if (f && dist[v] == dist[u] + 1) 
        {
            dist[v] = dist[u] + 1;
            i64 c = dfs(v, min(f, last));
            if (!c) dist[v] = -1;//废点优化
            E[i].f -= c, E[i ^ 1].f += c;//正边加 反边减
            last -= c;//残余流量
        }
    }
    return flow - last;//全部的减去剩下的即使用过的
}

inline void add(int a, int b, i64 c) {
    E[++idx].e = b, E[idx].f = c, E[idx].ne = h[a], h[a] = idx;
    E[++idx].e = a, E[idx].f = 0, E[idx].ne = h[b], h[b] = idx;
}

i64 dinic() {
    i64 mxflow = 0;
    while(bfs()) mxflow += dfs();
    return mxflow;
}

void solve() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) 
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    
    cout << dinic() << '\n';
}


使用：
如 solve() 函数所示

12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849505152535455565758596061626364656667686970717273747576777879808182838485868788
```

#### \- ISAP（当前弧优化）

```cpp

using i64 = long long;

const int N = 1e5 + 10;

int h[N], e[N << 1], ne[N << 1], idx = 1;
//gap层点数 dist 分层 cur 当前弧优化
int gap[N], cur[N], dist[N], s, t;
i64 w[N << 1];//流量

int n, m;

inline void bfs()
{
    for (int i = 1; i <= n; ++i)
        dist[i] = -1, gap[i] = 0;
    queue<int> que;
    dist[t] = 0, gap[0] = 1;
    que.push(t);
    while (que.size())
    {
        auto u = que.front(); que.pop();
        for (int i = h[u]; i; i = ne[i])
        {
            int v = e[i];
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1, que.push(v);
            ++gap[dist[v]];
        }
    }
}

i64 dfs(int u = s, i64 flow = INT64_MAX)
{
    if (u == t) return flow;
    i64 last = flow;//该点剩余的流

    for (int i = h[u]; i; i = ne[i])
    {
        i64 v = e[i], vol = w[i];
        if (vol > 0 && dist[u] == dist[v] + 1)
        {
            i64 c = dfs(v, min(vol, last));
            w[i] -= c, w[i ^ 1] += c;//正边加 反边减
            last -= c;//残余流量
        }
        if (last == 0) return flow;//所有流量均用光
    }
    --gap[dist[u]];
    if (!gap[dist[u]]) 
        dist[s] = n + 1;
    ++dist[u], ++gap[dist[u]];
    return flow - last;
}

inline i64 ISAP()
{
    bfs();
    i64 mxflow = 0;
    while (dist[s] < n)
    {
        for (int i = 1; i <= n; ++i) cur[i] = h[i];
        mxflow += dfs();
    }
    return mxflow;
}


inline void add(int a, int b, i64 c)
{
    e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}

void solve()
{
    cin >> n >> m >> s >> t;
    for (int i = 0, x, y, w; i < m; ++i)
    {
        cin >> x >> y >> w;
        add(x, y, w), add(y, x, 0);
    }
    cout << ISAP() << '\n';
}


使用：
如 solve() 函数所示

12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849505152535455565758596061626364656667686970717273747576777879808182838485868788
```

* * *

### (2) 最小费用最大流

#### \- Dinic + SPFA（LLL+SLF）

```cpp

const int N = 1e5 + 10;

struct edges {
    int v, ne;
    i64 f, c;
}E[N];

int h[N], dist[N], cur[N], idx = 1;
int n, m, s, t;
bool vis[N];

inline bool spfa()//老老实实用SLF好像会比SLF+LLL快
{
    for (int i = 1; i <= n; ++i)
        dist[i] = 0x3f3f3f3f, cur[i] = h[i];

    deque<int> que;
    que.push_back(s);
    dist[s] = 0;
    i64 sum = dist[s], num = 1;//LLL
    while (que.size())
    {
        auto u = que.front();
        while (dist[u] * num > sum) //LLL
        {
            que.pop_front();
            que.push_back(u);
            u = que.front();
        }
        sum -= dist[u], --num;
        que.pop_front();
        
        vis[u] = false;
        for (int i = h[u]; i; i = E[i].ne)
        {
            auto& [v, ne, f, c] = E[i];
            if (f > 0 && dist[v] > dist[u] + c)
            {
                dist[v] = dist[u] + c;
                if (!vis[v])
                {
                    vis[v] = true;
                    if (que.size() && dist[que.front()] > dist[v])//SLF
                        que.push_front(v);
                    else
                        que.push_back(v);
                    sum += dist[v], ++num;//LLL
                }
            }
        }
    }
    return dist[t] != 0x3f3f3f3f;
}

i64 dfs(int u = s, i64 flow = INT64_MAX)
{
    if (u == t) return flow;
    i64 last = flow;
    vis[u] = true;//注意标记访问
    for (int& i = cur[u]; i && last; i = E[i].ne)
    {
        auto& [v, ne, f, cost] = E[i];
        if (f > 0 && !vis[v] && dist[v] == dist[u] + cost)
        {
            i64 c = dfs(v, min(f, last));
            E[i].f -= c, E[i ^ 1].f += c;
            last -= c;
        }
    }
    vis[u] = false;//注意清除标记
    return flow - last;
}

i64 maxflow = 0, mincost = 0;
inline void dinic()
{
    while (spfa())
    {
        i64 flow = dfs();
        maxflow += flow;
        mincost += dist[t] * flow;
    }
}

inline void add(int u, int v, i64 f, i64 c)
{
    E[++idx].v = v, E[idx].f = f, E[idx].c = c, E[idx].ne = h[u], h[u] = idx;
}

void solve()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i)
    {
        i64 u, v, w, c;
        cin >> u >> v >> w >> c;
        add(u, v, w, c), add(v, u, 0, -c);//注意加边
    }
    dinic();
    cout << maxflow << ' ' << mincost << '\n';
}

使用：
如 solve() 函数所示

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100101102103104105106
```

* * *

* * *

# 7.字符串

### (1) KMP字符串匹配

```cpp
string str, match;//str是模式串 match是匹配串

void getnxt(vector<int>& nxt, int len, string matcht)
{
	for (int i = 2; i < len; ++i)
	{
		nxt[i] = nxt[i - 1];
		while (nxt[i] && matcht[i] != matcht[nxt[i] + 1]) nxt[i] = nxt[nxt[i]];
		nxt[i] += (matcht[i] == matcht[nxt[i] + 1]);//补正nxt[i]
	}
}

bool kmp(string str, string match)
{
	//使字符串下标从 1 开始
	string strt = '?' + str + str, matcht = '?' + match;
	vector<int> nxt(matcht.size());
	getnxt(nxt, matcht.size(), matcht);
	//开始匹配: i为str下标 j 为match下标
	for (int i = 1, j = 1; i <= strt.size();)
	{
		while (j != 1 && strt[i] != matcht[j]) j = nxt[j - 1] + 1;//回溯 j
		if (strt[i] == matcht[j]) ++i, ++j;
		else ++i;
		if (j == matcht.size())
		{
			//此时 i - match.size() 即为第一个开始匹配元素的下标
			j = nxt[match.size()] + 1;
			//匹配成功后要做的事
			//return true;
		}
	}
	//匹配失败后要做的事
	//return false;
}

使用: 
-kmp(str, match) (模式串, 匹配串)
-if(kmp(str, match)) <判断>

注意:如果要多个模式串匹配一个匹配串，请务必开一个全局nxt数组保证复杂度

123456789101112131415161718192021222324252627282930313233343536373839404142
```

* * *

### (2)Trie 字典树

```cpp

const int N = 3e6 + 10, M = 26 + 26 + 10 + 10;//N 字符串总长度 M 字符种类数目
int trie[N][M], cnt[N], idx = 0;
bool exist[N];

void clear()
{
	fill(trie[0], trie[0] + idx * M, 0);
	fill(exist, exist + idx + 1, false);
	fill(cnt, cnt + idx + 1, 0);
	idx = 0;
}
int pos(char x)
{
	if (x >= 'a' && x <= 'z') return x - 'a' + 1;
	if (x >= 'A' && x <= 'Z') return x -'A' + 27;
	if (x >= '0' && x <= '9') return x -'0' + 53;
}
void insert(string & str)//插入字符串 str
{
	int now = 0;
	for (auto& x : str)
	{
		if (!trie[now][pos(x)]) trie[now][pos(x)] = ++idx;
		now = trie[now][pos(x)];
		++cnt[now];
	}
	exist[now] = true;
}
int findpre(string & str)//查询有多少个相同前缀 str
{
	int now = 0;
	for (auto& x : str)
	{
		if (!trie[now][pos(x)]) return 0;
		now = trie[now][pos(x)];
	}
	return cnt[now];
}
bool findstr(string & str)//查询是否存在字符串 str
{
	int now = 0;
	for (auto& x : str)
	{
		if (!trie[now][pos(x)]) return false;
		now = trie[now][pos(x)];
	}
	return exist[now];
}


使用: 给出字符串 <str>

-clear() <清空字典树>
-insert(str) <向树上插入str字符串>
-findpre(str) <查询是否有前缀串str>
-findstr(str) <查询是否存在字符串str>

12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849505152535455565758
```

* * *

### (3) 字符串双哈希

```cpp

using ui64 = unsigned long long;
using PUU = pair<ui64, ui64>;
using i64 = long long;

// N 为字符串最长长度 p为seed  mod1/mod2 为两个模数
const ui64 N = 1e4 + 10, p = 131, mod1 = 998244853, mod2 = 1e9 + 7;

ui64 a1[N], a2[N], hs1[N], hs2[N];

void init() {//初始化 a 数组
	a1[0] = a2[0] = 1;
	for (int i = 1; i <= 1e4; ++i) {
		a1[i] = a1[i - 1] * p % mod1;
		a2[i] = a2[i - 1] * p % mod2;
	}
}

void hashstr(string& str) {//将str哈希化
	int n = str.size();
	for (int i = 1; i <= n; ++i) {
		hs1[i] = (hs1[i - 1] * p % mod1 + str[i]) % mod1;
		hs2[i] = (hs2[i - 1] * p % mod2 + str[i]) % mod2;
	}
}

ui64 geths1(int l, int r) {//得到str[l -- r]的第一哈希值
	return (hs1[r] - hs1[l - 1] * a1[r - l + 1] % mod1 + mod1) % mod1;
}

ui64 geths2(int l, int r) {//得到str[l -- r]的第二哈希值
	return (hs2[r] - hs2[l - 1] * a2[r - l + 1] % mod2 + mod2) % mod2;
}

使用: 给出一个字符串 str，且 len 为 str 的长度
*init() <初始化预处理>
*hashstr(str) <将字符串str哈希化预处理>

-hs1[len] / hs2[len] <str整串的第一/二哈希值>
-geths1(l, r) / geths2(l, r) <得到str[l--r]的第一/二哈希值> 


<将哈希值存入 map<PUU, int>s, set<PUU> s 进一步处理>
例如:
map[{ geths1(l, r), geths2(l, r) }];
set,insert({ geths1(l, r), geths2(l, r) });
(注意: l，r严格在闭区间[1, n]内)

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748
```

* * *

* * *

# 8.杂项

### (1) 快读快写模板

```cpp
template<class T> void read(T& x) {
    x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x *= f;
}

template<class T> void print(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) print(x / 10);
    putchar(x % 10 ^ 48);
}

使用：给出变量 a

-read(a)
-print(a)


12345678910111213141516171819
```

**正在慢慢学，学会了再来更新**  
update: 2023 / 1 / 17 创建  
update: 2023 / 1 / 20 偷取：jiangly神の模板元  
update: 2023 / 1 / 23 更新：重链剖分 // LCA （重链剖分）// 单调队列  
update: 2023 / 2 / 04 更新：分块算法（维护区间和） // 二分  
update: 2023 / 2 / 06 更新：并查集（ jiangly神的板子）  
update: 2023 / 2 / 18 更新：匈牙利算法（二分图匹配）  
update: 2023 / 2 / 20 更新：Tarjan（缩点 / 强连通分量）  
update: 2023 / 2 / 21 更新：Tarjan（割点 / 割顶 // 桥）  
update: 2023 / 2 / 21 更新：Trie 字典树  
update: 2023 / 2 / 24 偷取：jiangly神の组合数板子  
update: 2023 / 2 / 27 偷取：yggの组合数板子  
update: 2023 / 3 / 06 更新：网络最大流 Dinic / ISAP  
update: 2023 / 3 / 27 更新：字符串双哈希  
update: 2023 / 4 / 08 更新：快读快写模板  
update: 2023 / 4 / 18 更新：可持久化线段树（维护区间和）  
update: 2023 / 4 / 19 更新：珂朵莉树（ODT）  
update: 2023 / 5 / 9 更新：莫队板子  
update: 2023 / 5 / 10 更新：线性筛欧拉函数  
update: 2023 / 5 / 12 更新：点双连通分量 // 边双连通分量