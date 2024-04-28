#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N], b[N];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        // b[i]为差分数组
    }

    // 操作方法有4种（在对应的区间下 +-1 ）：
    // 1.  l = 1 , r = n 无意义
    // 2.  2 <= l <= r <= n - 1
    // 3.  l = 1, 2 <= r <= n - 1
    // 4.  2 <= l <= n - 1, r = n

    int pos = 0, neg = 0;
    // 数组元素相等时，b[2...n] = 0
    for (int i = 2; i <= n; i++)
    {
        if (b[i] > 0)
            pos += b[i];
        else
            neg -= b[i];
    }
    // 最少操作次数：pos neg的最大值
    // 对于原数组而言，修改l..r的值，需要修改差分数组b[l] ++/--, b[r + 1] --/++;
    // 因此，贪心，将差分数组正负配对，会进行min(pos, neg) 次变为零, 剩下abs(pos - neg) 需要变为零。
    // 故，最少操作次数为max(pos, neg) = min(pos, neg) + abs(pos - neg)
    // 对于剩余的 abs(neg - pos) 执行操作
    // 如 差分数组 0, 1, 2（原数组0 1 3） 要操作3次：先 1 -> 0 后 2 -> 0
    //  0 -1 1 --- 0 -1 0 操作1次
    cout << max(pos, neg) << endl;

    // 对于每一种操作，数组最后相等，问结果数量就是问b[1]有多少种可能--操作3可操作的次数
    // 由于之前是正负配对，b[1]值未发生改变
    // 现在需要进行abs(pos - neg)次操作变为零
    // 有如下方案：方案1 修改i...n ;方案二 修改1...i;
    // 假设此时数组只剩下正数，方案一1.b[i] -= (-1),b[n+1] += (-1);
    // 方案2.b[1] += 1,b[i+1] -=1;
    // 所以方案数abs(pos- neg) + 1;
    cout << abs(pos - neg) + 1 << endl;

    return 0;
}