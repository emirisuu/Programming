#include <iostream>
#include <fstream>

using namespace std;
void Skaitymas(int &n, int A[], int temp, int temp1);
void Rasymas(int A[]);

int main()
{
    int n, A[100], temp, temp1;
    Skaitymas(n, A, temp, temp1);
    Rasymas(A);
    return 0;
}

void Skaitymas(int &n, int A[], int temp, int temp1)
{
    ifstream fd("duomenys.txt");
    for(int i = 0; i < 5; i++) {
        A[i] = 0;
    }
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> temp;
        if(temp == 0) {
            A[0]++;
        }
        else{
            for(int j = 0; j < temp; j++) {
                fd >> temp1;
                if(temp1 == 1) {
                    A[1]++;
                }
                else if(temp1 == 2) {
                    A[3]++;
                }
                else if(temp1 == 3) {
                    A[2]++;
                }
                else if(temp1 == 4) {
                    A[4]++;
                }
            }
        }
    }
    fd.close();
}

void Rasymas(int A[])
{
    ofstream fr("rezultatai.txt");
    for(int i = 0; i < 5; i++) {
        fr << A[i] << endl;
    }
    fr.close();
}