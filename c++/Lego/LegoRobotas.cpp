#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int &k, double Pinigai[], double &kaina);
double Suma(int n, double X[]);
int Maksimumas(int n, double X[]);
void Rikiavimas(int n, double X[]);
void Rasymas(int k, double total, double kaina, double Pinigai[]);

int main()
{
    int k;
    double Pinigai[100], total, kaina;
    Skaitymas(k, Pinigai, kaina);
    total = Suma(k, Pinigai);
    Rasymas(k, total, kaina, Pinigai);
    return 0;
}

void Skaitymas(int &k, double Pinigai[], double &kaina)
{
    ifstream fd("duomenys.txt");
    fd >> k;
    int n;
    double A[100];
    for(int i = 0; i < k; i++) {
        fd >> n;
        for(int j = 0; j < n; j++) {
            fd >> A[j];
        }
        Pinigai[i] = Suma(n, A);
    }
    fd >> kaina;
    fd.close();
}

double Suma(int n, double X[])
{
    double suma = 0;
    for(int i = 0; i < n; i++) {
        suma += X[i];
    }
    return suma;
}

int Maksimumas(int n, double X[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(X[i] > X[index]) {
            index = i;
        }
    }
    return index;
}

void Rikiavimas(int n, double X[])
{
    int index;
    double temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++) {
            if(X[j] > X[index]) {
                index = j;
            }
        }
        temp = X[i];
        X[i] = X[index];
        X[index] = temp;
    }
}

void Rasymas(int k, double total, double kaina, double Pinigai[])
{
    ofstream fr("rezultatai.txt");
    int index;
    index = Maksimumas(k, Pinigai);
    Rikiavimas(k, Pinigai);
    fr << k << " " << total << endl;
    if(total >= kaina) {
        fr << "Uzteks" << endl;
    }
    else {
        fr << "Neuzteks" << endl;
    }
    fr << index + 1 << endl;
    for(int i = 0; i < k; i++) {
        fr << fixed << setprecision(2) << Pinigai[i] << endl;
    }
    fr.close();
}