#include <iostream>

using namespace std;

int main()
{
    int eilutes;
    cout << "Iveskite eiluciu skaiciu: ";
    cin >> eilutes;
    for(int i = 1; i <= eilutes; i++) {
        string eilute = "";
        for(int j = 1; j <= i; j++) eilute += to_string(j);
        cout << eilute << endl;
    }
    return 0;
}