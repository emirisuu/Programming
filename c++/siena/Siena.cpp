#include <iostream>
#include <fstream>

using namespace std;
ifstream fd("duomenys.txt");
ofstream fr("rezultatai.txt");
int Plotas(int x1, int x2, int y1, int y2);
int main()
{
    int p, a, x1, x2, y1, y2, n, s;
    fd >> p >> a;
    fd >> n;
    s = p * a;
    for(int i = 0; i < n; i ++) {
        fd >> x1 >> y1 >> x2 >> y2;
        s -= Plotas(x1, x2, y1, y2);
    }
    fd.close();
    fr << s;
    fr.close();
    return 0;
}

int Plotas(int x1, int x2, int y1, int y2)
{
    int x, y;
    x = x2 - x1;
    y = y2 - y1;
    return x * y;
}