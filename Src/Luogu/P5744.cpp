#include <bits/stdc++.h>
using namespace std;

struct node
{
    string name;
    int age;
    int score;
} student[5];

int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> student[i].name >> student[i].age >> student[i].score;
    for (int i = 0; i < n; i++)
    {
        cout << student[i].name << " " << student[i].age + 1 << " ";

        if (student[i].score * 1.2 >= 600)
            cout << 600 << endl;
        else
            cout << student[i].score * 1.2 << endl;
    }
    return 0;
}