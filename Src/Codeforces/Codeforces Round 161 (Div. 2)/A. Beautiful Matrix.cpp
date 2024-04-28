#include <iostream>
#include <algorithm>
using namespace std;

int a[5][5];

int main()
{
    int m, n;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                m = i;
                n = j;
            }
        }

    int step = 0;
    if (m == 2 && n == 2)
    {
        cout << step << endl;
        return 0;
    }
    else
    {
        while (m != 2)
        {
            step++;
            if (m < 2)
                m += 1;
            else if (m > 2)
                m -= 1;
        }
        while (n != 2)
        {
            step++;
            if (n < 2)
                n += 1;
            else if (n > 2)
                n -= 1;
        }
    }
    cout << step << endl;
    return 0;
}
