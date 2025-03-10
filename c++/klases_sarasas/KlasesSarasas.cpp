#include <iostream>
#include <fstream>

using namespace std;

struct Klase
{
    string VardasPavarde, pamoka;
};

void Skaitymas(int &n, Klase A[]);
void Salinimas(int &n, Klase A[], int index);
void Rikiavimas(int n, Klase A[]);
void Rasymas(int n, int m, Klase A[], Klase B[]);

int main()
{
    Klase A[100];
    Klase B[100];
    int n, m = 0;
    Skaitymas(n, A);
    Rikiavimas(n, A);
    for(int i = 0; i < n; i++)
        if(A[i].pamoka == "Etika") {
            B[m].VardasPavarde = A[i].VardasPavarde;
            B[m].pamoka = A[i].pamoka;
            m++;
        }
    Rikiavimas(m, B);
    Rasymas(n, m, A, B);
    return 0;
}

void Skaitymas(int &n, Klase A[])
{
    ifstream fd("Klases_sarasas.txt");
    int temp, temp1;
    char t;
    char eil[26];
    string Isvyke[100], Naujokai[100], Pamoka[100];
    fd >> temp;
    for(int i = 0; i < temp; i++) {
        fd.ignore(81, '\n');
        fd.get(eil, 26);
        Isvyke[i] = eil;
        cout << Isvyke[i] << endl;
        fd >> t;
    }
    fd >> temp1;
    for(int i = 0; i < temp1; i++) {
        fd.ignore(81, '\n');
        fd.get(eil, 26);
        Naujokai[i] = eil;
        fd >> Pamoka[i];
    }
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd.ignore(81, '\n');
        fd.get(eil, 26);
        A[i].VardasPavarde = eil;
        fd >> A[i].pamoka;
    }
    fd.close();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < temp; j++)
            if(A[i].VardasPavarde == Isvyke[j]) {
                Salinimas(n, A, i);
                i--;
            }
    for(int i = 0; i < temp1; i++) {
        A[n].VardasPavarde = Naujokai[i];
        A[n].pamoka = Pamoka[i];
        n++;
    }
}

void Salinimas(int &n, Klase A[], int index)
{
    for(int i = index; i < n; i++)
        A[i] = A[i + 1];
    n--;
}

void Rikiavimas(int n, Klase A[])
{
    int index = 0;
    Klase temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++)
            if(A[j].VardasPavarde < A[index].VardasPavarde) index = j;
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}

void Rasymas(int n, int m, Klase A[], Klase B[])
{
    ofstream fr("KlasesSarasasrez.txt");
    fr << "Klasės sąrašas" << endl;
    fr << "     Mokinys             Dalykas" << endl;
    for(int i = 0; i < n; i++)
        fr << A[i].VardasPavarde << A[i].pamoka << endl;
    fr << "Etiką pasirinkusieji mokiniai" << endl;
    fr << "     Mokinys             Dalykas" << endl;
    for(int i = 0; i < m; i++)
        fr << B[i].VardasPavarde << B[i].pamoka << endl;
    fr.close();
}