#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Skaitymas(int *n, int *m, int *x, int Berniukai[][100], int *k);
void Skaiciavimai(int n, int m, int x, int Berniukai[][100], int Atrinkti[], int *counter);
void Rikiavimas(int m, int index, int Berniukai[][100]);
void Rasymas(int counter, int Atrinkti[]);

int main()
{
    int n, m, x, Berniukai[100][100], Atrinkti[10000], counter = 0, k = 0;
    Skaitymas(&n, &m, &x, Berniukai, &k);
    if(k != 1){
        Skaiciavimai(n, m, x, Berniukai, Atrinkti, &counter);
        Rasymas(counter, Atrinkti);
    }
    return 0;
}

void Skaitymas(int *n, int *m, int *x, int Berniukai[][100], int *k)
{
    FILE *fd = fopen("duomenys.txt", "r");
    if (fd == NULL) {
        printf("Nepavyko atidaryti failo.\n");
        *k = 1;
        return;
    }
    char temp[100];
    int len, A[3];
    for(int i = 0; i < 3; i++) {
        fscanf(fd, "%s", temp);
        len = strlen(temp);
        for(int j = 0; j < len; j++) {
            if(temp[j] < '0' || temp[j] > '9') {
                printf("Ivestas neteisingas n, m arba x duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaiciu be kablelio nuo 1 iki 100.");
                *k = 1;
                fclose(fd);
                return;
            }
        }
        A[i] = atoi(temp);
        if(A[i] < 1 || A[i] > 100) {
            printf("Ivestas neteisingas n, m arba x duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 1 iki 100.");
            *k = 1;
            fclose(fd);
            return;
        }
    }
    *n = A[0];
    *m = A[1];
    *x = A[2];
    if(*x > *m) {
        printf("Ivestas neteisingas x duomenu formatas. Skaicius x negali buti didesnis uz skaiciu m ir turi buti skaicius be kablelio nuo 1 iki 100.");
        *k = 1;
        fclose(fd);
        return;
    }
    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < *m; j++) {
            fscanf(fd, "%s", temp);
            len = strlen(temp);
            for(int z = 0; z < len; z++) {
                if(temp[z] < '0' || temp[z] > '9') {
                    printf("Ivestas neteisingas berniuku ugio duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 50 iki 250.");
                    *k = 1;
                    fclose(fd);
                    return;
                }
            }
            Berniukai[i][j] = atoi(temp);
            if(Berniukai[i][j] < 50 || Berniukai[i][j] > 250) {
                printf("Ivestas neteisingas berniuku ugio duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 50 iki 250.");
                *k = 1;
                fclose(fd);
                return;
            }
        }
    }
    fclose(fd);
}

void Skaiciavimai(int n, int m, int x, int Berniukai[][100], int Atrinkti[], int *counter)
{
    for(int i = 0; i < n; i++) {
        Rikiavimas(m, i, Berniukai);
        for(int j = 0; j < x; j++) {
            Atrinkti[*counter] = Berniukai[i][j];
            (*counter)++;
        }
    }
    int index, temp;
    for(int i = 0; i < *counter; i++) {
        index = i;
        for(int j = i + 1; j < *counter; j++)
            if(Atrinkti[j] > Atrinkti[index]) index = j;
        temp = Atrinkti[i];
        Atrinkti[i] = Atrinkti[index];
        Atrinkti[index] = temp;
    }
}

void Rikiavimas(int m, int index, int Berniukai[][100])
{
    int index1, temp;
    for(int i = 0; i < m; i++) {
        index1 = i;
        for(int j = i + 1; j < m; j++) 
            if(Berniukai[index][j] > Berniukai[index][index1]) index1 = j;
        temp = Berniukai[index][i];
        Berniukai[index][i] = Berniukai[index][index1];
        Berniukai[index][index1] = temp;
    }
}

void Rasymas(int counter, int Atrinkti[])
{
    FILE *fr = fopen("rezultatai.txt", "w");
    if (fr == NULL) {
        printf("Nepavyko atidaryti failo.\n");
        return;
    }
    fprintf(fr, "Trenerio atrinktu kandidatu sarasas:\n");
    for(int i = 0; i < counter; i++) 
        fprintf(fr, "%d ", Atrinkti[i]);
    fclose(fr);
}

