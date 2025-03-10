#include <iostream>
#include <fstream>

using namespace std;
void Skaityti(int &n, int A[], double B[]);
int AuksciausiaTemp(int n, double B[]);
void SpausdintiAukstaTemp(int n, int A[], double B[], int maxindex);
void Spausdinti(int n, int A[], double B[], int maxindex);
ofstream fr("rezultatai.txt");
int main()
{
    int n, A[100], maxindex;
    double B[100];
    Skaityti(n, A, B);
    maxindex = AuksciausiaTemp(n, B);
    Spausdinti(n, A, B, maxindex);
    fr.close();
    return 0;
}

void Skaityti(int &n, int A[], double B[])
{
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i] >> B[i];
    }
    fd.close();
}

int AuksciausiaTemp(int n, double B[])
{
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(B[i] > B[index]) {
            index = i;
        }
    }
    return index;
}

void SpausdintiAukstaTemp(int n, int A[], double B[], int maxindex)
{
    for(int i = 0; i < n; i++) {
        if(B[i] == B[maxindex] || B[i] == B[maxindex] - 0.1 || B[i] == B[maxindex] - 0.2 || B[i] == B[maxindex] - 0.3 || B[i] == B[maxindex] - 0.4 || B[i] == B[maxindex] - 0.5) {
            fr << A[i] << " val. " << B[i] << endl;
        }
    }
}

void Spausdinti(int n, int A[], double B[], int maxindex)
{
    fr << "Ligonio temperatura" << endl;
    fr << "----------------------" << endl;
    fr << "Valanda   Temperatura" << endl;
    fr << "----------------------" << endl;
    for(int i = 0; i < n; i++) {
        fr << "   " << A[i] << "       " << B[i] << endl;
    }
    fr << "----------------------" << endl;
    fr << "Auksciausia temperatura " << B[maxindex] << " buvo " << A[maxindex] << " val." << endl;
    fr << "Auksta temperatura dar buvo:" << endl;
    SpausdintiAukstaTemp(n, A, B, maxindex);
}