### A. Tricky Sum

题意：

问1-n中，加上不是2的次方的数，减去2的次方的数，最后的结果是多少

思路：

1-n求和，减去2倍的2的次方之和，可用高斯求和公式，等比数列求和公式

```c++
#include <bits/stdc++.h>

using i64 = long long;

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
};

void solve()
{
    i64 n;
    std::cin >> n;

    i64 sum = (1 + n) * n / 2;
    i64 sum2 = 2 * qmi(2, (int)log2(n)) - 1;
    sum -= 2 * sum2;
    std::cout << sum << '\n';
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

### B. Queries on a String

题意：

给你一个字符串，给定区间 l ， r 和操作次数 k，每次将区间内的最后一个字符移至最前面，问最后的字符串是什么

思路：

k操作可以是一个周期性的操作，与区间的长度有关；这里假设k是最后有效的操作次数

把字符串分割为三个部分，0 - （l - 1）   (L -- R)  和   (R + 1。。)

我们每次只需对L 和 R 的部分进行操作即可

具体操作，就是将后k个字符移至前面

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    while (n--)
    {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--, r--;
        int len = r - l + 1;
        k %= len;

        if (!k)
            continue;

        std::string s1 = s.substr(0, l);
        std::string s2 = s.substr(l, len);
        std::string s3 = s.substr(r + 1);

        std::string t = s2.substr(len - k);
        s2.erase(len - k);
        s2 = t + s2;

        s = s1 + s2 + s3;
    }

    std::cout << '\n';
    std::cout << s << '\n';

    return 0;
}
```

### [C - Nearest vectors](https://codeforces.com/contest/598/problem/C)

题意：

给你n个坐标，问你这些坐标与原点连线组成的线段两两直接构成的角中最小角对应的坐标编号；

思路：

用atan2（y, x）计算点与x轴正方向构成的角度v，最小角必定是与v大小相邻的角组成的

用pair<>存储角度，编号

对每个点与x轴的夹角进行排序

遍历一遍即可

需要注意的是，不仅仅是这题，在不使用 `using namespace std` 时，所用的数学函数，默认是  `math.h` . 例如本题中， atan2 使用的是 `math.h`中的函数，使用的参数是double类型，在本题要求的高精度下是不合适的，所以使用 atant2 时正确写法是 `std::atan2(y, x)`;

```c++
#include <bits/stdc++.h>

using i64 = long long;

const long double pi = acos(-1.0);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<long double, int>> angle(n);
    for (int i = 0; i < n; i++)
    {
        long double x, y;
        std::cin >> x >> y;
        angle[i].first = std::atan2(y, x);
        angle[i].second = i + 1;
    }

    std::sort(angle.begin(), angle.end());

    int ans1, ans2;
    long double min = 2 * pi;
    for (int i = 0; i < n; i++)
    {
        long double tmp = angle[(i + 1) % n].first - angle[i].first;
        if (tmp < 0)
            tmp += 2 * pi;
        if (tmp < min)
            min = tmp, ans1 = angle[i].second, ans2 = angle[(i + 1) % n].second;
    }
    std::cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}
```

### [D - Igor In the Museum](https://codeforces.com/contest/598/problem/D)

题意：

给定一个二维矩阵，*代表图画，.代表空地，人可以在空地移动，但不能到达图画，问人最多可以看到多少图画

思路：

一开始对第二个样例有点疑问，结合题目描述

>Igor is able to see the picture only if he is in the cell adjacent to the wall with this picture. Igor have a lot of time, so he will examine every picture he can see.

好奇难道在不同位置看到的图画是不一样的？？？

但是第二个样例答案是8，问的就是能看到多少画（包括已经看过的）

~~横看成岭侧成峰是吧~~

第一眼感觉就是一个bfs的板子题，在题目的数据范围下，在第十个点会t

菜鸡第一次写的代码

```c++
auto bfs = [&](int x, int y)
{
    int cnt = 0;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    std::queue<std::pair<int, int>> q;
    std::vector vis(n + 1, std::vector<bool>(m + 1));
    q.push({x, y});
    vis[x][y] = true;
    while (q.size())
    {
        int tx = q.front().first, ty = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = tx + dx[i], ny = ty + dy[i];
            if (nx > n || nx < 1 || ny > m || ny < 1)
                continue;
            if (g[nx][ny] == '*')
                cnt++;

            if (g[nx][ny] == '.' && !vis[nx][ny])
                q.push({nx, ny}), vis[nx][ny] = true;
        }
    }
    return cnt;
};
```



于是， 考虑每一个连通块，对于每个连通块预处理出能看到的数量，然后输入查询即可

这里可以用并查集、dfs、bfs等算法   属于各显神通了



### E. Chocolate Bar

题意：

