#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Mokesciai
{
    string vardas;
    double siluma;
    double telefonas;
    double vanduo;
    double moketi;
};

void Skaitymas(int &n, Mokesciai A[]);
void Skaiciavimai(int &n, Mokesciai A[], double &siluma, double &telefonas, double &vanduo);
void Salinimas(int &n, Mokesciai A[], int index);
void Rasymas(int n, Mokesciai A[], double siluma, double telefonas, double vanduo);

int main()
{
    Mokesciai A[100];
    int n; 
    double siluma = 0, telefonas = 0, vanduo = 0;
    Skaitymas(n, A);
    Skaiciavimai(n, A, siluma, telefonas, vanduo);
    Rasymas(n, A, siluma, telefonas, vanduo);
    return 0;
}

void Skaitymas(int &n, Mokesciai A[])
{
    ifstream fd("mokesciai.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i].vardas >> A[i].siluma >> A[i].telefonas >> A[i].vanduo;
        A[i].moketi = 0;
    }
    fd.close();
}

void Skaiciavimai(int &n, Mokesciai A[], double &siluma, double &telefonas, double &vanduo)
{
    for(int i = 0; i < n; i++) {
        if(A[i].siluma > 0) {
            A[i].moketi += A[i].siluma;
            siluma += A[i].siluma;
        }
        if(A[i].telefonas > 0) {
            A[i].moketi += A[i].telefonas;
            telefonas += A[i].telefonas;
        }
        if(A[i].vanduo > 0) {
            A[i].moketi += A[i].vanduo;
            vanduo += A[i].vanduo;
        }
    }
    for(int i = 0; i < n; i++) {
        if(A[i].moketi == 0) {
            Salinimas(n, A, i);
            i--;
        }
    }
}

void Rasymas(int n, Mokesciai A[], double siluma, double telefonas, double vanduo)
{
    ofstream fr("mokesciairez.txt");
    fr << "Už šilumą turi būti sumokėta: " << siluma << endl;
    fr << "Už telefoną turi būti sumokėta: " << telefonas << endl;
    fr << "Už vandenį turi būti sumokėta: " << vanduo << endl;
    fr << "Vardas              Turi mokėti" << endl;
    for(int i = 0; i < n; i++) {
        fr << A[i].vardas << "              " << fixed << setprecision(2) << A[i].moketi << endl;
    }
    fr.close();
}

void Salinimas(int &n, Mokesciai A[], int index)
{
    for(int i = index; i < n; i++) {
        A[i].vardas = A[i + 1].vardas;
        A[i].siluma = A[i + 1].siluma;
        A[i].telefonas = A[i + 1].telefonas;
        A[i].vanduo = A[i + 1].vanduo;
        A[i].moketi = A[i + 1].moketi;
    }
    n--;
}