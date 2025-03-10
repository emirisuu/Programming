#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int A[], int ratai, int suma, int temp, double santykis, double B[]);
int Minimumas(int n, double B[]);
void Rasymas(int A[], int minindex);

int main()
{
    int n, A[100], ratai, suma, temp, minindex;
    double B[100], santykis;
    Skaitymas(n, A, ratai, suma, temp, santykis, B);
    minindex = Minimumas(n, B);
    Rasymas(A, minindex);
    return 0;
}

void Skaitymas(int &n, int A[], int ratai, int suma, int temp, double santykis, double B[])
{
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i] >> ratai;
        suma = 0;
        for(int j = 0; j < ratai; j++) {
            fd >> temp;
            suma += temp;
        }
        santykis = double(suma) / ratai;
        B[i] = santykis;
    }
    fd.close();
}

int Minimumas(int n, double B[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(B[i] < B[index]) {
            index = i;
        }
        cout << B[i] << endl;
    }
    return index;
}

void Rasymas(int A[], int minindex)
{
    ofstream fr("rezultatai.txt");
    fr << A[minindex];
    fr.close();
}