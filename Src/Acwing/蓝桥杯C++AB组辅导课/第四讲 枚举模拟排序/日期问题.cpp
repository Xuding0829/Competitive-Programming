#include <bits/stdc++.h>

using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int year, int month, int day)
{
    if (month == 0 || month > 12)
        return false;
    if (day == 0 || month != 2 && days[month] < day)
        return false;
    if (month == 2)
    {
        int leap = year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
        if (day > 28 + leap)
            return false;
    }
    return true;
}

signed main()
{
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);

    for (int i = 19600101; i <= 20591231; i++)
    {
        int year = i / 10000;
        int month = i / 100 % 100;
        int day = i % 100;
        if (check(year, month, day))
            if (year % 100 == a && month == b && day == c ||
                month == a && day == b && year % 100 == c ||
                day == a && month == b && year % 100 == c)

                printf("%d-%02d-%02d\n", year, month, day);
    }
    return 0;
}

