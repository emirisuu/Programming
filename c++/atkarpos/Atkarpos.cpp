#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
ifstream fd("atkarpos.txt");
ofstream fr("atkarpos.rez.txt");
double Perimetras(double a1, double a2, double a3);
bool Trikampis(double a1, double a2, double a3);
double Plotas(double a1, double a2, double a3, double p);
int main()
{
    int n;
    double a1, a2, a3, perimetras, plotas, pusperimetris;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> a1 >> a2 >> a3;
        if(Trikampis(a1, a2, a3)) {
            perimetras = Perimetras(a1, a2, a3);
            pusperimetris =  perimetras / 2;
            plotas = Plotas(a1, a2, a3, pusperimetris);
            fr << fixed << setprecision(2) << a1 << " " << a2 << " " << a3 << " " << perimetras << " " << plotas << endl;
        }
    }
    fd.close();
    fr.close();
    return 0;
}

double Perimetras(double a1, double a2, double a3)
{
    return a1 + a2 + a3;
}

bool Trikampis(double a1, double a2, double a3)
{
    if(a1 + a2 > a3 && a1 + a3 > a2 && a2 + a3 > a1) {
        return true;
    }
    return false;
}

double Plotas(double a1, double a2, double a3, double p)
{
    return sqrt(p * (p - a1) * (p - a2) * (p - a3));
}