给定一个n * m的巧克力，问要吃k个单位的巧克力至少要多少费用

费用：每切一刀的线段的平方、

思路：

这是一个dp问题  数据范围不大，先预处理出结果，后对输入查表即可。 

f[i, j, k] 表示 i * j 的巧克力，吃k个单位的最小值

对于切法我们可以横着切，竖着切

对于横着切，我们每次加上 i * i； 竖着切， 每次加上 j * j

而对于横着切，我们一共可以选择1----- j-1 的位置上切，因此还需要用一重循环控制切的位置，竖着切同理

状态转移方程：

​		f[i, j, k] = std::min(f[i, j, k], f[i - t, j, k] + j * j);(t 枚举切的位置)

​		如果k > t * j, f[i, j, k] = std::min(f[i, j, k], f[i - t, j, k - t * j] + j * j)

​		可以切出t * j块， 但是还不够k，此时，需要的贡献来源于两部分， 一部分切出 t * j ，另一部分切出 k - t * j

 k - t * j的贡献又可以由 f[i - t, j, k - t * j]转移过来

```c++
A. Tricky Sum
题意：
问1-n中，加上不是2的次方的数，减去2的次方的数，最后的结果是多少
思路：
1-n求和，减去2倍的2的次方之和，可用高斯求和公式，等比数列求和公式
 #include <bits/stdc++.h>
 ​
 using i64 = long long;
 ​
 int qmi(int a, int b)
 {
     int res = 1;
     while (b)
     {
         if (b & 1)
             res = res * a;
         a = a * a;
         b >>= 1;
     }
     return res;
 };
 ​
 void solve()
 {
     i64 n;
     std::cin >> n;
 ​
     i64 sum = (1 + n) * n / 2;
     i64 sum2 = 2 * qmi(2, (int)log2(n)) - 1;
     sum -= 2 * sum2;
     std::cout << sum << '\n';
 }
 ​
 int main()
 {
     std::ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
 ​
     int t;
     std::cin >> t;
     while (t--)
     {
         solve();
     }
 ​
     return 0;
 }
B. Queries on a String
题意：
给你一个字符串，给定区间 l ， r 和操作次数 k，每次将区间内的最后一个字符移至最前面，问最后的字符串是什么
思路：
k操作可以是一个周期性的操作，与区间的长度有关；这里假设k是最后有效的操作次数
把字符串分割为三个部分，0 - （l - 1）   (L -- R)  和   (R + 1。。)
我们每次只需对L 和 R 的部分进行操作即可
具体操作，就是将后k个字符移至前面
 #include <bits/stdc++.h>
 ​
 using i64 = long long;
 ​
 int main()
 {
     std::ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
 ​
     std::string s;
     std::cin >> s;
 ​
     int n;
     std::cin >> n;
 ​
     while (n--)
     {
         int l, r, k;
         std::cin >> l >> r >> k;
         l--, r--;
         int len = r - l + 1;
         k %= len;
 ​
         if (!k)
             continue;
 ​
         std::string s1 = s.substr(0, l);
         std::string s2 = s.substr(l, len);
         std::string s3 = s.substr(r + 1);
 ​
         std::string t = s2.substr(len - k);
         s2.erase(len - k);
         s2 = t + s2;
 ​
         s = s1 + s2 + s3;
     }
 ​
     std::cout << '\n';
     std::cout << s << '\n';
 ​
     return 0;
 }
C - Nearest vectors
题意：
给你n个坐标，问你这些坐标与原点连线组成的线段两两直接构成的角中最小角对应的坐标编号；
思路：
用atan2（y, x）计算点与x轴正方向构成的角度v，最小角必定是与v大小相邻的角组成的
用pair<>存储角度，编号
对每个点与x轴的夹角进行排序
遍历一遍即可
需要注意的是，不仅仅是这题，在不使用 using namespace std 时，所用的数学函数，默认是  math.h . 例如本题中， atan2 使用的是 math.h中的函数，使用的参数是double类型，在本题要求的高精度下是不合适的，所以使用 atant2 时正确写法是 std::atan2(y, x);
 #include <bits/stdc++.h>
 ​
 using i64 = long long;
 ​
 const long double pi = acos(-1.0);
 ​
 int main()
 {
     std::ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
 ​
     int n;
     std::cin >> n;
 ​
     std::vector<std::pair<long double, int>> angle(n);
     for (int i = 0; i < n; i++)
     {
         long double x, y;
         std::cin >> x >> y;
         angle[i].first = std::atan2(y, x);
         angle[i].second = i + 1;
     }
 ​
     std::sort(angle.begin(), angle.end());
 ​
     int ans1, ans2;
     long double min = 2 * pi;
     for (int i = 0; i < n; i++)
     {
         long double tmp = angle[(i + 1) % n].first - angle[i].first;
         if (tmp < 0)
             tmp += 2 * pi;
         if (tmp < min)
             min = tmp, ans1 = angle[i].second, ans2 = angle[(i + 1) % n].second;
     }
     std::cout << ans1 << ' ' << ans2 << '\n';
 ​
     return 0;
 }
D - Igor In the Museum
题意：
给定一个二维矩阵，*代表图画，.代表空地，人可以在空地移动，但不能到达图画，问人最多可以看到多少图画
思路：
一开始对第二个样例有点疑问，结合题目描述
Igor is able to see the picture only if he is in the cell adjacent to the wall with this picture. Igor have a lot of time, so he will examine every picture he can see.
好奇难道在不同位置看到的图画是不一样的？？？
但是第二个样例答案是8，问的就是能看到多少画（包括已经看过的）
横看成岭侧成峰是吧
第一眼感觉就是一个bfs的板子题，在题目的数据范围下，在第十个点会t
菜鸡第一次写的代码
 auto bfs = [&](int x, int y)
 {
     int cnt = 0;
     int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
     std::queue<std::pair<int, int>> q;
     std::vector vis(n + 1, std::vector<bool>(m + 1));
     q.push({x, y});
     vis[x][y] = true;
     while (q.size())
     {
         int tx = q.front().first, ty = q.front().second;
         q.pop();
 ​
         for (int i = 0; i < 4; i++)
         {
             int nx = tx + dx[i], ny = ty + dy[i];
             if (nx > n || nx < 1 || ny > m || ny < 1)
                 continue;
             if (g[nx][ny] == '*')
                 cnt++;
 ​
             if (g[nx][ny] == '.' && !vis[nx][ny])
                 q.push({nx, ny}), vis[nx][ny] = true;
         }
     }
     return cnt;
 };

于是， 考虑每一个连通块，对于每个连通块预处理出能看到的数量，然后输入查询即可
这里可以用并查集、dfs、bfs等算法   属于各显神通了

E. Chocolate Bar
题意：
给定一个n * m的巧克力，问要吃k个单位的巧克力至少要多少费用
费用：每切一刀的线段的平方、
思路：
这是一个dp问题  数据范围不大，先预处理出结果，后对输入查表即可。 
f[i, j, k] 表示 i * j 的巧克力，吃k个单位的最小值
对于切法我们可以横着切，竖着切
对于横着切，我们每次加上 i * i； 竖着切， 每次加上 j * j
而对于横着切，我们一共可以选择1----- j-1 的位置上切，因此还需要用一重循环控制切的位置，竖着切同理
状态转移方程：
 f[i, j, k] = std::min(f[i, j, k], f[i - t, j, k] + j * j);(t 枚举切的位置)
 如果k > t * j, f[i, j, k] = std::min(f[i, j, k], f[i - t, j, k - t * j] + j * j)
 可以切出t * j块， 但是还不够k，此时，需要的贡献来源于两部分， 一部分切出 t * j ，另一部分切出 k - t * j
 k - t * j的贡献又可以由 f[i - t, j, k - t * j]转移过来
 #include <bits/stdc++.h>
 ​
 using i64 = long long;
 ​
 constexpr int inf = 0x3f3f3f3f;
 ​
 int f[35][35][55];
 ​
 void solve()
 {
     int n, m, k;
     std::cin >> n >> m >> k;
     std::cout << f[n][m][k] << '\n';
 }
 ​
 int main()
 {
     std::ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
 ​
     memset(f, 0x3f, sizeof(f));
 ​
     for (int i = 0; i <= 30; i++)
         for (int j = 0; j <= 30; j++)
         {
             f[i][j][0] = 0;
             if (i * j <= 50)
                 f[i][j][i * j] = 0;
         }
 ​
     for (int i = 1; i <= 30; i++)
     {
         for (int j = 1; j <= 30; j++)
         {
             for (int k = 1; k <= std::min(50, i * j); k++)
             {
                 for (int t = 1; t < i; t++)
                 {
                     f[i][j][k] = std::min(f[i - t][j][k] + j * j, f[i][j][k]);
                     if (k > t * j)
                         f[i][j][k] = std::min(f[i][j][k], f[i - t][j][k - t * j] + j * j);
                 }
                 for (int t = 1; t < j; t++)
                 {
                     f[i][j][k] = std::min(f[i][j - t][k] + i * i, f[i][j][k]);
                     if (k > t * i)
                         f[i][j][k] = std::min(f[i][j][k], f[i][j - t][k - t * i] + i * i);
                 }
             }
         }
     }
 ​
     int t;
     std::cin >> t;
     while (t--)
     {
         solve();
     }
 ​
     return 0;
 }

```

### F. Cut Length

题意
按顺时针或逆时针顺序给你一个多边形的顶点，问一条线与多边形相交截得的线一共有多长

