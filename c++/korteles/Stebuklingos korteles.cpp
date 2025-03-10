#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int Zaidejai[], int Taskai[]);
int Minimumas(int Z[], int X[]);
int Maksimumas(int Z[], int X[]);
void Iterpimas(int &n, int Z[], int X[], int &index, int index1);
void Rasymas(int n, int Zaidejai[], int Taskai[], int minindex, int maxindex);

int main()
{
    int n, Zaidejai[100], Taskai[100], minindex, maxindex; 
    Skaitymas(n, Zaidejai, Taskai);
    minindex = Minimumas(Zaidejai, Taskai);
    maxindex = Maksimumas(Zaidejai, Taskai);
    Rasymas(n, Zaidejai, Taskai, minindex, maxindex);
    return 0;
}

void Skaitymas(int &n, int Zaidejai[], int Taskai[])
{
    ifstream fd("zaidimas.txt");
    int m, temp1, temp2;
    fd >> m;
    n = m / 4;
    for(int i = 0; i < 4; i++) {
        Zaidejai[i] = i + 1;
        Taskai[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            fd >> temp1 >> temp2;
            Taskai[j] += temp2;
        }
    }
    fd.close();
}

int Minimumas(int Z[], int X[])
{
    int index = 0;
    for(int i = 0; i < 4; i++) {
        if(X[i] < X[index]) {
            index = i;
        }
        else if(X[i] == X[index]) {
            if(Z[i] < Z[index]) {
                index = i;
            }
        }
    }
    return index;
}

int Maksimumas(int Z[], int X[])
{
   int index = 0;
    for(int i = 0; i < 4; i++) {
        if(X[i] > X[index]) {
            index = i;
        }
        else if(X[i] == X[index]) {
            if(Z[i] > Z[index]) {
                index = i;
            }
        }
    }
    return index; 
}

void Iterpimas(int &n, int Z[], int X[], int &index, int index1)
{
    int temp1 = Z[index1], temp2 = X[index1];
    for(int i = n; i > index; i--) {
        Z[i] = Z[i - 1];
        X[i] = X[i - 1];
    }
    Z[index] = temp1;
    X[index] = temp2;
    index++;
    n++; 
}

void Rasymas(int n, int Zaidejai[], int Taskai[], int minindex, int maxindex)
{
    ofstream fr("zaidimasrez.txt");
    fr << "Žaidėjai ir jų surinkti taškai:" << endl;
    for(int i = 0; i < n; i++) {
        if(Taskai[i] >= 0) {
            fr << Zaidejai[i] << " " << Taskai[i] << endl;
        }
    }
    fr << "Mažiausiai taškų surinko:" << endl;
    fr << Zaidejai[minindex] << endl;
    fr << "Daugiausiai taškų surinko:" << endl;
    fr << Zaidejai[maxindex] << endl;
    fr << "Po įterpimo:" << endl;
    Iterpimas(n, Zaidejai, Taskai, minindex, maxindex);
    Iterpimas(n, Zaidejai, Taskai, maxindex, minindex);
    for(int i = 0; i < n; i++) {
        if(Taskai[i] >= 0) {
            fr << Zaidejai[i] << " " << Taskai[i] << endl;
        }
    }
    fr.close();
}