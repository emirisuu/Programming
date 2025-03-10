#include <iostream>
#include <fstream>

using namespace std;

struct Kandidatas
{
    string vardas, pavarde;
    int kiek;
};

void Skaitymas(int &n, Kandidatas A[]);
int Yra(int m, Kandidatas B[], string vardas, string pavarde);
void Atrinkimas(int n, int &m, Kandidatas A[], Kandidatas B[]);
void Rikiavimas(int m, Kandidatas B[]);
void Rasymas(int m, Kandidatas B[]);

int main()
{
    Kandidatas A[100], B[100];
    int n, m = 0;
    Skaitymas(n, A);
    Atrinkimas(n, m, A, B);
    Rikiavimas(m, B);
    Rasymas(m, B);
    return 0;
}

void Skaitymas(int &n, Kandidatas A[])
{
    ifstream fd("rinkimai.txt");
    fd >> n;
    char eil[16];
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd.get(eil, 16);
        A[i].vardas = eil;
        fd.get(eil, 16);
        A[i].pavarde = eil;
        A[i].kiek = 1;
    }
    fd.close();
}

int Yra(int m, Kandidatas B[], string vardas, string pavarde)
{
    for(int i = 0; i < m; i++)
        if(B[i].vardas == vardas && B[i].pavarde == pavarde) return i;
    return -1;
}

void Atrinkimas(int n, int &m, Kandidatas A[], Kandidatas B[])
{
    int k;
    for(int i = 0; i < n; i++) {
        k = Yra(m, B, A[i].vardas, A[i].pavarde);
        if(k >= 0) B[k].kiek++;
        else {
            B[m] = A[i];
            m++;
        }
    }
}

void Rikiavimas(int m, Kandidatas B[])
{
    int index;
    Kandidatas temp;
    for(int i = 0; i < m; i++) {
        index = i;
        for(int j = i + 1; j < m; j++)
            if(B[j].kiek > B[index].kiek) index = j;
        temp = B[i];
        B[i] = B[index];
        B[index] = temp;
    }
}

void Rasymas(int m, Kandidatas B[])
{
    ofstream fr("rinkimairez.txt");
    for(int i = 0; i < m; i++)
        fr << B[i].vardas << B[i].pavarde << B[i].kiek << endl;
    fr.close();
}