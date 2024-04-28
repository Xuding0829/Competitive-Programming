#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main()
{
    cin >> n;
    int num = 0;
    if (n % 5 != 0)
    {
        num += n / 5;
        n %= 5;
        num += 1;
    }
    else
    {
        num += n / 5;
    }

    cout << num << endl;
    return 0;
}
