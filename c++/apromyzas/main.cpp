#include <iostream>
#include <fstream>

using namespace std;

struct Dievas
{
    string vardas;
    int A[10];
};

void Skaitymas(int &n, int &m, Dievas D[]);
void Taskai(int n, int m, Dievas D[], int V[], int L[]);
int Max(int n, int V[], int L[]);
void Rasymas(int did, Dievas D[], int V[]);

int main()
{
    int n, m, L[50] = {0}, V[50] = {0};
    Dievas D[50];
    Skaitymas(n, m, D);
    Taskai(n, m, D, V, L);
    int maxi = Max(n, V, L);
    Rasymas(maxi, D, V);
    return 0;
}
void Skaitymas(int &n, int &m, Dievas D[])
{
    ifstream fd("U2.txt");
    fd >> n >> m;
    char temp[11];
    for (int i=0; i<n; i++)
    {
        fd.ignore(80, '\n');
        fd.get(temp, 11);
        D[i].vardas = temp;
        fd >> ws;
        for (int j = 0; j < m; j++)
        {
            fd >> D[i].A[j];
        }
    }
    fd.close();
}
void Taskai(int n, int m, Dievas D[], int V[], int L[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (D[i].A[j]%2 == 0)
            {
                V[i] = V[i] + D[i].A[j];
                L[i]++;
            }
            else
            {
                V[i] = V[i] - D[i].A[j];
            }
        }
    }

}
int Max(int n, int V[], int L[])
{
    int maxi = 0;
    for(int i = 1; i < n; i++)
    {
        if(V[maxi] < V[i] || V[maxi] == V[i] && L[i] > L[maxi])
            maxi = i;
    }
    return maxi;
}
void Rasymas(int maxi, Dievas D[], int V[])
{
    ofstream fr("U2rez.txt");
    fr << D[maxi].vardas << " " << V[maxi];
    fr.close();
}