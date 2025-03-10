#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int &n, int D[][100]);
void Sumavimas(int n, int D[][100], int S[], int &dienukiekis);
void Rikiavimas(int n, int S[]);
int Suma(int n, int S[]);
void Rasymas(int n, int S[], int suma, double vid);

int main()
{
    int n, D[100][100], S[100], suma, dienukiekis;
    double vid;
    Skaitymas(n, D);
    Sumavimas(n, D, S, dienukiekis);
    Rikiavimas(n, S);
    suma = Suma(n, S);
    vid = double(suma) / dienukiekis;
    Rasymas(n, S, suma, vid);
    return 0;
}

void Skaitymas(int &n, int D[][100])
{
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> D[i][0];
        for(int j = 1; j <= D[i][0]; j++) {
            fd >> D[i][j];
        }
    }
    fd.close();
}

void Sumavimas(int n, int D[][100], int S[], int &dienukiekis)
{
    for(int i = 0; i < n; i++) {
        S[i] = 0;
        dienukiekis += D[i][0];
        for(int j = 1; j <= D[i][0]; j++) {
            S[i] += D[i][j];
        }
    }
}

void Rikiavimas(int n, int S[])
{
    int temp, index;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++){
            if(S[j] > S[index]) {
                index = j;
            }
        }
        temp = S[i];
        S[i] = S[index];
        S[index] = temp;
    }
}

int Suma(int n, int S[])
{
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += S[i];
    }
    return suma;
}

void Rasymas(int n, int S[], int suma, double vid)
{
    ofstream fr("rezultatai.txt");
    for(int i = 0; i < n; i++) {
        fr << S[i] << endl;
    }
    fr << suma << endl;
    fr << fixed << setprecision(1) << vid;
}