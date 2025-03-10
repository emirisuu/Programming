#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaitymas(int &n, int A[], int &k);
void Rikiavimas(int n, int A[]);
void Salinimas(int &n, int A[], int &index);
int Suma(int n, int A[]);
void Rasymas(double vidurkis);

int main()
{
    int Balai[100], n, index = 0, suma, k = 0; 
    double vidurkis;
    Skaitymas(n, Balai, k);
    if(k != 1){
        Rikiavimas(n, Balai);
        Salinimas(n, Balai, index);
        n--;
        suma = Suma(n, Balai);
        vidurkis = double(suma) / n;
        Rasymas(vidurkis);
    }
    return 0;
}

void Skaitymas(int &n, int A[], int &k)
{
    ifstream fd("duomenys.txt");
    string temp;
    int len;
    fd >> temp;
    len = temp.length();
    for(int i = 0; i < len; i++) {
        if(temp[i] < 48 || temp[i] > 57) {
            cout << "Ivestas neteisingas teiseju skaiciaus duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaiciu be kablelio nuo 3 iki 100.";
            k = 1;
            return;
        }
    }
    n = stoi(temp);
    if(n < 3 || n > 100) {
        cout << "Ivestas neteisingas teiseju skaicius. Prasome pataisyti duomenu faila ir ivesti skaiciu be kablelio nuo 3 iki 100.";
        k = 1;
        return;
    }
    for(int i = 0; i < n; i++) {
        fd >> temp;
        len = temp.length();
        for(int j = 0; j < len; j++) {
            if(temp[j] < 48 || temp[j] > 57) {
                cout << "Ivestas neteisingas teiseju duoto balo duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaiciu be kablelio nuo 1 iki 10.";
                k = 1;
                return;
            }
        }
        A[i] = stoi(temp);
        if(A[i] < 1 || A[i] > 10) {
        cout << "Ivestas neteisingas teiseju duoto balo duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaiciu be kablelio nuo 1 iki 10.";
        k = 1;
        return;
        }
    }
    fd.close();
}

void Rikiavimas(int n, int A[])
{
    int temp, index;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++) if(A[j] < A[index]) index = j;
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}

void Salinimas(int &n, int A[], int &index)
{
    for(int i = index; i < n - 1; i++) A[i] = A[i + 1];
    n--;
}

int Suma(int n, int A[])
{
    int temp = 0;
    for(int i = 0; i < n; i++) temp += A[i];
    return temp;
}

void Rasymas(double vidurkis)
{
    ofstream fr("rezultatai.txt");
    fr << "Sportininko galutinis balas yra: " << fixed << setprecision(2) << vidurkis << endl;
    fr.close();
}