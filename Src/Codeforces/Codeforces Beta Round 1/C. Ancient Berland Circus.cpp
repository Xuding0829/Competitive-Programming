#include <bits/stdc++.h>

using i64 = long long;

const double pi = acos(-1.0);
const double eps = 1e-3;

double gcd(double a, double b)
{
    if (fabs(b) < eps)
        return a;
    if (fabs(a) < eps)
        return b;
    return gcd(b, fmod(a, b));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<double> x(3), y(3);
    for (int i = 0; i < 3; i++)
        std::cin >> x[i] >> y[i];

    double a = sqrt((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
    double b = sqrt((x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]));
    double c = sqrt((x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]));

    double p = (a + b + c) / 2.0;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    double r = (a * b * c) / (4 * s);

    double A = acos(1 - (a * a) / (2 * r * r));
    double B = acos(1 - (b * b) / (2 * r * r));
    double C = 2 * pi - A - B;

    double T = gcd(A, gcd(B, C));
    std::cout << std::fixed << std::setprecision(6) << (pi * r * r * sin(T) / T) << '\n';

    return 0;
}
