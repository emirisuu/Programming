#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &pinigai, int &counter);
int Maksimumas(int n, int X[], int p);
void Rasymas(int pinigai, int counter);

int main()
{
    int pinigai, counter = 0;
    Skaitymas(pinigai, counter);
    Rasymas(pinigai, counter);
    return 0;
}

void Skaitymas(int &pinigai, int &counter)
{
    ifstream fd("duom.txt");
    int A[100], n, m, index;
    fd >> pinigai >> n;
    for(int i = 0; i < n; i++) {
        fd >> m;
        for(int j = 0; j < m; j++) {
            fd >> A[j];
        }
        index = Maksimumas(m, A, pinigai);
        if(A[index] <= pinigai) {
            pinigai -= A[index];
            counter++; 
        } 
    }
    fd.close();
}

int Maksimumas(int n, int X[], int p)
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(X[i] > X[index] && X[i] <= p) {
            index = i;
        }
    }
    return index;
}

void Rasymas(int pinigai, int counter) 
{
    ofstream fr("rez.txt");
    fr << counter << " " << pinigai;
    fr.close();
}