#include <iostream>
#include <fstream>
using namespace std;

struct Turistai
{
    string Vardas;
    int litai, centai, bitai, bcentai;
};

void Skaitymas(int &n, Turistai A[], int &bitai, int &bitai2);
void Surinko(int n, Turistai A[], int &surinko, int &surinkocentai);
void Kursas(int n, Turistai A[], int bitai, int bitai2);
void Gavo(int n, Turistai A[], int &gavo, int &gavocentai);
void Rasymas(int n, Turistai A[], int surinko, int surinkocentai, int gavo, int gavocentai);

int main()
{
    Turistai A[100];
    int n, bitai, bitai2, surinko, surinkocentai, gavo, gavocentai;
    Skaitymas(n, A, bitai, bitai2);
    Surinko(n, A, surinko, surinkocentai);
    Kursas(n, A, bitai, bitai2);
    Gavo(n, A, gavo, gavocentai);
    Rasymas(n, A, surinko, surinkocentai, gavo, gavocentai);
    return 0;
}

void Skaitymas(int &n, Turistai A[], int &bitai, int &bitai2)
{
    ifstream fd("valiuta.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i].Vardas >> A[i].litai >> A[i].centai;
    }
    fd >> bitai >> bitai2;
    fd.close();
}

void Surinko(int n, Turistai A[], int &surinko, int &surinkocentai)
{
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += A[i].litai * 100 + A[i].centai;
    }
    surinko = suma / 100;
    surinkocentai = suma % 100;
}

void Kursas(int n, Turistai A[], int bitai, int bitai2)
{
    int temp;
    double temp2;
    temp = bitai * 100 + bitai2;
    for(int i = 0; i < n; i++) {
        A[i].bcentai = A[i].litai * temp;
        temp2 = double(A[i].centai) / 100;
        A[i].bcentai += temp2 * temp;
        A[i].bitai = A[i].bcentai / 100;
        A[i].bcentai = A[i].bcentai % 100;
    }
}

void Gavo(int n, Turistai A[], int &gavo, int &gavocentai)
{
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += A[i].bitai * 100 + A[i].bcentai;
    }
    gavo = suma / 100;
    gavocentai = suma % 100;
}

void Rasymas(int n, Turistai A[], int surinko, int surinkocentai, int gavo, int gavocentai)
{
    ofstream fr("valiutarez.txt");
    fr << "Gidas surinko: " << surinko << " " << surinkocentai << endl;
    fr << "Gidas gavo: " << gavo << " " << gavocentai << endl;
    fr << "     Vardas              Turi        Gavo" << endl;
    for(int i = 0; i < n; i++) {
        fr << A[i].Vardas << "              " << A[i].litai << " " << A[i].centai << "      " << A[i].bitai << " " << A[i].bcentai << endl;
    }
    fr.close();
}