#include <iostream>

using namespace std;

struct Patiekalas
{
    string pavadinimas;
    int kalorijos;
};

void Rikiavimas(Patiekalas meniu[])
{
    Patiekalas temp;
    int index;
    for(int i = 0; i < 10; i++) {
        index = i;
        for(int j = i + 1; j < 10; j++) if(meniu[j].kalorijos < meniu[index].kalorijos) index = j;

        temp = meniu[i];
        meniu[i] = meniu[index];
        meniu[index] = temp;
    }
}

int main()
{
    Patiekalas meniu[10];
    meniu[0] = {"Pica", 800};
    meniu[1] = {"Burgeris", 600};
    meniu[2] = {"Makaronai", 500};
    meniu[3] = {"Salotos", 200};
    meniu[4] = {"Sriuba", 300};
    meniu[5] = {"Troskinys", 400};
    meniu[6] = {"Kepsnys", 1200};
    meniu[7] = {"Antiena", 800};
    meniu[8] = {"Vistiena", 900};
    meniu[9] = {"Kepta duona", 500};
    Rikiavimas(meniu);
    cout << "Restorano pilnas meniu: " << endl;
    for(int i = 0; i < 10; i++) cout << meniu[i].pavadinimas << " " << meniu[i].kalorijos << endl;
    return 0;
}