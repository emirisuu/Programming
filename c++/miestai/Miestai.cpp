#include <iostream>
#include <fstream>

using namespace std;

struct Salis
{
    string salis;
    int counter;
};

void Skaitymas(int &n, Salis A[]);
int Yra(int m, Salis B[], string salis);
void Atrinkimas(int n, int &m, Salis A[], Salis B[]);
void Rasymas(int m, Salis B[]);

int main()
{
    Salis A[100], B[100];
    int n, m = 0;
    Skaitymas(n, A);
    Atrinkimas(n, m, A, B);
    Rasymas(m, B);
    return 0;
}

void Skaitymas(int &n, Salis A[])
{
    ifstream fd("miestai.txt");
    fd >> n;
    char eil[21];
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd.get(eil, 21);
        fd >> A[i].salis;
        A[i].counter = 1;
    }
    fd.close();
}

int Yra(int m, Salis B[], string salis)
{
    for(int i = 0; i < m; i++)
        if(B[i].salis == salis) return i;
    return -1;
}

void Atrinkimas(int n, int &m, Salis A[], Salis B[])
{
    int k;
    for(int i = 0; i < n; i++) {
        k = Yra(m, B, A[i].salis);
        if(k < 0) {
            B[m] = A[i];
            m++;
        }
        else B[k].counter++;
    }
}

void Rasymas(int m, Salis B[])
{
    ofstream fr("miestairez.txt");
    fr << "Valstybių sąrašas:" << endl;
    for(int i = 0; i < m; i++)
        fr << B[i].salis << "       " << B[i].counter << endl;
    fr.close();
}