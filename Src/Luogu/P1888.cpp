#include <bits/stdc++.h> //万能库
using namespace std;
int main()
{
    int a[4];                   // 数组用来存储三角形三条边
    for (int i = 0; i < 3; i++) // 因为是勾股数 一共只有三个数 所以循环三次来读入三个数
    {
        cin >> a[i]; // 把数都存在一个数组
    }
    sort(a, a + 3);                                                      // 把三个数从小到大排列 此时a[0]就是最小直角边 a[2]为斜边
    cout << a[0] / __gcd(a[0], a[2]) << '/' << a[2] / __gcd(a[0], a[2]); // 因为要约分 所以用gcd(a[0],a[2]）取a[0]与a[2]的最大公约数                                                    //  a[0]/最大公约数的值与a[2]/最大公约数的比值即是约分后的结果
    return 0;
}