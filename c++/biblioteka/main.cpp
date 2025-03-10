#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int Kartai[], string Dienos[], int &k);
void Rikiavimas(int Kartai[], string Dienos[]);
void Rasymas(int Kartai[], string Dienos[], int k);

int main()
{
    int Kartai[7], k = 0;
    string Dienos[7];
    Skaitymas(Kartai, Dienos, k);
    Rikiavimas(Kartai, Dienos);
    Rasymas(Kartai, Dienos, k);
    return 0;
}

void Skaitymas(int Kartai[], string Dienos[], int &k)
{
    string temp;
    ifstream fd("duom.txt");
    for(int i = 0; i < 7; i++) {
        fd >> temp;
        for(int j = 0; j < temp.length(); j++)
            if(temp[j] > 57 || temp[j] < 47) {
                k = 1;
                break;
            }
        
        if(k == 1) break;
        else Kartai[i] = stoi(temp);
    }
    Dienos[0] = "Pirmadienis";
    Dienos[1] = "Antradienis";
    Dienos[2] = "Trečiadienis";
    Dienos[3] = "Ketvirtadienis";
    Dienos[4] = "Penktadienis";
    Dienos[5] = "Šeštadienis";
    Dienos[6] = "Sekmadienis";
    fd.close();
}

void Rikiavimas(int Kartai[], string Dienos[])
{
    int index;
    int temp;
    string temp1;
    for(int i = 0; i < 7; i++) {
        index = i;
        for(int j = i + 1; j < 7; j++)
            if(Kartai[j] < Kartai[index]) index = j;
        temp = Kartai[i];
        Kartai[i] = Kartai[index];
        Kartai[index] = temp;

        temp1 = Dienos[i];
        Dienos[i] = Dienos[index];
        Dienos[index] = temp1;
    }
}

void Rasymas(int Kartai[], string Dienos[], int k)
{
    ofstream fr("rez.txt");
    if(k == 1) fr << "Suvesti neįmanomi/neteisingi duomenys.";
    else {
        for(int i = 0; i < 7; i++)
            fr << Dienos[i] << endl;
    }
    fr.close();
}