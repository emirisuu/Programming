#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &gstart1, int &gend1, int &gstart2, int &gend2, int &gstart3, int &gend3, int&n, int &vyrcounter, int &mercounter, char Vaikinai[], char Merginos[], int Vmetai[], int Mmetai[]);
void Rikiavimas(int n, int X[]);
void Grupe(int gstart, int gend, int n, int k, int X[], int Z[], int &gv, int &gm);
void Rasymas(int gstart1, int gend1, int gstart2, int gend2, int gstart3, int gend3, int vyrcounter, int mercounter, int gv1, int gm1, int gv2, int gm2, int gv3, int gm3, int Vmetai[], int Mmetai[]);

int main()
{
    int gstart1, gend1, gstart2, gend2, gstart3, gend3, n, counter1 = 0, counter2 = 0, counter3 = 0, vyrcounter = 0, mercounter = 0, Vmetai[100], Mmetai[100], gv1 = 0, gm1 = 0, gv2 = 0, gm2 = 0, gv3 = 0, gm3 = 0;
    char Vaikinai[100], Merginos[100];
    Skaitymas(gstart1, gend1, gstart2, gend2, gstart3, gend3, n, vyrcounter, mercounter, Vaikinai, Merginos, Vmetai, Mmetai);
    Rikiavimas(vyrcounter, Vmetai);
    Rikiavimas(mercounter, Mmetai);
    Grupe(gstart1, gend1, vyrcounter, mercounter, Vmetai, Mmetai, gv1, gm1);
    Grupe(gstart2, gend2, vyrcounter, mercounter, Vmetai, Mmetai, gv2, gm2);
    Grupe(gstart3, gend3, vyrcounter, mercounter, Vmetai, Mmetai, gv3, gm3);
    Rasymas(gstart1, gend1, gstart2, gend2, gstart3, gend3, vyrcounter, mercounter, gv1, gm1, gv2, gm2, gv3, gm3, Vmetai, Mmetai);
    return 0;
}

void Skaitymas(int &gstart1, int &gend1, int &gstart2, int &gend2, int &gstart3, int &gend3, int&n, int &vyrcounter, int &mercounter, char Vaikinai[], char Merginos[], int Vmetai[], int Mmetai[])
{
    ifstream fd("duomenys.txt");
    int temp;
    char temp1;
    fd >> gstart1 >> gend1 >> gstart2 >> gend2 >> gstart3 >> gend3;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> temp >> temp1;
        if(temp1 == 'V') {
            Vmetai[vyrcounter] = temp;
            Vaikinai[vyrcounter] = temp1;
            vyrcounter++;
        }
        else {
            Mmetai[mercounter] = temp;
            Merginos[mercounter] = temp1;
            mercounter++;
        }
    }
    fd.close();
}

void Rikiavimas(int n, int X[])
{
    int index, temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++) {
            if(X[j] > X[index]) {
                index = j;
            }
        }
        temp = X[i];
        X[i] = X[index];
        X[index] = temp;
    }
}

void Grupe(int gstart, int gend, int n, int k, int X[], int Z[], int &gv, int &gm)
{
    for(int i = 0; i < n; i++) {
        if(X[i] == gstart || X[i] == gend) {
            gv++;
        }
    }
    for(int i = 0; i < k; i++) {
        if(Z[i] == gstart || Z[i] == gend) {
            gm++;
        }
    }
}

void Rasymas(int gstart1, int gend1, int gstart2, int gend2, int gstart3, int gend3, int vyrcounter, int mercounter, int gv1, int gm1, int gv2, int gm2, int gv3, int gm3, int Vmetai[], int Mmetai[])
{
    ofstream fr("rezultatai.txt");
    fr << "I varzybas uzsiregistravo:" << endl;
    fr << vyrcounter << " vaikinu" << endl;
    for(int i = 0; i < vyrcounter; i++) {
        fr << Vmetai[i] << endl;
    }
    fr << mercounter << " merginos" << endl;
    for(int i = 0; i < mercounter; i++) {
        fr << Mmetai[i] << endl;
    }
    fr << gstart3 << "-" << gend3 << " m. grupes:" << endl;
    if(gv3 > 0) {
        fr << "vaikinu grupeje bus " << gv3 << " dalyviai" << endl;
    }
    else {
        fr << "vaikinu grupe nesuformuota" << endl;
    }
    if(gm3 > 0) {
        fr << "merginu grupeje bus " << gm3 << " dalyves" << endl;
    }
    else { 
        fr << "merginu grupe nesuformuota" << endl;
    }
    fr << gstart2 << "-" << gend2 << " m. grupes:" << endl;
    if(gv2 > 0) {
        fr << "vaikinu grupeje bus " << gv2 << " dalyviai" << endl;
    }
    else {
        fr << "vaikinu grupe nesuformuota" << endl;
    }
    if(gm2 > 0) {
        fr << "merginu grupeje bus " << gm2 << " dalyves" << endl;
    }
    else { 
        fr << "merginu grupe nesuformuota" << endl;
    }
    fr << gstart1 << "-" << gend1 << " m. grupes:" << endl;
    if(gv1 > 0) {
        fr << "vaikinu grupeje bus " << gv1 << " dalyviai" << endl;
    }
    else {
        fr << "vaikinu grupe nesuformuota" << endl;
    }
    if(gm1 > 0) {
        fr << "merginu grupeje bus " << gm1 << " dalyves" << endl;
    }
    else { 
        fr << "merginu grupe nesuformuota" << endl;
    }
    fr.close();
}