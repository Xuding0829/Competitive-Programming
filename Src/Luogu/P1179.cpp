#include <iostream>
using namespace std;
int main()
{
    long long a, b, s = 0, n;
    cin >> a >> b;
    for (int y = a; y <= b; y++)
    {
        n = y; // 不能改变循环变量的原值，所以要找“替身”
        while (n != 0)
        {
            if (n % 10 == 2)
                s++;
            n /= 10;
        }
    }
    cout << s;
    return 0;
}