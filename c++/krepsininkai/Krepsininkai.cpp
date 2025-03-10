#include <iostream>
#include <fstream>

using namespace std;

struct Taskai
{
    string vardas;
    int taskai;
};

void Skaitymas(int &n, Taskai A[]);
int Suma(int n, Taskai A[]);
void Salinimas(int &n, Taskai A[], int index);
int Maksimumas(int n, Taskai A[]);
void Rasymas(int n, Taskai A[]);

int main()
{
    Taskai A[100];
    int n;
    Skaitymas(n, A);
    Rasymas(n, A);
    return 0;
}

void Skaitymas(int &n, Taskai A[])
{
    ifstream fd("krepsininkai.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i].vardas >> A[i].taskai;
    }
    fd.close();
}

int Suma(int n, Taskai A[])
{
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += A[i].taskai;
    }
    return suma;
}

void Salinimas(int &n, Taskai A[], int index)
{
    for(int i = index; i < n; i++) {
        A[i].vardas = A[i + 1].vardas;
        A[i].taskai = A[i + 1].taskai;
    }
    n--;
}

int Maksimumas(int n, Taskai A[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(A[i].taskai > A[index].taskai) {
            index = i;
        }
    }
    return index;
}

void Rasymas(int n, Taskai A[])
{
    ofstream fr("krepsininkairez.txt");
    int index, vidurkis, suma;
    if(n == 0) {
        fr << "Mokinių dalyvavusių rungtynese nebuvo";
    }
    else {
        index = Maksimumas(n, A);
        int taskai;
        string vardas;
        vardas = A[index].vardas;
        taskai = A[index].taskai;
        suma = Suma(n, A);
        vidurkis = suma / n;
        for(int i = 0; i < n; i++) {
            if(A[i].taskai < 15) {
                Salinimas(n, A, i);
                i--;
            }
        }
        fr << "Mokinių surinkusių ne mažiau kaip 15 taškų sarašas" << endl;
        if(n == 0) {
            fr << "Mokinių surinkusių ne mažiau kaip 15 taškų nebuvo." << endl;
        }
        else {
            fr << "Vardas           Taškai" << endl;
            for(int i = 0; i < n; i++) {
                fr << A[i].vardas << "          " << A[i].taskai << endl;
            }
        }
        if(taskai >= 15) {
            fr << "Taikliausias krepšininkas buvo " << vardas << endl;
        }
        else {
            fr << "Taikliausias krepšininkas buvo " << vardas << ", tačiau nesurinko 15 taškų" << endl;
        }
        fr << "Klasės mokinys vidutiniškai surinko taškų: " << vidurkis << endl;
        if(n == 0) {
            fr << "Atrinktųjų mokinių nebuvo.";
        }
        else {
            suma = Suma(n, A);
            vidurkis = suma / n;
            fr << "Atrinktieji mokiniai vidutiniškai surinko taškų: " << vidurkis;
        }
    }
    fr.close();
}