#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void Skaitymas(int &n, int &kcounter, int &fcounter, int &scounter, int Kugis[], int Fugis[], int Sugis[], char Klytis[], char Flytis[], char Slytis[]);
int Kiek(int n, char X[]);
double Vidurkis(int n, int X[]);
void Rasymas(int &n, int &kcounter, int &fcounter, int &scounter, int Kugis[], int Fugis[], int Sugis[], char Klytis[], char Flytis[], char Slytis[], int kv, int km, int fv, int fm, int sv, int sm);
void Rikiavimas(int n, int X[]);

int main()
{
    int n, kcounter = 0, fcounter = 0, scounter = 0, km, kv, fm, fv, sm, sv, Kugis[100], Fugis[100], Sugis[100];
    char Klytis[100], Flytis[100], Slytis[100];
    Skaitymas(n, kcounter, fcounter, scounter, Kugis, Fugis, Sugis, Klytis, Flytis, Slytis);
    kv = Kiek(kcounter, Klytis);
    km = kcounter - kv;
    fv = Kiek(fcounter, Flytis);
    fm = fcounter - fv;
    sv = Kiek(scounter, Slytis);
    sm = scounter - sv;
    Rasymas(n, kcounter, fcounter, scounter, Kugis, Fugis, Sugis, Klytis, Flytis, Slytis, kv, km, fv, fm, sv, sm);
    return 0;
}

void Skaitymas(int &n, int &kcounter, int &fcounter, int &scounter, int Kugis[], int Fugis[], int Sugis[], char Klytis[], char Flytis[], char Slytis[])
{
    ifstream fd("duomenys.txt");
    int tempu;
    char templ, temps;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> templ >> tempu >> temps;
        if(temps == 'K') {
            Klytis[kcounter] = templ;
            Kugis[kcounter] = tempu;
            kcounter++;
        }
        else if(temps == 'F') {
            Flytis[fcounter] = templ;
            Fugis[fcounter] = tempu;
            fcounter++;
        }
        else {
            Slytis[scounter] = templ;
            Sugis[scounter] = tempu;
            scounter++;
        }
    }
    fd.close();
}

int Kiek(int n, char X[])
{
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if(X[i] == 'V') {
            counter++;
        }
    }
    return counter;
}

double Vidurkis(int n, int X[])
{
    double suma = 0, vidurkis;
    for(int i = 0; i < n; i++) {
        suma += X[i];
    }
    vidurkis = suma / n;
    return vidurkis;
}

void Rikiavimas(int n, int X[])
{
    int index, temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++) {
            if(X[j] < X[index]) {
                index = j;
            }
        }
        temp = X[i];
        X[i] = X[index];
        X[index] = temp;
    }
}

void Rasymas(int &n, int &kcounter, int &fcounter, int &scounter, int Kugis[], int Fugis[], int Sugis[], char Klytis[], char Flytis[], char Slytis[], int kv, int km, int fv, int fm, int sv, int sm)
{
    ofstream fr("rezultatai.txt");
    double vidurkis;
    fr << "zaidzia krepsini " << kcounter << endl;
    if(kcounter >= 7) {
        fr << "Komanda sudaro vaikinai " << kv << " merginos " << km << endl;
        for(int i = 0; i < kcounter; i++) {
            fr << Klytis[i] << " " << Kugis[i] << endl;
        }
        vidurkis = Vidurkis(kcounter, Kugis);
        fr << "Krepsinio komandos ugio vidurkis " << fixed << setprecision(2) << vidurkis << endl;
    }
    else {
        fr << "Krepsinio komandos sudaryti negales" << endl;
    }
    fr << "zaidzia futbola " << fcounter << endl;
    if(fcounter >= 12) {
        fr << "Komanda sudaro vaikinai " << fv << " merginos " << fm << endl;
        for(int i = 0; i < fcounter; i++) {
            fr << Flytis[i] << " " << Fugis[i] << endl;
        }
    }
    else {
        fr << "Futbolo komandos sudaryti negalima" << endl;
    }
    fr << "Komandu palaikymo grupe " << scounter << endl;
    fr << "Komanda sudaro vaikinai " << sv << " merginos " << sm << endl;
    Rikiavimas(scounter, Sugis);
        for(int i = 0; i < scounter; i++) {
            fr << Sugis[i] << endl;
        }
    fr.close();
}
