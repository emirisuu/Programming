#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &a, int &r, int Ausra[], int Ruta[]);
void Daugiau(int n, int X[], int Mainymui[], int &counter);
void Salinimas(int &n, int X[], int index) ;
void Nezinau(int r, int Z[], int Mainymui[], int &counter);
void Rasymas(int counter, int Mainymui[]) ;

int main()
{
    int a, r, Ausra[1000], Ruta[1000], Mainymui[1000], counter = 0;
    Skaitymas(a, r, Ausra, Ruta);
    Daugiau(a, Ausra, Mainymui, counter);
    Nezinau(r, Ruta, Mainymui, counter);
    Rasymas(counter, Mainymui);
    return 0;
}

void Skaitymas(int &a, int &r, int Ausra[], int Ruta[])
{
    ifstream fd1("duom1.txt");
    fd1 >> a;
    for(int i = 0; i < a; i++) {
        fd1 >> Ausra[i];
    }
    fd1.close();
    ifstream fd2("duom2.txt");
    fd2 >> r;
    for(int i = 0; i < r; i++) {
        fd2 >> Ruta[i];
    }
    fd2.close();
}

void Daugiau(int n, int X[], int Mainymui[], int &counter)
{
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(X[i] == X[j]) {
                Mainymui[counter] = X[i];
                counter++;
                break;
            }
        }
    }
}

void Salinimas(int &n, int X[], int index) 
{
    for(int i = index; i < n; i++) {
        X[i] = X[i + 1];
    }
    n--;
}

void Nezinau(int r, int Z[], int Mainymui[], int &counter)
{
    int k = 0;
    for(int i = 0; i < counter; i++) {
        k = 0;
        for(int j = 0; j < r; j++) {
            if(Mainymui[i] == Z[j] || Mainymui[i] == Mainymui[i + 1]) {
                k = 1;
                break;
            }
        }
        if(k == 1) {
            Salinimas(counter, Mainymui, i);
            i--;
        }
    }
}

void Rasymas(int counter, int Mainymui[]) 
{
    ofstream fr("rez.txt");
    if(counter < 1) {
        fr << "Ženklų pasikeisti nėra.";
    }
    else {
        for(int i = 0; i < counter; i++) {
            fr << Mainymui[i] << " ";
        }
    }
    fr.close();
}