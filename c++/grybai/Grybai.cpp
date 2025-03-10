#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int M[100], int D[100], double G[100], double B[100], double R[100]);
int Derlingumas(int n, double X[]);
void Rasymas(int &n, int M[100], int D[100], double G[100], double B[100], double R[100]);

int main()
{
    int n, M[100], D[100];
    double G[100], B[100], R[100];
    Skaitymas(n, M, D, G, B, R);
    Rasymas(n, M, D, G, B, R);
    return 0;
}

void Skaitymas(int &n, int M[100], int D[100], double G[100], double B[100], double R[100])
{
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> M[i] >> D[i] >> G[i] >> B[i] >> R[i];
    }
    fd.close();
}

int Derlingumas(int n, double X[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(X[i] > X[index]) {
            index = i;
        }
    }
    if(X[index] == 0) {
        index = -1;
    }
    return index;
}

void Rasymas(int &n, int M[100], int D[100], double G[100], double B[100], double R[100])
{
    ofstream fr("rezultatai.txt");
    int index;
    index = Derlingumas(n, G);
    fr << "Derlingiausia diena: " << M[index] << " " << D[index] << endl;
    index = Derlingumas(n, B);
    if(index >= 0) {
        fr << "Derlingiausia baravyku diena: " << M[index] << " " << D[index] << endl;
    }
    else {
        fr << "Derlingiausia baravyku diena: nera" << endl;
    }
    index = Derlingumas(n, R);
    if(index >= 0) {
        fr << "Derlingiausia baravyku diena: " << M[index] << " " << D[index] << endl;
    }
    else {
        fr << "Derlingiausia baravyku diena: nera" << endl;
    }
    fr.close();
}