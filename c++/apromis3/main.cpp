#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int A[]);
void Kazkas(int n, int A[], int B[], int &counter);
void Rikiavimas(int counter, int B[]);
void Rasymas(int counter, int B[]);

int main()
{
    int n, A[100], B[100], counter = 0;
    Skaitymas(n, A);
    Kazkas(n, A, B, counter);
    Rikiavimas(counter, B);
    Rasymas(counter, B);
    return 0;
}

void Skaitymas(int &n, int A[])
{
    ifstream fd("duom.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i];
    }
    fd.close();
}

void Kazkas(int n, int A[], int B[], int &counter)
{
    int tempcounter, temp, maxcounter = 0, k = 0;
    for(int i = 0; i < n; i++) {
        tempcounter = 0;
        for(int j = 0; j < n; j++) {
            if(A[i] == A[j]) {
                tempcounter++;
            }
        }
        if(tempcounter > maxcounter) {
            maxcounter = tempcounter;   
        }
    }
    for(int i = 0; i < n; i++) {
        tempcounter = 0;
        for(int j = i; j < n; j++) {
            if(A[i] == A[j]) {
                tempcounter++;
            }
        }
        if(tempcounter == maxcounter) {
            B[counter] = A[i];
            counter++;
        }
    }
}

void Rikiavimas(int counter, int B[])
{
    int temp, index;
    for(int i = 0; i < counter; i++) {
        index = i;
        for(int j = i + 1; j < counter; j++) {
            if(B[j] < B[index]) {
                index = j;
            }
        }
        temp = B[i];
        B[i] = B[index];
        B[index] = temp;
    }
}

void Rasymas(int counter, int B[])
{
    ofstream fr("rez.txt");
    for(int i = 0; i < counter; i++) {
        fr << B[i];
        if(i != counter - 1) {
            fr << ",";
        }
    }
    fr.close();
}