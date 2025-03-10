#include <iostream>
#include <fstream>

using namespace std;
ifstream fd("duomenys.txt");
ofstream fr("rezultatai.txt");

int main()
{
    int n, litrai, A[100];
    bool turis;
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> A[i];
    }
    fd >> litrai;
    for(int i = 0; i < n; i++) {
        if(A[i] == litrai) {
            turis = true;
            break;
        }
        turis = false;
    }
    if(turis) {
        fr << "taip";
    }
    else {
        fr << "ne";
    }
    return 0;
}