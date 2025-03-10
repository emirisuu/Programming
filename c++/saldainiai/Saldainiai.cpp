#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int &n, double Kaina[], int Rusis[], int Kg[]);
double Suma(int n, double X[], int Z[]);
int Maksimumas(int n, int X[]);
int Minimumas(int n, double X[], int Z[]);
void Rasymas(double Kaina[], int Rusis[], int Kg[], int maxindex, int minindex, double sv, double kv);
int Suma1(int n, int X[]);

int main()
{
    int n, Rusis[100], Kg[100], maxindex, minindex;
    double Kaina[100], sv, kv;
    Skaitymas(n, Kaina, Rusis, Kg);
    sv = Suma(n, Kaina, Kg);
    kv = Suma1(n, Kg);
    maxindex = Maksimumas(n, Kg);
    minindex = Minimumas(n, Kaina, Kg);
    Rasymas(Kaina, Rusis, Kg, maxindex, minindex, sv, kv);
    return 0;
}

void Skaitymas(int &n, double Kaina[], int Rusis[], int Kg[])
{
    ifstream fd("saldainiai.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> Kaina[i] >> Rusis[i] >> Kg[i];
    }
    fd.close();
}

double Suma(int n, double X[], int Z[])
{
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += X[i] * Z[i];
    }
    return suma;
}

int Maksimumas(int n, int X[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(X[i] >= X[index]) {
            index = i;
        }
    }
    return index;
}

int Minimumas(int n, double X[], int Z[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(X[i] * Z[i] < X[index] * Z[index]) {
            index = i;
        }
    }
    return index;
}

void Rasymas(double Kaina[], int Rusis[], int Kg[], int maxindex, int minindex, double sv, double kv)
{
    ofstream fr("saldainiairez.txt");
    fr << fixed << setprecision(2) << sv << endl;
    fr << Rusis[maxindex] << " " << Kg[maxindex] << endl;
    fr << Rusis[minindex] << " " << Kaina[minindex] << endl;
    fr << fixed << setprecision(0) << kv;
    fr.close();
}

int Suma1(int n, int X[])
{
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += X[i];
    }
    return suma;
}