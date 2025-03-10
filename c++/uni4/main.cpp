#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Skaitymas(int &n, int &k, string *&Zodziai);
string Sakinys(int n, string *Zodziai);
void Rasymas(string sakinys);

int main()
{
    int n = 0, k = 0;
    string* Zodziai = NULL, sakinys;
    Skaitymas(n, k, Zodziai);
    if(k != 0) {
        cout << "Ivesti neteisingi duomenys. Zodziuose negali buti jokiu simboliu, prasome pataisyti duomenu faila.";
        return 0;
    }
    sakinys = Sakinys(n, Zodziai);
    if (Zodziai != NULL) {
        delete[] Zodziai;
    }
    Rasymas(sakinys);
    return 0;
}

void Skaitymas(int &n, int &k, string *&Zodziai)
{
    ifstream fd("duomenys.txt");
    string temp;
    getline(fd, temp, '\n');
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == ' ') n++;
    }
    n++;
    Zodziai = new string[n];
    int index = 0, wordIndex = 0;
    while (index < temp.length() && wordIndex < n) {
        string temp1 = "";
        while (index < temp.length() && temp[index] != ' ') {
            temp1 += temp[index];
            index++;
        }
        Zodziai[wordIndex++] = temp1;
        index++;
    }
    for(int i = 0; i < n; i++) {
        for(int j= 0; j < Zodziai[i].length(); j++) 
            if((Zodziai[i][j] >= 65 && Zodziai[i][j] <= 90) || (Zodziai[i][j] >= 97 && Zodziai[i][j] <= 122)) continue;
            else {
                k = 1;
                return;
            }
    }
    fd.close();
}

string Sakinys(int n, string *Zodziai)
{
    string sakinys = "";
    for(int i = 0; i < n; i++) {
        string temp = Zodziai[i];
        for(int j = 0; j < Zodziai[i].length(); j++) {
            if(Zodziai[i].length() - 2 == j) break;
            if(Zodziai[i][j] == 'l' && Zodziai[i][j+1] == 'i' && Zodziai[i][j+2] == 's') {
                temp.insert(j, "emi");
                break;
            }
        }
        if(i != n - 1) sakinys += temp + " ";
        else sakinys += temp;
    }
    return sakinys;
}

void Rasymas(string sakinys)
{
    ofstream fr("rezultatai.txt");
    fr << sakinys;
    fr.close();
}