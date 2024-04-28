#! https://zhuanlan.zhihu.com/p/632025821
### [ZAFU MAY Contest](https://codeforces.com/gym/440520)





[D - AsindE 的二叉树](https://codeforces.com/gym/440520/problem/D)

思路:

类似于猜数字的游戏；

设根节点为 $u$，$u$的左儿子为 $v(v = u << 1)$, 隐藏点为$x$

在这里就是先断开$u$与$v$的连接，读入x，判断$x$在$u$所在的联通块上还是$v$所在的连通块上

如果在左边， 更新$u = v$；

在右边，更新v ^= 1， 此时层数并没有减少，$u$仍有可能为$x$，再读入$x$，判断$u$是否为$x$

若是，输出即可，若否，更新$u = v$;



>x == (1 << (i - 1)) - 1 
>
>以v为根节点的子树层数为(i - 1) 画图易知
>
>有二叉树的性质或者瞪眼法可知，$j=i-1$ 以v为根节点的子树含有$2^j$



##### solution1

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve() 
{
    int k;
    std::cin >> k;
    if (k == 1) // 特判
    {
        std::cout << "! " << 1 << ' ' << 1 << std::endl;
        return;
    }

    i64 u = 1;
    for (int i = k; i >= 2; i--) // k枚举层数
    {
        i64 v = u << 1;
        std::cout << "? " << u << ' ' << v << std::endl; // std::endl 可清空缓存区

        i64 x;
        std::cin >> x;
        if (x == (1ll << (i - 1)) - 1) // 左
        {
            u = v; // 左儿子为根节点
            if (i == 2)
            {
                std::cout << "! " << u << ' ' << u << std::endl;
                return;
            }
        }
        else // 右
        {
            v ^= 1; // 截断左儿子与父节点的连接，
            if (i == 2)
            {
                std::cout << "! " << u << ' ' << v << std::endl;
                return;
            }
            std::cout << "? " << u << ' ' << v << std::endl;
        
            std::cin >> x;
            if (x == 1) // 父节点就是要找的点
            {
                std::cout << "! " << u << ' ' << u << std::endl;
                return;
            }
            u = v; // 父节点不是要找的点， 右儿子更新为父节点
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```



根据$x$的奇偶性可以判断在哪个连通块上

##### solution2

```c++
#include <bits/stdc++.h>
using i64 = long long;
void solve()
{
    int k;
    std::cin >> k;
    i64 t = 1;
    while (--k)
    {
        std::cout << "? " << t << " " << t * 2 << std::endl;
        i64 x;
        std::cin >> x;
        if (x & 1)
        {
            t = t << 1;
        }
        else
        {
            std::cout << "? " << t << " " << t * 2 + 1 << std::endl;
            std::cin >> x;
            if (x == 1)
            {
                std::cout << "! " << t << " " << t * 2 + 1 << std::endl;
                return;
            }
            t = t << 1 | 1;
        }
    }
    std::cout << "! " << t << " " << t << std::endl;
}

int main()
{
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}
```



