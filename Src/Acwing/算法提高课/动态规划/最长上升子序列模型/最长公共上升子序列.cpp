#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        int maxn = 1;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
                f[i][j] = std::max(f[i][j], maxn);
            if (b[j] < a[i])
                maxn = std::max(maxn, f[i - 1][j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = std::max(res, f[n][i]);
    std::cout << res << '\n';
    return 0;
}

/*
朴素写法:
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
            {
                f[i][j] = std::max(f[i][j], 1);
                for (int k = 1; k < j; k++)
                    if(b[k] < a[i])
                        f[i][j] = std::max(f[i][j], f[i][k] + 1);
            }
        }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = std::max(res, f[n][i]);

    return 0;
}
*/

/*
    for(int i=1;i<=n;i++){
        int maxv=1;//这里的maxv是用来存放下一次a[i]和b[j]相同前的前导最长公共上升子序列。
        for(int j=1;j<=n;j++){//On^2扫描
            f[i][j]=f[i-1][j];//f[i][j]先吃f[i-1][j]的状态表明当a[i]不属于公共上升子序列时。
            if(a[i]==b[j])f[i][j]=max(f[i][j],maxv);//a[i]属于公共上升子序列时,自然a[i]=b[j],因为两个同属于公共上升子序列,且都是最后一个元素。
            if(b[j]<a[i])maxv=max(maxv,f[i-1][j]+1);//重点!如果b[j]<a[i]那么为下次b[j]=a[i]做前导准备,也就是说如果后续
        }//有a[i]==b[j],那么自然f[i-1][j]也是一种情况,为了避免重复比较,将其与maxv进行比较,更新maxv,maxv存储前导最长公共子序列。
    }
*/