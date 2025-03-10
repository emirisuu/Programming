#include <iostream>
#include <fstream>

using namespace std;

struct Komanda
{
    string vardas;
    double ugis;
    int taskai;
};

void Skaitymas(int &n, Komanda A[], double &p, double &k);
int MaksimumasUgis(int n, Komanda A[]);
int MaksimumasTaskai(int n, Komanda A[]);
void Sarasas(int &n, Komanda A[], double p, double k);
void Rasymas(int n, Komanda A[]);

int main()
{
    Komanda A[100];
    int n;
    double p, k;
    Skaitymas(n, A, p, k);
    Sarasas(n, A, p, k);
    Rasymas(n, A);
    return 0;
}

void Skaitymas(int &n, Komanda A[], double &p, double &k)
{
    ifstream fd("krepsininku komanda.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i].vardas >> A[i].ugis >> A[i].taskai;
    }
    fd >> p >> k;
    int index;
    index = MaksimumasUgis(n, A);
    p /= 100;
    k /= 100;
    p *= A[index].ugis;
    p = A[index].ugis - p;
    index = MaksimumasTaskai(n, A);
    k *= A[index].taskai;
    k = A[index].taskai - k;
    fd.close();
}

int MaksimumasUgis(int n, Komanda A[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(A[i].ugis > A[index].ugis) {
            index = i;
        }
    }
    return index;
}

int MaksimumasTaskai(int n, Komanda A[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(A[i].taskai > A[index].taskai) {
            index = i;
        }
    }
    return index;
}

void Salinimas(int &n, Komanda A[], int index)
{
    for(int i = index; i < n; i++) {
        A[i].vardas = A[i + 1].vardas;
        A[i].ugis = A[i + 1].ugis;
        A[i].taskai = A[i + 1].taskai;
    }
    n--;
}

void Sarasas(int &n, Komanda A[], double p, double k)
{
    for(int i = 0; i < n; i++) {
        if(A[i].ugis >= p || A[i].taskai >= k) {
        }
        else {
            Salinimas(n, A, i);
            i--;
        }
    }
}

void Rasymas(int n, Komanda A[])
{
    ofstream fr("krepsininku komandarez.txt");
    if(n == 0) {
        fr << "Kandidatų nėra.";
    }
    else {
        fr << "Vardas       Ūgis    Taškai" << endl;
        for(int i = 0; i < n; i++) {
            fr << A[i].vardas << "        " << A[i].ugis << "    " << A[i].taskai << endl;
        }
    }
    fr.close();
}