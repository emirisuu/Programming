#include <iostream>
#include <fstream>

using namespace std;

struct Keleivis
{
    string pavarde;
    int vienetai;
    int Bagazai[100];
    int suma;
};

void Skaitymas(int &n, Keleivis A[], int &m, int &x, int &y);
void Skaiciavimai(int n, Keleivis A[], int m, int x, int y, int &mskaicius, int &xskaicius, int &yskaicius, string Pavardes [], int &counter);
int Maksimumas(int n, Keleivis A[]);
void Rasymas(int mskaicius, int xskaicius, int yskaicius, string Pavardes[], int counter);

int main()
{
    Keleivis A[500];
    int n, m, x, y, mskaicius = 0, xskaicius = 0, yskaicius = 0, counter = 0;
    string Pavardes[500];
    Skaitymas(n, A, m, x, y);
    Skaiciavimai(n, A, m, x, y, mskaicius, xskaicius, yskaicius, Pavardes, counter);
    Rasymas(mskaicius, xskaicius, yskaicius, Pavardes, counter);
    return 0;
}

void Skaitymas(int &n, Keleivis A[], int &m, int &x, int &y)
{
    ifstream fd("bagazas.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i].pavarde >> A[i].vienetai;
        for(int j = 0; j < A[i].vienetai; j++) {
            fd >> A[i].Bagazai[j];
        }
    }
    fd >> m >> x >> y;
    fd.close();
}

void Skaiciavimai(int n, Keleivis A[], int m, int x, int y, int &mskaicius, int &xskaicius, int &yskaicius, string Pavardes [], int &counter)
{
    int temp = 0, vidurkis, index;
    for(int i = 0; i < n; i++) {
        if(A[i].vienetai <= m) {
            mskaicius++; 
        }
        for(int j = 0; j < A[i].vienetai; j++) {
            temp += A[i].Bagazai[j];
        }
    }
    vidurkis = temp / n;
    for(int i = 0; i < n; i++) {
        A[i].suma = 0;
        for(int j = 0; j < A[i].vienetai; j++) {
            A[i].suma += A[i].Bagazai[j];
        }
        if(A[i].suma >= x + 0.1) {
            xskaicius++;
        }
        if(A[i].suma >= vidurkis + 1) {
            yskaicius++;
        }
    }
    index = Maksimumas(n, A);
    for(int i = 0; i < n; i++) {
        if(A[i].suma == A[index].suma + y || A[i].suma == A[index].suma - y) {
            Pavardes[counter] = A[i].pavarde;
            counter++;
        }
    }
}

int Maksimumas(int n, Keleivis A[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(A[i].suma > A[index].suma) {
            index = i;
        }
    }
    return index;
}

void Rasymas(int mskaicius, int xskaicius, int yskaicius, string Pavardes[], int counter)
{
    ofstream fr("LektuvoBagazasrez.txt");
    fr << mskaicius << endl;
    fr << xskaicius << endl;
    fr << yskaicius << endl;
    for(int i = 0; i < counter; i++) {
        fr << Pavardes[i] << endl;
    }
    fr.close();
}