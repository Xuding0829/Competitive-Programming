#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int x;
bool a, b;
int main()
{
    scanf("%d", &x);
    a = !(x & 1), b = (x > 4 && x <= 12); // a满足性质1，b满足性质2
    printf("%d %d %d %d", a & b, a | b, (a && !b || b && !a), !a && !b);
    // 按条件输出就好啦QWQ
}