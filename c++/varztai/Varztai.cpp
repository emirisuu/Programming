#include <iostream>
#include <fstream>

using namespace std;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
void Skaitymas(int A[]);

int main()
{
    int Varztai[21] = {0}, Verzles[21] = {0}, r = 0;
    Skaitymas(Varztai);
    Skaitymas(Verzles);
    fd.close();
    fr << "Reikalingi varžtai:" << endl;
    for(int i = 0; i < 21; i++) {
        if(Varztai[i] != Verzles[i] && Varztai[i] < Verzles[i]) {
            r++;
            fr << Verzles[i] - Varztai[i] << " " << i << endl;
        }
    }
    if(r == 0) {
        fr << "Varžtų nereikia" << endl;
    }
    r = 0;
    fr << "Reikalingos veržlės:" << endl;
    for(int i = 0; i < 21; i++) {
        if(Verzles[i] != Varztai[i] && Verzles[i] < Varztai[i]) {
            r++;
            fr << Varztai[i] - Verzles[i] << " " << i << endl;
        }
    }
    if(r == 0) {
        fr << "Veržlių nereikia";
    }
    return 0;
}
void Skaitymas(int A[])
{
    int nr, n;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> nr;
        A[nr]++;
    }
}