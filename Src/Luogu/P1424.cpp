#include <bits/stdc++.h> //包含了所有C++头文件的头文件
using namespace std;
int main()
{
    unsigned long long n, ans = 0; // 坑就坑在这儿。天数都那么大了，总路程还会小吗？？？
    int x;
    cin >> x >> n; // 输入星期和持续天数
    for (int i = 0; i < n; i++)
    {
        if ((x != 6) && (x != 7)) // 只要星期不等于6和7
            ans += 250;           // 总长度增加250
        if (x == 7)               // 当x等于7的时候
            x = 1;                // x归位为1
        else                      // 其他情况下（x不等于7的时候）
            x++;                  // x自加1
    }
    cout << ans; // 输出总路程
    return 0;
}