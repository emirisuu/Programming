#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fd("duomenys.txt");
ofstream fr("rezultatai.txt");
double Plotas(double ilgis, double plotis);
double DangosKaina(double plotas, double kaina, double nuostoliai);
int main()
{
    int n;
    double ilgis, plotis, kaina, suma = 0, plotas, temp, nuostoliai;
    fd >> n >> nuostoliai;
    for(int i = 0; i < n; i++) {
        fd >> ilgis >> plotis >> kaina >> temp;
        plotas = Plotas(ilgis, plotis);
        suma += DangosKaina(plotas, kaina, nuostoliai);
    }
    fd.close();
    fr << fixed << setprecision(2) << suma;
    fr.close();
    return 0;
}

double Plotas(double ilgis, double plotis)
{
    return ilgis * plotis;
}

double DangosKaina(double plotas, double kaina, double nuostoliai)
{
    return (plotas * nuostoliai) * kaina;
}