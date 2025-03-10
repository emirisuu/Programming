#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &n, int A[][100]);
void Masyvas(int n, int A[][100], int B[]);
int Suma(int n, int A[][100]);
void Rasymas(int n, int B[]);

int main()
{
    int n, A[100][100], B[100];
    Skaitymas(n, A);
    Masyvas(n, A, B);
    Rasymas(n, B);
    return 0;
}

void Skaitymas(int &n, int A[][100])
{
    ifstream fd("duom.txt");
    fd >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            fd >> A[i][j];
    fd.close();
}

void Masyvas(int n, int A[][100], int B[])
{
    for(int i = 0; i < n; i++) {
        B[i] = Suma(i, A);
    }
}

int Suma(int n, int A[][100])
{
    int suma = 0;
    for(int i = 0; i < n + 1; i++)
        suma += A[n][i];
    return suma;
}

void Rasymas(int n, int B[])
{
    ofstream fr("rez.txt");
    for(int i = 0; i < n; i++)
        fr << B[i] << " ";
    fr.close();
}