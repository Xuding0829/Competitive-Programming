#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double n, p;
    while (cin >> n >> p)
    {
        double ans;
        ans = pow(p, 1 / n);
        printf("%.0lf\n", ans);
    }
    return 0;
}
