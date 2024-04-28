#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x;
        cin >> x;
        long long int num = 0;
        for (int i = 1; i <= 9; i++)
        {
            long long int j = i, k = i;
            while (j <= x)
            {
                num++;
                j = j * 10 + k;
            }
        }
        cout << num << endl;
    }
    return 0;
}
