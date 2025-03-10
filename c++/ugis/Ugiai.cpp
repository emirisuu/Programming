#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
void Skaitymas(int &n, int Mergaites[], int Berniukai[], int &mergcounter, int &berncounter);
int Suma(int n, int X[]);
int Komanda(int n, int X[]);
void Rasymas(int n, int mergcounter, int berncounter, int Mergaites[], int Berniukai[], int Mokiniai[]);

int main()
{
    int n, Mergaites[100], Berniukai[100], Mokiniai[100], mergcounter = 0, berncounter = 0;
    Skaitymas(n, Mergaites, Berniukai, mergcounter, berncounter);
    Rasymas(n, mergcounter, berncounter, Mergaites, Berniukai, Mokiniai);
    return 0;
}

void Skaitymas(int &n, int Mergaites[], int Berniukai[], int &mergcounter, int &berncounter)
{
    ifstream fd("duomenys.txt");
    int temp;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> temp;
        if(temp > 0) {
            Mergaites[mergcounter] = temp;
            mergcounter++;
        }
        else {
            Berniukai[berncounter] = temp;
            berncounter++;
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

int Komanda(int n, int X[])
{
    int counter = 0, k;
    for(int i = 0; i < n; i++) {
        if(X[i] >= 175) {
            counter++;
        }
    }
    if(counter >= 7) {
        return k = 1;
    }
    else {
        return k = 0;
    }
}

void Rasymas(int n, int mergcounter, int berncounter, int Mergaites[], int Berniukai[], int Mokiniai[])
{
    ofstream fr("rezultatai.txt");
    int moksuma, mergsuma, bernsuma, temp;
    double mokvidurkis, mergvidurkis, bernvidurkis;
    mergsuma = Suma(mergcounter, Mergaites);
    bernsuma = Suma(berncounter, Berniukai);
    moksuma = fabs(bernsuma) + mergsuma;
    mokvidurkis = double(moksuma) / n;
    mergvidurkis = double(mergsuma) / mergcounter;
    bernvidurkis = double(bernsuma) / berncounter;
    fr << fixed << setprecision(2) << mokvidurkis << endl;
    fr << fixed << setprecision(2) << mergvidurkis << endl;
    fr << fixed << setprecision(2) << fabs(bernvidurkis) << endl;
    temp = Komanda(mergcounter, Mergaites);
    if(temp == 1) {
        fr << "Merginu komanda sudaryti galima" << endl;
    }
    else {
        fr << "Merginu komandos sudaryti negalima" << endl;
    }
    temp = Komanda(berncounter, Berniukai);
    if(temp == 1) {
        fr << "Vaikinu komanda sudaryti galima" << endl;
    }
    else {
        fr << "Vaikinu komandos sudaryti negalima" << endl;
    }
    fr.close();
}