#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int &m, int &x, int Berniukai[][100], int &k);
void Skaiciavimai(int n, int m, int x, int Berniukai[][100], int Atrinkti[], int &counter);
void Rikiavimas(int m, int index, int Berniukai[][100]);
void Rasymas(int counter, int Atrinkti[]);

int main()
{
    int n, m, x, Berniukai[100][100], Atrinkti[10000], counter = 0, k = 0;
    Skaitymas(n, m, x, Berniukai, k);
    if(k != 1){
        Skaiciavimai(n, m, x, Berniukai, Atrinkti, counter);
        Rasymas(counter, Atrinkti);
    }
    return 0;
}

void Skaitymas(int &n, int &m, int &x, int Berniukai[][100], int &k)
{
    ifstream fd("duomenys.txt");
    string temp;
    int len, A[3];
    for(int i = 0; i < 3; i++) {
        fd >> temp;
        len = temp.length();
        for(int j = 0; j < len; j++) {
            if(temp[j] < 48 || temp[j] > 57) {
                cout << "Ivestas neteisingas n, m arba x duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaiciu be kablelio nuo 1 iki 100.";
                k = 1;
                return;
            }
        }
        A[i] = stoi(temp);
        if(A[i] < 1 || A[i] > 100) {
            cout << "Ivestas neteisingas n, m arba x duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 1 iki 100.";
            k = 1;
            return;
        }
    }
    n = A[0];
    m = A[1];
    x = A[2];
    if(x > m) {
        cout << "Ivestas neteisingas x duomenu formatas. Skaicius x negali buti didesnis uz skaiciu m ir turi buti skaicius be kablelio nuo 1 iki 100.";
        k = 1;
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fd >> temp;
            len = temp.length();
            for(int z = 0; z < len; z++) {
                if(temp[z] < 48 || temp[z] > 57) {
                    cout << "Ivestas neteisingas berniuku ugio duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 50 iki 250.";
                    k = 1;
                    return;
                }
            }
            Berniukai[i][j] = stoi(temp);
            if(Berniukai[i][j] < 50 || Berniukai[i][j] > 250) {
                cout << "Ivestas neteisingas berniuku ugio duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 50 iki 250.";
                k = 1;
                return;
            }
            }
    }
    fd.close();
}

void Skaiciavimai(int n, int m, int x, int Berniukai[][100], int Atrinkti[], int &counter)
{
    for(int i = 0; i < n; i++) {
        Rikiavimas(m, i, Berniukai);
        for(int j = 0; j < x; j++) {
            Atrinkti[counter] = Berniukai[i][j];
            counter++;
        }
    }
    int index, temp;
    for(int i = 0; i < counter; i++) {
        index = i;
        for(int j = i + 1; j < counter; j++)
            if(Atrinkti[j] > Atrinkti[index]) index = j;
        temp = Atrinkti[i];
        Atrinkti[i] = Atrinkti[index];
        Atrinkti[index] = temp;
    }
}

void Rikiavimas(int m, int index, int Berniukai[][100])
{
    int index1, temp;
    for(int i = 0; i < m; i++) {
        index1 = i;
        for(int j = i + 1; j < m; j++) 
            if(Berniukai[index][j] > Berniukai[index][index1]) index1 = j;
        temp = Berniukai[index][i];
        Berniukai[index][i] = Berniukai[index][index1];
        Berniukai[index][index1] = temp;
    }
}

void Rasymas(int counter, int Atrinkti[])
{
    ofstream fr("rezultatai.txt");
    fr << "Trenerio atrinktu kandidatu sarasas:" << endl;
    for(int i = 0; i < counter; i++) 
        fr << Atrinkti[i] << " ";
    fr.close();
}