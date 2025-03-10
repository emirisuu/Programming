#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int A[], int &n);
void Rasymas(int suma, int nelijo, double vidurkis);
void SumaIrNelijo(int n, int A[], int &nelijo, int &suma);

int main()
{
    int n, A[100], nelijo = 0, suma = 0;
    double vidurkis;
    Skaitymas(A, n);
    SumaIrNelijo(n, A, nelijo, suma);
    vidurkis = suma / (n - nelijo);
    Rasymas(suma, nelijo, vidurkis);
    return 0;
}

void Skaitymas(int A[], int &n)
{
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i];
    }
    fd.close();
}

void Rasymas(int suma, int nelijo, double vidurkis)
{
    ofstream fr("rezultatai.txt");
    fr << "Is viso iskrito krituliu (mm): " << suma << endl;
    fr << "Nelijo (dienas): " << nelijo << endl;
    fr << "Vidutiniskai kiekviena lietinga diena iskrito krituliu (mm): " << vidurkis;
    fr.close();
}

void SumaIrNelijo(int n, int A[], int &nelijo, int &suma)
{
    for(int i = 0; i < n; i++) {
        suma += A[i];
        if(A[i] == 0) {
            nelijo++;
        }
    }
}