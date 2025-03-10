#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int &n, int S[], int N[]);
void Vidurkis(int n, int S[], double V[]);
void Rikiavimas(int n, double V[], int N[]);
void Rasymas(int n, double V[], int N[]);
int Suma(int A[]);

int main()
{
    int n, S[100], N[100];
    double V[100];
    Skaitymas(n, S, N);
    Vidurkis(n, S, V);
    Rikiavimas(n, V, N);
    Rasymas(n, V, N);
    return 0;
}

void Skaitymas(int &n, int S[], int N[])
{
    ifstream fd("duomenys.txt");
    int A[100];
    fd >> n;
    for(int i = 0; i < n; i++) {
        N[i] = i + 1;
        for(int j = 0; j < 7; j++) {
            fd >> A[j];
        }
        S[i] = Suma(A);
    }
    fd.close();
}

int Suma(int A[])
{
    int suma = 0;
    for(int i = 0; i < 7; i++) {
        suma += A[i];
    }
    return suma;
}

void Vidurkis(int n, int S[], double V[])
{
    for(int i = 0; i < 7; i++) {
        V[i] = double(S[i]) / 7;
    }
}

void Rikiavimas(int n, double V[], int N[])
{
    int index;
    double temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++){
            if(V[j] > V[index]) {
                index = j;
            }
        }
        temp = V[i];
        V[i] = V[index];
        V[index] = temp;
        temp = N[i];
        N[i] = N[index];
        N[index] = temp;
    }
}

void Rasymas(int n, double V[], int N[])
{
    ofstream fr("rezultatai.txt");
    for(int i = 0; i < n; i++) {
        fr << N[i] << " " << fixed << setprecision(3) << V[i] << endl;
    }
    fr.close();
}
