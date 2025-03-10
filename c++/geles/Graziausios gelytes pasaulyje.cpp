#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int A[], int C[], int &n, double B[]);
double Suma(int n, double B[], int C[]);
int Kiekis(int n, int C[]);
int Maksimumas(int A[], int C[], int n, double B[]);
int Minimumas(int A[], int C[], int n, double B[]);
void Rasymas(int kiekis, double suma, int maxrusis, int maxkiekis, int minrusis, double minkaina);

int main()
{
    int A[100], C[100], n, kiekis, maxrusis, maxkiekis, minrusis, index;
    double suma, B[100], minkaina;
    Skaitymas(A, C, n, B);
    suma = Suma(n, B, C);
    kiekis = Kiekis(n, C);
    index = Maksimumas(A, C, n, B);
    maxrusis = A[index];
    maxkiekis = C[index];
    index = Minimumas(A, C, n, B);
    minrusis = A[index];
    minkaina = B[index];
    Rasymas(kiekis, suma, maxrusis, maxkiekis, minrusis, minkaina);
    return 0;
}

void Skaitymas(int A[], int C[], int &n, double B[])
{
    ifstream fd("geles.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i] >> B[i] >> C[i];
    }
    fd.close();
}

double Suma(int n, double B[], int C[])
{
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += B[i] * C[i];
    }
    return suma;
}

int Kiekis(int n, int C[])
{
    int kiekis = 0;
    for(int i = 0; i < n; i++) {
        kiekis += C[i];
    }
    return kiekis;
}

int Maksimumas(int A[], int C[], int n, double B[])
{
    int index = 0, temp = C[0];
    for(int i = 0; i < n; i++) {
        if(C[i] > temp) {
            temp = C[i];
            index = i;
        }
    }
    return index;
}

int Minimumas(int A[], int C[], int n, double B[])
{
    int index = 0, temp = B[0];
    for(int i = 0; i < n; i++) {
        if(B[i] < temp) {
            temp = B[i];
            index = i;
        }
    }
    return index;
}

void Rasymas(int kiekis, double suma, int maxrusis, int maxkiekis, int minrusis, double minkaina)
{
    ofstream fr("gelesrez.txt");
    fr << kiekis << endl;
    fr << fixed << setprecision(2) << suma << endl;
    fr << maxrusis << " " << maxkiekis << endl;
    fr << minrusis << " " << minkaina;
    fr.close();
}
