#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Preke
{
    string pavadinimas;
    int data, dienos, metai, men, diena;

};

void Skaitymas(int &n, Preke A[], int Laikotarpis1[], int Laikotarpis2[]);
void Salinimas(int &n, Preke A[], int index);
double Vidurkis(int n, Preke A[]);
void Rikiavimas(int n, Preke A[]);
void Rasymas(int n, Preke A[], int Laikotarpis1[], int Laikotarpis2[], double vidurkis);

int main()
{
    Preke A[100];
    int n, Laikotarpis1[3], Laikotarpis2[3];
    double vidurkis;
    Skaitymas(n, A, Laikotarpis1, Laikotarpis2);
    vidurkis = Vidurkis(n, A);
    Rikiavimas(n, A);
    Rasymas(n, A, Laikotarpis1, Laikotarpis2, vidurkis);
    return 0;
}

void Skaitymas(int &n, Preke A[], int Laikotarpis1[], int Laikotarpis2[])
{
    ifstream fd("Prekes_cin.txt");
    fd >> n;
    int temp1, temp2, temp3, laik1, laik2;
    char eil[21];
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd.get(eil, 21);
        A[i].pavadinimas = eil;
        fd >> A[i].metai >> A[i].men >> A[i].diena;
        A[i].data = A[i].metai * 10000 + A[i].men * 100 + A[i].diena;
        fd >> A[i].dienos;
    }
    fd.close();
    cin >> Laikotarpis1[0] >> Laikotarpis1[1] >> Laikotarpis1[2];
    laik1 = Laikotarpis1[0] * 10000 + Laikotarpis1[1] * 100 + Laikotarpis1[2];
    cin >> Laikotarpis2[0] >> Laikotarpis2[1] >> Laikotarpis2[2];
    laik2 = Laikotarpis2[0] * 10000 + Laikotarpis2[1] * 100 + Laikotarpis2[2];
    for(int i = 0; i < n; i++) 
        if(A[i].data < laik1 || A[i].data > laik2) {
            Salinimas(n, A, i);
            i--;
        }
}

void Salinimas(int &n, Preke A[], int index)
{
    for(int i = index; i < n; i++)
        A[i] = A[i + 1];
    n--;
}

double Vidurkis(int n, Preke A[])
{
    double suma = 0, vidurkis;
    for(int i = 0; i < n; i++)
        suma += A[i].dienos;
    vidurkis = suma / double(n);
    return vidurkis;
}

void Rikiavimas(int n, Preke A[])
{
    int index = 0;
    Preke temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++)
            if(A[j].pavadinimas < A[index].pavadinimas) index = j;
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}

void Rasymas(int n, Preke A[], int Laikotarpis1[], int Laikotarpis2[], double vidurkis)
{
    ofstream fr("prekesrez.txt");
    fr << "Nurodytas laikotarpis: " << Laikotarpis1[0] << " " << Laikotarpis1[1] << " " << Laikotarpis1[2] << " - " << Laikotarpis2[0] << " " << Laikotarpis2[1] << " " << Laikotarpis2[2] << endl;
    fr << "Prekės pavadinimas       Pagaminimo      Vartojimo" << endl;
    fr << "                            Data           Laikas" << endl;
    for(int i = 0; i < n; i++)
        fr << A[i].pavadinimas << A[i].metai << " " << A[i].men << " " << A[i].diena << "       " << A[i].dienos << endl;
    fr << "Vartojimo trukmės vidurkis: " << fixed << setprecision(2) << vidurkis;
    fr.close();
}