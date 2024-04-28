#include <bits/stdc++.h>

using i64 = long long;
struct node
{
    int id;
    double sc1, sc2;
    int score;
    double final_score;
} a[1000];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].id >> a[i].sc1 >> a[i].sc2;
        a[i].score = a[i].sc1 + a[i].sc2;
        a[i].final_score = a[i].sc1 * 7 + a[i].sc2 * 3;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].score > 140 && a[i].final_score >= 800)
            std::cout << "Excellent" << std::endl;
        else
            std::cout << "Not excellent" << std::endl;
    }
    return 0;
}