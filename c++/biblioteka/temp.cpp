#include <iostream>

using namespace std;

int main()
{
    int n, A[10][10], m;
    int index = 0, Temp[n];
    for(int i = 0; i < n; i++) {
        int index1 = 0;
        for(int y = 0; y < m; y++) {
            if (A[i][y] < A[i][index1]) index1 = y;
        }
        Temp[i] = A[i][index1];
    }
    for(int i = 0; i < n; i++) {
        if(Temp[i] < Temp[index]) index = i;
    }
    if(Temp[index] < 0 ) {
        for(int i = 0; i < n; i++)
            for(int y = 0; y < m; y++)
                if(i != index) A[i][y] = 0;
    }
    else {
        for(int i = 0; i < n; i++)
            for(int y = 0; y < m; y++)
                A[i][y] = 0;
    }
    return 0;
}