#include <iostream>
#include <fstream>
using namespace std;
void Skaitymas(int &n, int &np, int &ng, int Knygos[], int Paimta[], int Grazinta[], int Counter[]);
void Salinimas(int &n, int X[], int Z[], int index);
int Index(int n, int X[], int x);
void Iterpimas(int &n, int X[], int Z[], int index, int x);
void Rasymas(int n, int ng, int Knygos[], int Grazinta[], int Counter[]);

int main()
{
    int n, Knygos[100], Paimta[100], Grazinta[100], np, ng, Counter[100];
    Skaitymas(n, np, ng, Knygos, Paimta, Grazinta, Counter);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < np; j++) {
            if(Knygos[i] == Paimta[j]) {
                if(Counter[i] == 1) {
                   Salinimas(n, Knygos, Counter, i);
                i--; 
                }
                else {
                    Counter[i]--;
                }
            }
        }
    }
    Rasymas(n, ng, Knygos, Grazinta, Counter);
    return 0;
}

void Skaitymas(int &n, int &np, int &ng, int Knygos[], int Paimta[], int Grazinta[], int Counter[])
{
    ifstream fd("duom.txt");
    fd >> n;
    fd >> np;
    for(int i = 0; i < np; i++) {
        fd >> Paimta[i];
    }
    fd >> ng;
    for(int i = 0; i < ng; i++) {
        fd >> Grazinta[i];
    }
    for(int i = 0; i < n; i++) {
        fd >> Knygos[i] >> Counter[i];
    }
    fd.close();
}

void Salinimas(int &n, int X[], int Z[], int index)
{
    for(int i = index; i < n - 1; i++) {
        X[i] = X[i + 1];
        Z[i] = Z[i + 1];
    }
    n--;
}

int Index(int n, int X[], int x)
{
    for(int i = 0; i < n; i++) {
        if(X[i] > x) {
            return i;
        }
    }
    return n;
}

void Iterpimas(int &n, int X[], int Z[], int index, int x)
{
    for(int i = n; i > index; i--) {
        X[i] = X[i - 1];
        Z[i] = Z[i - 1];
    }
    X[index] = x;
    Z[index] = 1;
    n++;
}

void Rasymas(int n, int ng, int Knygos[], int Grazinta[], int Counter[])
{
    ofstream fr("rez.txt");
    int index, k, index2;
    fr << "knygų sąrašas po išėmimo:" << endl;
    for(int i = 0; i < n; i++) {
        fr << "Nr. " << Knygos[i] << " " << Counter[i] << endl;
    }
    fr << "knygų sąrašas po išėmimo ir pridėjimo:" << endl;
    for(int i = 0; i < ng; i++) {
        k = 0;
        for(int j = 0; j < n; j++) {
            if(Grazinta[i] == Knygos[j]) {
                index2 = j;
                k = 1;
                break;
            }
        }
        if(k == 1) {
            Counter[index2]++;
        }
        else {
            index = Index(n, Knygos, Grazinta[i]);
        Iterpimas(n, Knygos, Counter, index, Grazinta[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        fr << "Nr. " << Knygos[i] << " " << Counter[i] << endl;
    }
    fr.close();
}
