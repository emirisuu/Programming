#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
void Skaitymas(int &t, int &n, int T[]);
int Maziausias(int n, int T[]);
int Didziausias(int n, int T[]);
int GalTemp(int t, int n, int T[]);
int TeigiamosDienos(int n, int T[]);
void Rasymas(int galtemp, int T[], int mazindex, int maxindex, int teigcounter);

int main()
{
    int t, n, T[100], mazindex, maxindex, galtemp, teigcounter;
    Skaitymas(t, n, T);
    mazindex = Maziausias(n, T);
    maxindex = Didziausias(n, T);
    galtemp = GalTemp(t, n, T);
    teigcounter = TeigiamosDienos(n, T);
    Rasymas(galtemp, T, mazindex, maxindex, teigcounter);
    return 0;
}

void Skaitymas(int &t, int &n, int T[])
{
    ifstream fd("duomenys.txt");
    fd >> t >> n;
    for(int i = 0; i < n; i++) {
        fd >> T[i];
    }
    fd.close();
}

int Maziausias(int n, int T[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(abs(T[i]) < abs(T[index])) {
            index = i;
        }
        else if(abs(T[i]) == abs(T[index])) {
            if(i < index) {
                index = i;
            }
        }
    }
    return index;
}

int Didziausias(int n, int T[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(abs(T[i]) > abs(T[index])) {
            index = i;
        }
        else if(abs(T[i]) == abs(T[index])) {
            if(i > index) {
                index = i;
            }
        }
    }
    return index;
}

int GalTemp(int t, int n, int T[])
{
    int temp = t;
    for(int i = 0; i < n; i++) {
        temp += T[i];
    }
    return temp;
}

int TeigiamosDienos(int n, int T[])
{
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if(T[i] >= 0) {
            counter++;
        }
    }
    return counter;
}

void Rasymas(int galtemp, int T[], int mazindex, int maxindex, int teigcounter)
{
    ofstream fr("rezultatai.txt");
    fr << galtemp << endl;
    fr << mazindex + 1 << " " << T[mazindex] << endl;
    fr << maxindex + 1 << " " << T[maxindex] << endl;
    fr << teigcounter;
}