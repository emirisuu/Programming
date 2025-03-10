#include <iostream>
#include <fstream>

using namespace std;
ifstream fd("duomenys.txt");
ofstream fr("rezultatai.txt");
int CiaFunkcijosNereikiaMokytoja(int n, int lenteles, int temp, int skaitmenys, int temp1, int temp2);
int main()
{
    int n, lenteles = 0, temp, skaitmenys = 1, temp1, temp2;
    fd >> n;
    temp = n;
    fd.close();
    lenteles = CiaFunkcijosNereikiaMokytoja(n, lenteles, temp, skaitmenys, temp1, temp2);
    fr << lenteles;
    fr.close();
    return 0;
}

int CiaFunkcijosNereikiaMokytoja(int n, int lenteles, int temp, int skaitmenys, int temp1, int temp2)
{
    while(temp > 10) {
        temp /= 10;
        skaitmenys++;
    }
    for(int i = n; i > 0; i--) {
        temp1 = 1;
        temp2 = i;
        lenteles += 1 * skaitmenys;
        while(temp2 > 10) {
            temp2 /= 10;
            temp1++;
        }
        if(temp1 < skaitmenys) {
            skaitmenys -= 1;
        }
    }
    return lenteles;
}