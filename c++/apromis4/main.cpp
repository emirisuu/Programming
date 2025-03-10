#include <iostream>

using namespace std;

int main()
{
    int n, m , x, y;
    cin >> n >> m;
    y = m / 2 - n;
    x = n - y;
    cout << y;
    if(y % 10 == 1 && y % 100 != 11)
        cout << " triusis ir ";
    else if((y % 10 == 0) || (y % 100 >= 11 && y % 100 <= 19))
        cout << " triusiu ir ";
    else
        cout << " triusiai ir ";
    cout << x;
    if(x % 10 == 1 && x % 100 != 11)
        cout << " vista";
    else if((x % 10 == 0) || (x % 100 >= 11 && x % 100 <= 19))
        cout << " vistu";
    else
        cout << " vistos";
    return 0;
}