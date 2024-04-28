#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double dis1, dis2, dis3, dis;

    dis1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    dis2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    dis3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    dis = dis1 + dis2 + dis3;

    printf("%.2lf", dis);

    return 0;
}