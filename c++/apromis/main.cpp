#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int A[], int B[]);
void NetNeisivaizduojuKasCiaPerFunkcijaBamBamBamDauzoBelekaBelekaipMuzonasSenelyzai(int n, int A[], int B[], int C[], int D[], int &counter);
void Rasymas(int counter, int C[], int D[], int M[], int maxcounter, int index);
void Rikiavimas(int counter, int C[], int D[]);
void Max(int counter, int D[], int M[], int &maxcounter, int C[], int &index);

int main()
{
    int n, A[1000], B[1000], C[1000], D[1000], M[1000],  counter = 0, maxcounter = 0, index = 0;
    Skaitymas(n, A, B);
    NetNeisivaizduojuKasCiaPerFunkcijaBamBamBamDauzoBelekaBelekaipMuzonasSenelyzai(n, A, B, C, D, counter);
    Rikiavimas(counter, C, D);
    Max(counter, D, M, maxcounter, C, index);
    Rasymas(counter, C, D, M, maxcounter, index);
    return 0;
}

void Skaitymas(int &n, int A[], int B[])
{
    ifstream fd("duom.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i] >> B[i];
    }
    fd.close();
}

void NetNeisivaizduojuKasCiaPerFunkcijaBamBamBamDauzoBelekaBelekaipMuzonasSenelyzai(int n, int A[], int B[], int C[], int D[], int &counter)
{
    for(int i = 0; i < n; i++) {
        C[counter] = A[i];
        D[counter] = B[i];
        if(A[i] >= 3 && A[i] <= 16) {
            for(int j = i + 1; j < n; j++) {
                if(A[i] == A[j]) {
                    D[counter] += B[j];
                    A[j] = 0;
                }
            }
            counter++;
        }
    }
}

void Rikiavimas(int counter, int C[], int D[])
{
    int temp, index;
    for(int i = 0; i < counter; i++) {
        index = i;
        for(int j = i + 1; j < counter; j++) {
            if(C[j] < C[index]) {
                index = j;
            }
        }
        temp = C[i];
        C[i] = C[index];
        C[index] = temp;
        temp = D[i];
        D[i] = D[index];
        D[index] = temp;
    }
}

void Rasymas(int counter, int C[], int D[], int M[], int maxcounter, int index)
{
    ofstream fr("rez.txt");
    for(int i = 0; i < counter; i++) {
        fr << C[i] << " " << D[i] << endl;
    }
    if(maxcounter > 1) {
        fr << "Daugiausia yra ";
        for(int i = 0; i < maxcounter; i++) {
            if(i == maxcounter - 1) {
                fr << M[i] << " ";
                break;
            }
            fr << M[i] << ",";
        }
        fr << "rusiu" << endl;
    }
    else{
        fr << "Daugiausia yra " << C[index] << " rusies";
    }
    fr.close();
}

void Max(int counter, int D[], int M[], int &maxcounter, int C[], int &index)
{
    for(int i = 0; i < counter; i++) {
        if(D[i] > D[index]) {
            index = i;
        }
    }
    for(int i = 0; i < counter; i++) {
        if(D[i] == D[index]) {
            M[maxcounter] = C[i];
            maxcounter++;
        }
    }
}