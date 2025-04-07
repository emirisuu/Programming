#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, counterN = 0, counterM = 0;
    vector<int> vektorius;
    cout << "Iveskite skaiciu N: ";
    cin >> n;
    cout << "Iveskite skaiciu M: ";
    cin >> m;
    while (true) {
        string temp = "";
        cout << "Pridekite skaiciu i vektoriu, norint uzbaigti vektoriu irasyti end: ";
        cin >> temp;
        if(temp == "end") break;
        vektorius.push_back(stoi(temp));
    }
    for(int i = 0; i < vektorius.size(); i++) {
        if(vektorius[i] == n) counterN++;
        if(vektorius[i] == m) counterM++;
    }
    if(counterN > counterM) cout << "Skaicius N(" << n << ") pasikartojo daugiau kartu.";
    else if(counterM > counterN) cout << "Skaicius M(" << m << ") pasikartojo daugiau kartu.";
    else cout << "Abu skaiciai pasikartojo tiek pat kartu arba ju nebuvo vektoriuje.";
    return 0;
}