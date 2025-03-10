#include <iostream>
#include <cmath>
using namespace std;
void Skaitymas(int &n, int &x0, int &y0, int X[], int Y[], double A[]);
void Rikiavimas(int n, int X[], int Y[], double A[]);
void Rasymas(int X[], int Y[], double A[]);
int main()
{
    int n, x0, y0, X[100], Y[100];
    double A[100];
    Skaitymas(n, x0, y0, X, Y, A);
    Rikiavimas(n, X, Y, A);
    Rasymas(X, Y, A);
    return 0;
}

void Skaitymas(int &n, int &x0, int &y0, int X[], int Y[], double A[])
{
    cin >> n >> x0 >> y0;
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
        A[i] = sqrt(pow((x0 - X[i]), 2) + pow((y0 - Y[i]), 2));
    }
}

void Rikiavimas(int n, int X[], int Y[], double A[])
{
    int index;
    double temp;
    for(int i = 0; i < n; i++){
        index = i;
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[index]){
                index = j;
            }
        }
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;

        temp = X[i];
        X[i] = X[index];
        X[index] = temp;

        temp = Y[i];
        Y[i] = Y[index];
        Y[index] = temp;
    }
}

void Rasymas(int X[], int Y[], double A[])
{
    for(int i = 0; i < 3; i++) {
        cout << "(" << X[i] << "; " << Y[i] << ")" << endl;
    }
    

}