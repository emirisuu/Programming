#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &counter, int Padalinys[], int Vaztarastis[]);
int Radimas(int n, int X[], int gaidys);
void Iterpimas(int &counter, int Padalinys[], int Vaztarastis[], int index, int temp, int temp1);
void Rasymas(int counter, int Padalinys[], int Vaztarastis[]);

int main()
{
    int counter, Padalinys[100], Vaztarastis[100];
    Skaitymas(counter, Padalinys, Vaztarastis);
    Rasymas(counter, Padalinys, Vaztarastis);
    return 0;
}

void Skaitymas(int &counter, int Padalinys[], int Vaztarastis[])
{
    ifstream fd1("seni.txt");
    fd1 >> counter;
    for(int i = 0; i < counter; i++) {
        fd1 >> Padalinys[i] >> Vaztarastis[i];
    }
    fd1.close();
    ifstream fd2("nauji.txt");
    int n, temp, temp1, index;
    fd2 >> n;
    for(int i = 0; i < n; i++) {
        fd2 >> temp >> temp1;
        index = Radimas(counter, Padalinys, temp);
        if(index >= 0) {
            Iterpimas(counter, Padalinys, Vaztarastis, index, temp, temp1);
        }
    }
    fd2.close();
}

int Radimas(int n, int X[], int gaidys)
{
    int index = - 1;
    for(int i = 0; i < n; i++) {
        if(X[i] == gaidys) {
            index = i;
            break;
        }
    }
    return index;
}

void Iterpimas(int &counter, int Padalinys[], int Vaztarastis[], int index, int temp, int temp1)
{
    for(int i = counter; i > index + 1; i--) {
        Padalinys[i] = Padalinys[i - 1];
        Vaztarastis[i] = Vaztarastis[i - 1];
    }
    Padalinys[index + 1] = temp;
    Vaztarastis[index + 1] = temp1;
    counter++;
}

void Rasymas(int counter, int Padalinys[], int Vaztarastis[])
{
    ofstream fr("ataskaita.txt");
    cout << counter;
    fr << counter << endl;
    for(int i = 0; i < counter; i++) {
        fr << Padalinys[i] << " " << Vaztarastis[i] << endl;
    }
    fr.close();
}