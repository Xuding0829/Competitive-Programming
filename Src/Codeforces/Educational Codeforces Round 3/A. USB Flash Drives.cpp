#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[101];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, cmp);
    int num = 0, sum = 0;
    int i = 0;
    while (sum < m)
    {
        sum += a[i++];
        num++;
    }
    cout << num << endl;
}
