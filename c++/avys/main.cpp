#include <iostream>
#include <fstream>

using namespace std;

struct Avis
{
    string avis, dnr;
    int counter;
};

void Skaitymas(int &n, int &m, Avis A[], string &test, string &testdnr);
void Salinimas(int &n, Avis A[], int index);
void Koeficientai(int n, int m, Avis A[], string test, string testdnr);
void Rikiavimas(int n, Avis A[]);
void Rasymas(int n, Avis A[], string test);

int main()
{
    Avis A[20];
    int n, m;
    string test = "", testdnr = "";
    Skaitymas(n, m, A, test, testdnr);
    Koeficientai(n, m, A, test, testdnr);
    Rikiavimas(n, A);
    Rasymas(n, A, test);
    return 0;
}

void Skaitymas(int &n, int &m, Avis A[], string &test, string &testdnr)
{
    ifstream fd("U2.txt");
    int index;
    fd >> n >> m;
    fd >> index;
    char temp[11], temp1;
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd.get(temp, 11);
        A[i].avis = temp;
        A[i].dnr = "";
        for(int j = 0; j < m; j++) {
            fd >> temp1;
            A[i].dnr += temp1;
        }
        if(i == index - 1) {
            test = A[i].avis;
            testdnr = A[i].dnr;
        }
    }
    Salinimas(n, A, index);
    fd.close();
}

void Salinimas(int &n, Avis A[], int index)
{
    for(int i = index - 1; i < n - 1; i++)
        A[i] = A[i + 1];
    n--;
}

void Koeficientai(int n, int m, Avis A[], string test, string testdnr)
{
    for(int i = 0; i < n; i++) {
        A[i].counter = 0;
        for(int j = 0; j < m; j++)
            if(A[i].dnr[j] == testdnr[j]) A[i].counter++;
    }
}

void Rikiavimas(int n, Avis A[])
{
    Avis Temp;
    int index;
    for(int i = 0; i < n; i++) {
        index  = i;
        for(int j = i + 1; j < n; j++)
            if(A[j].counter > A[index].counter || (A[j].counter == A[index].counter && A[j].avis < A[index].avis)) index = j;
        Temp = A[i];
        A[i] = A[index];
        A[index] = Temp;
    }
}

void Rasymas(int n, Avis A[], string test)
{
    ofstream fr("U2rez.txt");
    fr << test << endl;
    for(int i = 0; i < n; i++)
        fr << A[i].avis << " " << A[i].counter << endl;
    fr.close();
}