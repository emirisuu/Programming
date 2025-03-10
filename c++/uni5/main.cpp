#include <iostream>
#include <fstream>
#include <iomanip>
#include "funkcijos.h"

using namespace std;

struct SandelioTurtas
{
    string pavadinimas;
    double kaina;
    int kiekis;
};

struct CechoUzsakymas
{
    string pavadinimas;
    int kiekis;
};

void Skaitymas(int &n, int &m, int &k, SandelioTurtas *&A, CechoUzsakymas *&B);
void Skaiciavimai(SandelioTurtas *&A, SandelioTurtas *&C, CechoUzsakymas *&B, int &n, int &m, int &z);
void Rikiavimas(SandelioTurtas *&C, int z);
void Rasymas(SandelioTurtas *C, int z);

int main()
{
    SandelioTurtas *A, *C;
    int n = 0, m = 0, k = 0, z = 0;
    A = new SandelioTurtas[1000];
    CechoUzsakymas *B;
    B = new CechoUzsakymas[1000];
    Skaitymas(n, m, k, A, B);
    if(k == 1) cout << "Ivestas neteisingas duomenu formatas. Prasome pataisyti duomenu faila.\n" << "Failui F1.txt duomenis veskite formatu(x yra skaiciai) - abcdef xx.xx x\n" << "Failui F1.txt duomenis veskite formatu(x yra skaiciai) - abcdef x\n";
    else {
        Skaiciavimai(A, C, B, n, m, z);
        Rasymas(C, z);
    }
    return 0;
}

void Skaitymas(int &n, int &m, int &k, SandelioTurtas *&A, CechoUzsakymas *&B)
{
    string temp, temp1, temp2;
    ifstream fd1("F1.txt");
    while(!fd1.eof()){
        fd1 >> temp >> temp1 >> temp2;
        if(temp == A[n - 1].pavadinimas && stod(temp1) == A[n - 1].kaina && stoi(temp2) == A[n - 1].kiekis) continue;
        if(Zodis(temp) || NesveikasSkaicius(temp1) || SveikasSkaicius(temp2)) {
            k = 1;
            return;
        }
        A[n].pavadinimas = temp;
        A[n].kaina = stod(temp1);
        A[n].kiekis = stoi(temp2);
        n++;
    }
    fd1.close();
    ifstream fd2("F2.txt");
    while(!fd2.eof()){
        fd2 >> temp >> temp1;
        if(temp == B[n - 1].pavadinimas && stoi(temp1) == B[n - 1].kiekis) continue;
        if(Zodis(temp) || SveikasSkaicius(temp1)){
            k = 1;
            return;
        }
        B[m].pavadinimas = temp;
        B[m].kiekis = stoi(temp1);
        m++;
    }
    fd2.close();
}

void Skaiciavimai(SandelioTurtas *&A, SandelioTurtas *&C, CechoUzsakymas *&B, int &n, int &m, int &z)
{
    C = new SandelioTurtas[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i].pavadinimas == B[j].pavadinimas && A[i].kiekis >= B[j].kiekis) {
                C[z].pavadinimas = A[i].pavadinimas;
                C[z].kaina = A[i].kaina;
                C[z].kiekis = B[j].kiekis;
                z++;
                A[i].kiekis -= B[j].kiekis;
                break;
            }
        }
    }
    delete []B;
    Rikiavimas(C, z);
}

void Rikiavimas(SandelioTurtas *&C, int z)
{
    SandelioTurtas temp;
    int index;
    for(int i = 0; i < z; i++) {
        index = i;
        for(int j = i + 1; j < z; j++) {
            if(C[j].kiekis == C[index].kiekis) {
                if(C[j].kaina > C[index].kaina) index = j;
            }
            else if(C[j].kiekis > C[index].kiekis) index = j;
        }
        temp = C[i];
        C[i] = C[index];
        C[index] = temp;
    }
}

void Rasymas(SandelioTurtas *C, int z)
{
    ofstream fr("rezultatai.txt");
    fr << "eil.nr. " << setw(10) << "pavadinimas " << setw(7) << "kiekis " << setw(7) << "kaina" << endl;
    for(int i = 0; i < z; i++) {
        fr << setw(7) << i + 1 << " " << setw(11) << C[i].pavadinimas << " " << setw(6) << C[i].kiekis << " " << setw(7) << C[i].kaina << endl;
    }
    fr.close();
}