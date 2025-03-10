#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int A[], int C[], int &n, double B[]);
double Suma(int n, double B[], int A[]);
int Kiekis(int n, int A[]);
int Maksimumas(int A[], int C[], int n, double B[]);
int Minimumas(int A[], int C[], int n, double B[]);
void Rasymas(int kiekis, double suma, int maxrusis, double maxkaina, int minrusis, int minkiekis);

int main()
{
    int A[100], C[100], n, kiekis, maxrusis, minkiekis, minrusis, index;
    double suma, B[100], maxkaina;
    Skaitymas(A, C, n, B);
    suma = Suma(n, B, A);
    kiekis = Kiekis(n, A);
    index = Maksimumas(A, C, n, B);
    maxrusis = C[index];
    maxkaina = B[index];
    index = Minimumas(A, C, n, B);
    minrusis = C[index];
    minkiekis = A[index];
    Rasymas(kiekis, suma, maxrusis, maxkaina, minrusis, minkiekis);
    return 0;
}

void Skaitymas(int A[], int C[], int &n, double B[])
{
    ifstream fd("lempos.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i] >> B[i] >> C[i];
    }
    fd.close();
}

double Suma(int n, double B[], int A[])
{
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += B[i] * A[i];
    }
    return suma;
}

int Kiekis(int n, int A[])
{
    int kiekis = 0;
    for(int i = 0; i < n; i++) {
        kiekis += A[i];
    }
    return kiekis;
}

int Maksimumas(int A[], int C[], int n, double B[])
{
    int index = 0;
    double temp = B[0];
    for(int i = 0; i < n; i++) {
        if(B[i] > temp) {
            temp = B[i];
            index = i;
        }
        else if(B[i] == temp && C[i] > C[index]) {
            index = i;
        }
    }
    return index;
}

int Minimumas(int A[], int C[], int n, double B[])
{
    int index = 0, temp = A[0];
    for(int i = 0; i < n; i++) {
        if(A[i] < temp) {
            temp = A[i];
            index = i;
        }
        else if(A[i] == temp && C[i] < C[index]) {
            index = i;
        }
    }
    return index;
}

void Rasymas(int kiekis, double suma, int maxrusis, double maxkaina, int minrusis, int minkiekis)
{
    ofstream fr("lemposrez.txt");
    fr << fixed << setprecision(2) << suma << endl;
    fr << kiekis << endl;
    fr << maxrusis << " " << maxkaina << endl;
    fr << minkiekis << " " << minrusis;
    fr.close();
}
