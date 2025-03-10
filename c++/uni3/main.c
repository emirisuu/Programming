#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Skaitymas(unsigned int *n, unsigned int *m, unsigned int Pinigai[][100], unsigned int *k);
unsigned int Skaiciavimai(unsigned int n, unsigned int m, unsigned int Pinigai[][100]);
void Rasymas(unsigned int kelio_suma);

int main()
{
    unsigned int n, m, Pinigai[100][100], kelio_suma, k = 0;
    Skaitymas(&n, &m, Pinigai, &k);
    if(k != 1){
        kelio_suma = Skaiciavimai(n, m, Pinigai);
        Rasymas(kelio_suma);
    }
    return 0;
}

void Skaitymas(unsigned int *n, unsigned int *m, unsigned int Pinigai[][100], unsigned int *k)
{
    FILE *fd = fopen("duomenys.txt", "r");
    if (fd == NULL) {
        printf("Nepavyko atidaryti failo.\n");
        *k = 1;
        return;
    }
    char temp[100];
    int len, A[2];
    for(int i = 0; i < 2; i++) {
        fscanf(fd, "%s", temp);
        len = strlen(temp);
        for(int j = 0; j < len; j++) {
            if(temp[j] < '0' || temp[j] > '9') {
                printf("Ivestas neteisingas n arba m duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaiciu be kablelio nuo 3 iki 100.");
                *k = 1;
                fclose(fd);
                return;
            }
        }
        A[i] = atoi(temp);
        if(A[i] < 3 || A[i] > 100) {
            printf("Ivestas neteisingas n arba m duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 3 iki 100.");
            *k = 1;
            fclose(fd);
            return;
        }
    }
    *n = A[0];
    *m = A[1];
    if(*n == *m) {
        printf("Skaiciai n ir m negali buti lygus. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 3 iki 100.");
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
                    printf("Ivestas neteisingas kelio kainos duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 1 iki 10000.");
                    *k = 1;
                    fclose(fd);
                    return;
                }
            }
            Pinigai[i][j] = atoi(temp);
            if(Pinigai[i][j] < 1 || Pinigai[i][j] > 10000) {
                printf("Ivestas neteisingas kelio kainos duomenu formatas. Prasome pataisyti duomenu faila ir ivesti skaicius be kablelio nuo 1 iki 10000.");
                *k = 1;
                fclose(fd);
                return;
            }
        }
    }
    fclose(fd);
}

unsigned int Skaiciavimai(unsigned int n, unsigned int m, unsigned int Pinigai[][100])
{
    int i = 0, j = 0, suma;
    suma = Pinigai[0][0] + Pinigai[n - 1][m - 1];
    while(i != n - 1 && j != m - 1) {
        if(i == n - 1) {
            suma += Pinigai[i][j+1];
            j++;
        }
        else if(j == m - 1) {
            suma += Pinigai[i+1][j];
            i++;
        }
        else if(Pinigai[i+1][j] == Pinigai[i][j+1]) {
            suma += Pinigai[i][j + 1];
            j++;
        }
        else if(Pinigai[i+1][j] < Pinigai[i][j+1]) {
            suma += Pinigai[i+1][j];
            i++;
        }
        else {
            suma += Pinigai[i][j+1];
            j++;
        }
    }
    return suma;
}

void Rasymas(unsigned int kelio_suma)
{
    FILE *fr = fopen("rezultatai.txt", "w");
    fprintf(fr, "Pigiausio kelio suma: %u", kelio_suma);
    fclose(fr);
}

