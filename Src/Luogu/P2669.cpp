#include <iostream>
using namespace std;
int main()
{
    int a, b = 0, c = 1, i;
    cin >> a;
    for (i = 1; i <= a; i++)
        a -= i, b += c * c, c++;
    cout << b + a * c;
    return 0;
}