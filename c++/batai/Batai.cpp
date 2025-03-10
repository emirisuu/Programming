#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int &counter, int Dydis[], char Lytis[]);
int Index(int counter, char Lytis[], int Dydis[], char lytis, int dydis);
void Salinimas(int &counter, int vyrindex, int motindex, char Lytis[], int Dydis[]);
void Rasymas(int counter, int vyrindex, int motindex, char Lytis[], int Dydis[]);

int main()
{
    int n, Dydis[100], counter = 0, vyrdydis = 43, motdydis = 38, vyrindex, motindex;
    char Lytis[100], vyras = 'v', moteris = 'm';
    Skaitymas(n, counter, Dydis, Lytis);
    vyrindex = Index(counter, Lytis, Dydis, vyras, vyrdydis);
    motindex = Index(counter, Lytis, Dydis, moteris, motdydis);
    Rasymas(counter, vyrindex, motindex, Lytis, Dydis);
    return 0;
}

void Skaitymas(int &n, int &counter, int Dydis[], char Lytis[])
{
    ifstream fd("duom.txt");
    int temp, k;
    char temp1;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> temp1 >> temp;
        k = 0;
        for(int j = 0; j < counter; j++) {
            if(temp1 == Lytis[j] && temp == Dydis[j]) {
                k = 1;
                break;
            }
            else {
                k = 0;
            }
        }
        if(k == 0) {
            Lytis[counter] = temp1;
            cout << Lytis[counter] << " ";
            Dydis[counter] = temp;
            cout << Dydis[counter] << endl;
            counter++;
        }
    }
    fd.close();
}

int Index(int counter, char Lytis[], int Dydis[], char lytis, int dydis)
{
    int index = 0;
    for(int i = 0; i < counter; i++) {
        if(lytis == Lytis[i] && dydis == Dydis[i]) {
            index = i;
            break;
        }
    }
    return index;
}

void Salinimas(int &counter, int vyrindex, int motindex, char Lytis[], int Dydis[])
{
    for(int i = 0; i < counter; i++) {
        if(i == vyrindex) {
            Lytis[i] = Lytis[i + 1];
            Dydis[i] = Dydis[i + 1];
            counter--;
            motindex--;
            vyrindex = 0;
            i--;
        }
        else if(i == motindex) {
            Lytis[i] = Lytis[i + 1];
            Dydis[i] = Dydis[i + 1];
            counter--;
            vyrindex--;
            motindex = 0;
            i--;
        }
    }
}

void Rasymas(int counter, int vyrindex, int motindex, char Lytis[], int Dydis[])
{
    ofstream fr("rez.txt");
    fr << "Batu sarasas" << endl;
    fr << "--------------" << endl;
    fr << " Tipas  Dydis" << endl;
    fr << "--------------" << endl;
    for(int i = 0; i < counter; i++) {
        fr << "  " << Lytis[i] << "     " << Dydis[i] << endl;
    }
    fr << "--------------" << endl;
    fr << "Mykolo 43-io dydzio batu indeksas masyve " << vyrindex << endl;
    fr << "Marytes 38-io dydzio batu indeksas masyve " << motindex << endl;
    Salinimas(counter, vyrindex, motindex, Lytis, Dydis);
    fr << "Batu sarasas" << endl;
    fr << "--------------" << endl;
    fr << " Tipas  Dydis" << endl;
    fr << "--------------" << endl;
    for(int i = 0; i < counter; i++) {
        fr << "  " << Lytis[i] << "     " << Dydis[i] << endl;
    }
    fr << "--------------" << endl;
    fr.close();
}