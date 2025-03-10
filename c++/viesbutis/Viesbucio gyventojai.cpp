#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Gyventojas
{
    string VardasPavarde;
    int metai, menesis, diena, laikas, ismetai, ismenesis, isdiena;
    double kaina, sumokejo;
};

void Skaitymas(int &n, Gyventojas A[]);
void Isvyko(int n, Gyventojas A[]);
void Rikiavimas(int n, Gyventojas A[]);
void Rasymas(int n, Gyventojas A[], double pajamos);

int main()
{
    Gyventojas A[100];
    int n;
    double pajamos = 0;
    Skaitymas(n, A);
    for(int i = 0; i < n; i++)
        A[i].sumokejo = A[i].laikas * A[i].kaina;
    Isvyko(n, A);
    for(int i = 0; i < n; i++)
        pajamos += A[i].sumokejo;
    Rikiavimas(n, A);
    Rasymas(n, A, pajamos);
    return 0;
}

void Skaitymas(int &n, Gyventojas A[])
{
    ifstream fd("Viesbucio_gyventojai.txt");
    fd >> n;
    char eil[21];
    for(int i = 0; i < n; i++) {
        fd.ignore(80, '\n');
        fd.get(eil, 21);
        A[i].VardasPavarde = eil;
        fd >> A[i].metai >> A[i].menesis >> A[i].diena >> A[i].laikas >> A[i].kaina;
        A[i].ismetai = A[i].metai;
        A[i].ismenesis = A[i].menesis;
        A[i].isdiena = A[i].diena;
    }
    fd.close();
}

void Isvyko(int n, Gyventojas A[])
{
    int temp;
    for(int i = 0; i < n; i++) {
        while(A[i].laikas > 0) {
            if(A[i].ismenesis == 1 || A[i].ismenesis == 3 || A[i].ismenesis == 5 || A[i].ismenesis == 7 || A[i].ismenesis == 8 || A[i].ismenesis == 10 || A[i].ismenesis == 12) {
                if(A[i].ismenesis == 12) {
                    if(A[i].isdiena + A[i].laikas > 31) {
                        temp = 31 - A[i].isdiena + 1;
                        A[i].laikas -= temp;
                        A[i].isdiena += temp;
                        if(A[i].isdiena > 31) {
                            A[i].isdiena = 1;
                            A[i].ismenesis = 1;
                            A[i].ismetai += 1;
                        } 
                    }
                    else {
                        A[i].isdiena += A[i].laikas;
                        A[i].laikas = 0;
                    }
                }
                else {
                    if(A[i].isdiena + A[i].laikas > 31) {
                        temp = 31 - A[i].isdiena + 1;
                        A[i].laikas -= temp;
                        A[i].isdiena += temp;
                        if(A[i].isdiena > 31) {
                            A[i].isdiena = 1;
                            A[i].ismenesis += 1;
                        }
                    }
                    else {
                        A[i].isdiena += A[i].laikas;
                        A[i].laikas = 0;
                    }
                }
            }
            else if(A[i].ismenesis == 4 || A[i].ismenesis == 6 || A[i].ismenesis == 9 || A[i].ismenesis == 11) {
                if(A[i].isdiena + A[i].laikas > 30) {
                    temp = 30 - A[i].isdiena + 1;
                    A[i].laikas -= temp;
                    A[i].isdiena += temp;
                    if(A[i].isdiena > 30) {
                        A[i].isdiena = 1;
                        A[i].ismenesis += 1;
                    } 
                }
                else {
                    A[i].isdiena += A[i].laikas;
                    A[i].laikas = 0;
                }
            }
            else {
                if(A[i].ismetai % 4 == 0) {
                    if(A[i].ismetai % 100 != 0 || A[i].ismetai % 100 == 0 && A[i].ismetai % 400 == 0) {
                        if(A[i].isdiena + A[i].laikas > 29) {
                            temp = 29 - A[i].isdiena + 1;
                            A[i].laikas -= temp;
                            A[i].isdiena += temp;
                            if(A[i].isdiena > 29) {
                                A[i].isdiena = 1;
                                A[i].ismenesis += 1;
                            } 
                        }
                        else {
                            A[i].isdiena += A[i].laikas;
                            A[i].laikas = 0;
                        }
                    }
                    else {
                        if(A[i].isdiena + A[i].laikas > 28) {
                            temp = 28 - A[i].isdiena + 1;
                            A[i].laikas -= temp;
                            A[i].isdiena += temp;
                            if(A[i].isdiena > 28) {
                                A[i].isdiena = 1;
                                A[i].ismenesis += 1;
                            } 
                        }
                        else {
                            A[i].isdiena += A[i].laikas;
                            A[i].laikas = 0;
                        }
                    }
                }
                else {
                    if(A[i].isdiena + A[i].laikas > 28) {
                        temp = 28 - A[i].isdiena + 1;
                        A[i].laikas -= temp;
                        A[i].isdiena += temp;
                        if(A[i].isdiena > 28) {
                            A[i].isdiena = 1;
                            A[i].ismenesis += 1;
                        } 
                    }
                    else {
                        A[i].isdiena += A[i].laikas;
                        A[i].laikas = 0;
                    }
                }
            }
        }
        A[i].isdiena -= 1;
    }
}

void Rikiavimas(int n, Gyventojas A[])
{
    int index;
    Gyventojas temp;
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i + 1; j < n; j++)
            if(A[j].sumokejo > A[index].sumokejo) index = j;
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}

void Rasymas(int n, Gyventojas A[], double pajamos)
{
    ofstream fr("viesbutisrez.txt");
    fr << "Pavardė, vardas          Atvyko      Išvyko      Sumokėjo" << endl;
    for(int i = 0; i < n; i++)
        fr << A[i].VardasPavarde << A[i].metai << " " << A[i].menesis << " " << A[i].diena << " " << A[i].ismetai << " " << A[i].ismenesis << " " << A[i].isdiena << " " << fixed << setprecision(2) << A[i].sumokejo << endl;
    fr << "Viešbučio pajamos: " << fixed << setprecision(2) << pajamos;
    fr.close();
}   