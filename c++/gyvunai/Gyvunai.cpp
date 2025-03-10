#include <iostream>
#include <fstream>

using namespace std;

struct Gyvunas
{
    string gyvunas;
    int kiek;
};

void Skaitymas(int &n, Gyvunas A[]);
int Yra(int m, Gyvunas B[], string gyvunas);
void Atrinkimas(int n, int &m, Gyvunas A[], Gyvunas B[]);
void Rikiavimas(int m, Gyvunas B[]);
void Rasymas(int m, Gyvunas B[]);

int main()
{
    Gyvunas A[100], B[100];
    int n, m = 0;
    Skaitymas(n, A);
    Atrinkimas(n, m, A, B);
    Rikiavimas(m, B);
    Rasymas(m, B);
    return 0;
}

void Skaitymas(int &n, Gyvunas A[])
{
    ifstream fd("gyvunai.txt");
    fd >> n;
    char eil[16];
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd.get(eil, 16);
        A[i].gyvunas = eil;
        fd >> A[i].kiek;
    }
    fd.close();
}

int Yra(int m, Gyvunas B[], string gyvunas)
{
    for(int i = 0; i < m; i++)
        if(B[i].gyvunas == gyvunas) return i;
    return -1;
}

void Atrinkimas(int n, int &m, Gyvunas A[], Gyvunas B[])
{
    int k;
    for(int i = 0; i < n; i++) {
        k = Yra(m, B, A[i].gyvunas);
        if(k >= 0) B[k].kiek++;
        else {
            B[m] = A[i];
            m++;
        }
    }
}

void Rikiavimas(int m, Gyvunas B[])
{
    int index;
    Gyvunas temp;
    for(int i = 0; i < m; i++) {
        index = i;
        for(int j = i + 1; j < m; j++)
            if(B[j].kiek > B[index].kiek) index = j;
        temp = B[i];
        B[i] = B[index];
        B[index] = temp;
    }
}

void Rasymas(int m, Gyvunas B[])
{
    ofstream fr("gyvunairez.txt");
    for(int i = 0; i < m; i++) 
        fr << B[i].gyvunas << B[i].kiek << endl;
    fr.close();
}