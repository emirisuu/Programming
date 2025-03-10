#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int &n, int &suma, int Obuoliai[], int Temperatura[], double Laikas[]);
int Suma(int n, int X[]);
void Salinimas(int &n, int Obuoliai[], int Temperatura[], double Laikas[], int index);
void Rasymas(int n, int suma, int Obuoliai[], int Temperatura[], double Laikas[]);

int main()
{
    int n, suma, Obuoliai[100], Temperatura[100];
    double Laikas[100];
    Skaitymas(n, suma, Obuoliai, Temperatura, Laikas);
    Rasymas(n, suma, Obuoliai, Temperatura, Laikas);
    return 0;
}

void Skaitymas(int &n, int &suma, int Obuoliai[], int Temperatura[], double Laikas[])
{
    ifstream fd("pyragai.txt");
    int temperatura;
    double laikas;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> Obuoliai[i] >> Temperatura[i] >> Laikas[i];
    }
    fd >> laikas >> temperatura;
    suma = Suma(n, Obuoliai);
    for(int i = 0; i < n; i++) {
        if(temperatura < Temperatura[i] || laikas < Laikas[i]) {
            Salinimas(n, Obuoliai, Temperatura, Laikas, i);
            i--;
        }
    }
    fd.close();
}

int Suma(int n, int X[])
{
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += X[i];
    }
    return suma;
}

void Salinimas(int &n, int Obuoliai[], int Temperatura[], double Laikas[], int index)
{
    for(int i = index; i < n - 1; i++) {
        Obuoliai[i] = Obuoliai[i + 1];
        Temperatura[i] = Temperatura[i + 1];
        Laikas[i] = Laikas[i + 1];
    }
    n--;
}

void Rasymas(int n, int suma, int Obuoliai[], int Temperatura[], double Laikas[])
{
    ofstream fr("pyragairez.txt");
    fr << suma << endl;
    for(int i = 0; i < n; i++) {
        fr << Obuoliai[i] << " " << Temperatura[i] << " " << fixed << setprecision(2) << Laikas[i] << endl;
    }
    fr.close();
}