## A - 你在codeforces哪个分区？

### 题目描述

输入一个数字判断数字所在区间

### olution

```c++
#include <bits/stdc++.h>
using namespace std;
int n, m;

void solve()
{
	cin >> n;
	if (n >= 1900)
		cout << "Division 1" << endl;
	else if (n <= 1899 && n >= 1600)
		cout << "Division 2" << endl;
	else if (n <= 1599 && n >= 1400)
		cout << "Division 3" << endl;
	else
		cout << "Division 4" << endl;
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

## B - 至少出现三次

### 题目描述

给定一串数组，输出任意一个在数组中出现3次的元素，若不存在这样的元素，则输出-1

### solution1

运用map统计读入元素出现的次数，如果次数超过3次，把答案更新

//这种做法输出的是出现3次以上最大的元素

```c++
#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    int ans = -1;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] >= 3)
            ans = x;
    }
    cout << ans << endl;
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

### solution2

运用桶排序，用 a[n]  存储n出现的次数   

边读入元素边统计当前元素出现的次数，再从前往后遍历一遍，若a[i]大于等于3更新答案

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n;
int a[N];

void solve()
{
	memset(a, 0, sizeof(a));
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        a[x]++;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++)
        if (a[i] >= 3)
        {
            ans = i;
            break;
        }
    cout << ans << endl;
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

## C - 全奇全偶数组

### 题目描述

给定一组数组，每次执行如下操作的一种，奇数下标的元素+1或者偶数下标的元素+1。问最后是否可以使得数组全为奇数或者偶数

### solution

这里可以用1表示奇数， 0表示偶数 对数组稍加枚举

a1   a2    a3    a4

（此处省略 2^4 种情况）

通过观察可以发现，数组若要经过操作全为奇数或者偶数，需满足a[ i ] & a[ i - 2] 具有相同的奇偶性

因此，我们可以遍历数组，如果遇到 a[ i ] & a[ i - 2 ] 奇偶性不同，则输出NO； 如果能完全遍历数组输出YES;

当然 ，需要特判 数组一共只有2个元素的情况

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;
int n;
int a[N];

void solve()
{
    cin >> n;
    bool flag = true;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n == 2)
    {
        puts("YES");
        return;
    }

    for (int i = 3; i <= n; i++)
    {
        if (a[i - 2] % 2 != a[i] % 2)
        {
            flag = false;
            break;
        }
    }
    puts(flag ? "YES" : "NO");
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

## D - 方格涂色

### 题目描述

给定一串字符串，问是否可以由一段全为w组成的数组，经过若干次涂色（涂色使得两个相邻的方格其中一个被涂上r红色，另一个被涂上b蓝色），

### solution

example：WWWWW→WWBRW→RBBRW→RBRRW

观察最后的字符串，易知 w 可以作为隔板将字符串分段，可以再字符串末尾再加上一个w，将字符串以w分割线分割为若干段，对着若干段进行讨论

wwww —> bbbr 模拟涂色过程， 易知当全为w的字符串全部涂色之后， 同时必定存在br两种颜色，不可能存在只有一种颜色的情况，根据这一性质可以通过记录   子串中br颜色的个数来判断字符串是否合法

```c++
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt_B = 0, cnt_R = 0;
    bool flag = true;
    s += 'W';
    for (int i = 0; i < n + 1; i++)
    {
        if (s[i] == 'W')
        {
            if (cnt_B == 0 && cnt_R > 0 || cnt_R == 0 && cnt_B > 0)
            {
                flag = false;
                break;
            }
            cnt_B = 0, cnt_R = 0;
        }
        else if (s[i] == 'B')
            cnt_B++;
        else if (s[i] == 'R')
            cnt_R++;
    }
    puts(flag ? "YES" : "NO");
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



## E - 简单的字符串匹配

### 题目描述

给定若干个长度为2，只包含小写字母'a'到小写字母'k'的字符串。问有多少对字符串，他们之间恰好只有一个位置上的字符不同。

### solution

aa

aa

ab

ac

用二维数组存储字符串输入 字符串xy 的个数 g [x] [y] ++

固定一位不变  枚举另一位   

如 x 不变 i = 'a' ~ 'k' 统计 i !=  y 的字符串个数之和 

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 150;
int g[N][N];
void solve()
{
    memset(g, 0, sizeof(g));
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        char x, y;
        cin >> x >> y;
        g[x][y]++;
        for (int j = 'a'; j <= 'k'; j++)
        {
            if (x != j)
                ans += g[j][y];
            if (y != j)
                ans += g[x][j];
        }
    }
    cout << ans << endl;
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



## F - 伙伴之间要公平

### 题目描述

给定一串数组，分别从前往后， 从后往前相加记作a,b;要求a==b, 同时ab不能加上同一个元素a[ i ]

问a, b 共加了多少个元素

### solution

双指针做法

定义 l， r 分别从1 ， n 开始遍历



```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int a[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0, cnt = 0, sum1 = 0, sum2 = 0;
    // sum1 记录 l开始的和  sum2 记录 r 开始的和
    int l = 1, r = n;
    while(l <= r)
    {
        sum1 += a[l];
        cnt++;//数量+1
        while(sum2 < sum1 && l < r)//由于先执行l,循环结束要求sum2 > sum1
        // 不可改成while(sum1 < sum2 && l < r) 
        {
            sum2 += a[r--];
            cnt++;//数量+1
        }
        if(sum1 == sum2)
            ans = cnt;
        // 只有两者之和相等时候更新答案
        l++;
    }
    cout << ans << endl;
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

## G - 雪花坠落

### 题目描述

给定一个地图，*代表雪花，o代表障碍物，. 代表空气

问雪花下落后最终状态是什么

### solution

先枚举每一列，初始状态雪花最低可以落到最后一行；

枚举每一行，每一行状态更新雪花下落的最低点。如果是0，最低落到前一行，如果是*，则让 * 落到最低点，同时更新最低点

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 55;


void solve()
{
    int n, m;
    char g[N][N];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    for (int j = 1; j <= m; j++)
    {
        int lowest = n;
        for (int i = n; i >= 1; i--)
        {
            if (g[i][j] == 'o')
                lowest = i - 1;
            if (g[i][j] == '*')
                swap(g[i][j], g[lowest][j]), lowest--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << g[i][j];
        cout << endl;
    }
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



## H - 位运算入门

### 题目描述

给定一串数组和一个数k，可对数组最多进行k次操作（将a[ i ] 的 j 位设置为1）

问操作后 a[1] & a[2] ……& a[n] 的最大值是多少

### solution

贪心求最大值，要使ans最大，应尽可能使得a[i] 的高位变为1

由于操作最高至30位，可以先循环统计每个数各个位上0的个数

从高位到低位遍历，判断0的个数是否小于可操作数k，若是，则答案的二进制表示当前位是1，否则，判断下一位

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 50;
int n, k;
int a[N];

void solve()
{
    memset(a, 0, sizeof(a));
    cin >> n >> k;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        for (int j = 0; j <= 30; j++)
        {
            if (x >> j & 1)
                ;
            else
                a[j]++;
        }
    }
    int ans = 0;
    for(int i = 30; i >= 0; i--)
    {
        if (k >= a[i])
        {
            k -= a[i];
            ans += 1 << i;
        }
    }
    cout << ans << endl;
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

