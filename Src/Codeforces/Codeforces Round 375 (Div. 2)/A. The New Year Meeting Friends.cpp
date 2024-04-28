#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    int a[5];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3);
    int dis = 10000;
    for (int i = a[0]; i <= a[2]; i++)
    {
        dis = min(abs(i - a[0]) + abs(i - a[1]) + abs(i - a[2]), dis);
    }
    cout << dis << endl;
    return 0;
}
