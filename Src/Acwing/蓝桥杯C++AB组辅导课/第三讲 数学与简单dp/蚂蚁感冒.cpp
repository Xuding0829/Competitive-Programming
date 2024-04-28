#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];
int res = 1;
/*
当第一只蚂蚁向右走时：
    右边    向左走 V     ***这个是前提条件***            ———— right
            向右走 X
    左边    向左走 X
            向右走  [存在右边向左走V    不存在右边向左走X]   ———— left


当第一只蚂蚁向左走时：
    右边    向左走 X
            向右走 [存在左边向右走V     不存在左边向右走X]  —————right
    左边    向左走 X
            向右走 V    ***这个是前提条件***                ————left

*/
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int left = 0, right = 0;
    for (int i = 2; i <= n; i++)
    {
        if (abs(a[i]) > abs(a[1]) && a[i] < 0)
            right++; // 右边向左走
        else if (abs(a[i] < abs(a[1])) && a[i] > 0)
            left++; // 左边向右走
    }

    // cout << "left" << left << ' ' << "right" << ' ' << right << endl;

    // a[1] > 0 代表被感染的蚂蚁往右走
    if (a[1] > 0 && right == 0)
        res = 1;
    else if (a[1] > 0 && right)
        res += left + right;
    // a[1] < 0 代表被感染的蚂蚁向左走
    else if (a[1] < 0 && left == 0)
        res = 1;
    else
        res += left + right;

    /*
    if (x[0] > 0 && right == 0 || x[0] < 0 && left == 0)
        cout << 1 << endl;
    else
        cout << left + right + 1 << endl;
    */

    cout << res << endl;
    return 0;
}