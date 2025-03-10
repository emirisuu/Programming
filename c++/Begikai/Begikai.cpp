#include <iostream>
#include <fstream>

using namespace std;

struct Begikas
{
    string VardasPavarde;
    int laikas;
};

void Skaitymas(int &n, Begikas A[]);
void Rikiavimas(int n, Begikas A[]);
void Salinimas(int &n, Begikas A[], int index);
void Rasymas(int n, Begikas A[]);

int main()
{
    Begikas A[100]; 
    int n;
    Skaitymas(n, A);
    Rasymas(n, A);
    return 0;
}

void Skaitymas(int &n, Begikas A[])
{
    ifstream fd1("Begikai1.txt");
    int temp1, temp2, vidurys, k;
    Begikas B[100];
    char eil[21];
    fd1 >> n;
    for(int i = 0; i < n; i++) {
        fd1.ignore(80, '\n');
        fd1.get(eil, 21);
        A[i].VardasPavarde = eil;
        fd1 >> temp1 >> temp2;
        A[i].laikas = temp1 * 60 + temp2;
    }
    fd1.close();
    Rikiavimas(n, A);
    vidurys = n / 2;
    for(int i = 0; i < n - vidurys; i++) 
        Salinimas(n, A, vidurys);
    n--;
    ifstream fd2("Begikai2.txt");
    fd2 >> k;
    for(int i = 0; i < k; i++) {
        fd2.ignore(80, '\n');
        fd2.get(eil, 21);
        B[i].VardasPavarde = eil;
        fd2 >> temp1 >> temp2;
        B[i].laikas = temp1 * 60 + temp2;
    }
    fd2.close();
    Rikiavimas(k, B);
    vidurys = k / 2;
    for(int i = 0; i < k - vidurys; i++) 
        Salinimas(k, B, vidurys);
    k--;
    for(int i = 0; i < k; i++) {
        A[n] = B[i];
        n++;
    }
    Rikiavimas(n, A);
}

void Rikiavimas(int n, Begikas X[])
{
    int index;
    Begikas temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++)
            if(X[j].laikas < X[index].laikas) index = j;
        temp = X[i];
        X[i] = X[index];
        X[index] = temp;
    }
}

void Salinimas(int &n, Begikas A[], int index)
{
    for(int i = index; i < n; i++)
        A[i] = A[i + 1];
    n--;
}

void Rasymas(int n, Begikas A[])
{
    ofstream fr("Begikairez.txt");
    fr << "Bėgikų finalinio bėgimo sąrašas" << endl;
    fr << "Vardas ir             Parodytas  Bėgimo" << endl;
    fr << "pavardė               laikas     takelis" << endl;
    for(int i = 0; i < n; i++)
        fr << A[i].VardasPavarde << A[i].laikas / 60 << " " << A[i].laikas % 60 << "         " << n - i << endl;
    fr.close();
}