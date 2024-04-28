#include <iostream>
using namespace std;
long long a = 1, b = 1, c = 0; 
int n, i;
int main()
{
    cin >> n;
    for (i = 3; i <= n; i++)
    { 
        c = a + b;
        a = b;
        b = c;
    }
    cout << c << ".00"; 
    return 0;
}
