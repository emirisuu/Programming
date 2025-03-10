#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(int &n, int D[], double R[], double M[], double K[], double P[]);
double Suma(int n, double R[]);
double Islaidos(int n, double M[], double K[], double P[]);
int Maziausias(int n, double M[], int D[]);
int Didziausias(int n, double P[], int D[]);
void Rasymas(double suma, double islaidos, double santaupos, double viddienos, int minindex, int maxindex, int D[], double M[], double P[]);

int main()
{
    int n, D[100], minindex, maxindex;
    double R[100], M[100], K[100], P[100], suma, santaupos, islaidos, viddienos;
    Skaitymas(n, D, R, M, K, P);
    suma = Suma(n, R);
    islaidos = Islaidos(n, M, K, P);
    santaupos = suma - islaidos;
    viddienos = islaidos / n;
    minindex = Maziausias(n, M, D);
    maxindex = Didziausias(n, P, D);
    Rasymas(suma, islaidos, santaupos, viddienos, minindex, maxindex, D, M, P);
    return 0;
}

void Skaitymas(int &n, int D[], double R[], double M[], double K[], double P[])
{
    ifstream fd("duomenys1.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> D[i] >> R[i] >> M[i] >> K[i] >> P[i];
    }
    fd.close();
}

double Suma(int n, double R[])
{
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += R[i];
    }
    return suma;
}

double Islaidos(int n, double M[], double K[], double P[])
{
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += M[i] + K[i] + P[i];
    }
    return suma;
}

int Maziausias(int n, double M[], int D[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(M[i] < M[index]) {
            index = i;
        }
        else if(M[i] == M[index]) {
            if(D[i] < D[index]) {
                index = i;
            }
        }
    }
    return index;
}

int Didziausias(int n, double P[], int D[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(P[i] > P[index]) {
            index = i;
        }
        else if(P[i] == P[index]) {
            if(D[i] > D[index]) {
                index = i;
            }
        }
    }
    return index;
}

void Rasymas(double suma, double islaidos, double santaupos, double viddienos, int minindex, int maxindex, int D[], double M[], double P[])
{
    ofstream fr("rezultatai1.txt");
    fr << fixed << setprecision(2) << suma << endl;
    fr << fixed << setprecision(2) << islaidos << endl;
    fr << fixed << setprecision(2) << santaupos << endl;
    fr << fixed << setprecision(2) << viddienos << endl;
    fr << D[minindex] << " " << fixed << setprecision(2) << M[minindex] << endl;
    fr << D[maxindex] << " " << fixed << setprecision(2) << P[maxindex];
    fr.close();
}