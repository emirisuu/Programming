#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

string s1 = "Mokesciai_1.txt", s2 = "Mokesciai_2.txt", r1 = "Mokesciai1rez.txt", r2 = "Mokesciai2rez.txt";

struct Gyventojas
{
    string VardasPavarde;
    int butas;
    double sildymas, elektra, vanduo;
};

void Skaitymas(int &n, Gyventojas Z[], string pavad);
void Skaiciavimai(int a, int &b, Gyventojas A[], Gyventojas B[]);
void Rasymas(int n, Gyventojas Z[], string pavad);

int main()
{
    Gyventojas A[100];
    Gyventojas B[100];
    int a, b;
    Skaitymas(a, A, s1);
    Skaitymas(b, B, s2);
    Skaiciavimai(a, b, A, B);
    Rasymas(a, A, r1);
    Rasymas(b, B, r2);
    return 0;
}

void Skaitymas(int &n, Gyventojas Z[], string pavad)
{
    ifstream fd(pavad);
    fd >> n;
    char eil[21];
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd.get(eil, 21);
        Z[i].VardasPavarde = eil;
        fd >> Z[i].butas >> Z[i].sildymas >> Z[i].elektra >> Z[i].vanduo;
    }
    fd.close();
}

void Skaiciavimai(int a, int &b, Gyventojas A[], Gyventojas B[])
{
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++)
            if(A[i].butas == B[j].butas) {
                A[i].sildymas += B[j].sildymas;
                A[i].elektra += B[j].elektra;
                A[i].vanduo += B[j].vanduo;
            }
    }
    b = 0;
    for(int i = 0; i < a; i++)
        if(A[i].sildymas < 0 || A[i].elektra < 0 || A[i].vanduo < 0) {
            B[b] = A[i];
            b++;
        }
}

void Rasymas(int n, Gyventojas Z[], string pavad)
{
    ofstream fr(pavad);
    fr << "Pavardė, vardas      Buto Nr.  Šildymas  Elektra  Vanduo" << endl;
    for(int i = 0; i < n; i++)
        fr << Z[i].VardasPavarde  << Z[i].butas << fixed << setprecision(2) << "        "  << Z[i].sildymas << "         " << Z[i].elektra << "     " << Z[i].vanduo << endl;
    fr.close();
}