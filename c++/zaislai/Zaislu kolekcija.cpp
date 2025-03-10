#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &n, int Z[]);
void Rasymas(int n, int Z[]);

int main()
{
    int n, Z[100] = {0};
    Skaitymas(n, Z);
    Rasymas(n, Z);
    return 0;
}

void Skaitymas(int &n, int Z[])
{
    ifstream fd("duomenys.txt");
    fd >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        fd >> temp;
        Z[temp]++;
    }
    fd.close();
}

void Rasymas(int n, int Z[])
{
    ofstream fr("rezultatai.txt");
    int temp;
    for(int i = 0; i < n; i++) {
        if(Z[i] > 1) {
            temp = Z[i] - 1;
            for(int j = 0; j < temp; j++) fr << i << "  ";
        }
    }
    fr.close();
}