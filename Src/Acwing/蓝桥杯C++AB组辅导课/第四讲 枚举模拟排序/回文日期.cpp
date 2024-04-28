#include <bits/stdc++.h>

using namespace std;

int res;
int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date)
{
    int year = date / 10000;
    int month = date / 100 % 100;
    int day = date % 100;

    if (month > 12 || month == 0)
        return false;

    if (months[month] < day && month != 2 || day == 0)
        return false;

    if (month == 2)
    {
        int leap = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
        // cout << year << ' ' << leap << endl;
        if (day > months[2] + leap)
            return false;
    }

    return true;
}

signed main()
{
    int date1, date2;
    cin >> date1 >> date2;
    for (int i = 1000; i <= 9999; i++)
    {
        int tmp = i, date = 0;
        while (tmp)
        {
            date = date * 10 + tmp % 10;
            tmp /= 10;
        }
        date = i * 10000 + date;
        // cout << date << endl;
        if (check(date) && date1 <= date && date <= date2)
            res++;
    }
    cout << res << endl;
    return 0;
}
