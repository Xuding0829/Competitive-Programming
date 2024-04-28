#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    while (n--)
    {
        int a[3], cnt = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
            cnt += a[i];
        }
        if (cnt >= 2)
            sum++;
    }
    cout << sum << endl;
    return 0;
}
