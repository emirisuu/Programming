#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int &n, string Simboliai[], char Raide[], char Sakinys[], int &s);
int Kodas(int n, char Raide[], string Simboliai[], char raide);
void Rasymas(int n, string Simboliai[], char Raide[], char Sakinys[], int s);

int main()
{
    int n, s = 0;
    string Simboliai[100];
    char Raide[100], Sakinys[100];
    Skaitymas(n, Simboliai, Raide, Sakinys, s);
    Rasymas(n, Simboliai, Raide, Sakinys, s);
    return 0;
}

void Skaitymas(int &n, string Simboliai[], char Raide[], char Sakinys[], int &s)
{
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd >> Raide[i] >> Simboliai[i];
    }
    fd.close();
    ifstream fd1("duomenys2.txt");
    while(!fd1.eof()) {
        fd >> Sakinys[s];
        s++;
    }
    fd1.close();
}

int Kodas(int n, char Raide[], string Simboliai[], char raide)
{
    for(int i = 0; i < n; i++)
        if(raide == Raide[i]) return i;
}

void Rasymas(int n, string Simboliai[], char Raide[], char Sakinys[], int s)
{
    ofstream fr("rezultatai.txt");
    string temp = "";
    int index;
    for(int i = 0; i < s; i++) {
        cout << Sakinys[i] << endl;
        if(Sakinys[i] == ' ' || Sakinys[i] == '.') {
           fr << temp << endl;
           temp = "";
        }
        else {
            index = Kodas(n, Raide, Simboliai, Sakinys[i]);
            temp += Simboliai[index] + " ";
        }
    }
    fr.close();
}
