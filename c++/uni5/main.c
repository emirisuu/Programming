#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SandelioTurtas {
    char pavadinimas[50];
    double kaina;
    int kiekis;
};

struct CechoUzsakymas {
    char pavadinimas[50];
    int kiekis;
};

void Skaitymas(int *n, int *m, int *k, struct SandelioTurtas **A, struct CechoUzsakymas **B);
void Skaiciavimai(struct SandelioTurtas **A, struct SandelioTurtas **C, struct CechoUzsakymas **B, int *n, int *m, int *z);
void Rikiavimas(struct SandelioTurtas **C, int z);
void Rasymas(struct SandelioTurtas *C, int z);

int main() {
    struct SandelioTurtas *A, *C;
    int n = 0, m = 0, k = 0, z = 0;
    A = (struct SandelioTurtas *)malloc(1000 * sizeof(struct SandelioTurtas));
    struct CechoUzsakymas *B;
    B = (struct CechoUzsakymas *)malloc(1000 * sizeof(struct CechoUzsakymas));
    Skaitymas(&n, &m, &k, &A, &B);
    if(k == 1) printf("Ivestas neteisingas duomenu formatas. Prasome pataisyti duomenu faila.\n");
    else {
        Skaiciavimai(&A, &C, &B, &n, &m, &z);
        Rasymas(C, z);
    }
    return 0;
}

void Skaitymas(int *n, int *m, int *k, struct SandelioTurtas **A, struct CechoUzsakymas **B) {
    char temp[50], temp1[50], temp2[50];
    FILE *fd1 = fopen("F1.txt", "r");
    while(fscanf(fd1, "%s %s %s", temp, temp1, temp2) != EOF) {
        if(strcmp((*A)[*n - 1].pavadinimas, temp) == 0 && atof(temp1) == (*A)[*n - 1].kaina && atoi(temp2) == (*A)[*n - 1].kiekis) continue;
        if(/* Zodis(temp) || NesveikasSkaicius(temp1) || SveikasSkaicius(temp2) */ 0) {
            *k = 1;
            return;
        }
        strcpy((*A)[*n].pavadinimas, temp);
        (*A)[*n].kaina = atof(temp1);
        (*A)[*n].kiekis = atoi(temp2);
        (*n)++;
    }
    fclose(fd1);
    FILE *fd2 = fopen("F2.txt", "r");
    while(fscanf(fd2, "%s %s", temp, temp1) != EOF) {
        if(strcmp((*B)[*m - 1].pavadinimas, temp) == 0 && atoi(temp1) == (*B)[*m - 1].kiekis) continue;
        if(/* Zodis(temp) || SveikasSkaicius(temp1) */ 0) {
            *k = 1;
            return;
        }
        strcpy((*B)[*m].pavadinimas, temp);
        (*B)[*m].kiekis = atoi(temp1);
        (*m)++;
    }
    fclose(fd2);
}

void Skaiciavimai(struct SandelioTurtas **A, struct SandelioTurtas **C, struct CechoUzsakymas **B, int *n, int *m, int *z) {
    *C = (struct SandelioTurtas *)malloc((*n) * sizeof(struct SandelioTurtas));
    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < *m; j++) {
            if(strcmp((*A)[i].pavadinimas, (*B)[j].pavadinimas) == 0 && (*A)[i].kiekis >= (*B)[j].kiekis) {
                strcpy((*C)[*z].pavadinimas, (*A)[i].pavadinimas);
                (*C)[*z].kaina = (*A)[i].kaina;
                (*C)[*z].kiekis = (*B)[j].kiekis;
                (*z)++;
                (*A)[i].kiekis -= (*B)[j].kiekis;
                break;
            }
        }
    }
    free(*B);
    Rikiavimas(C, *z);
}

void Rikiavimas(struct SandelioTurtas **C, int z) {
    struct SandelioTurtas temp;
    int index;
    for(int i = 0; i < z; i++) {
        index = i;
        for(int j = i + 1; j < z; j++) {
            if((*C)[j].kiekis == (*C)[index].kiekis) {
                if((*C)[j].kaina > (*C)[index].kaina) index = j;
            } else if((*C)[j].kiekis > (*C)[index].kiekis) index = j;
        }
        temp = (*C)[i];
        (*C)[i] = (*C)[index];
        (*C)[index] = temp;
    }
}

void Rasymas(struct SandelioTurtas *C, int z) {
    FILE *fr = fopen("rezultatai.txt", "w");
    fprintf(fr, "eil.nr. %10s %7s %7s\n", "pavadinimas", "kiekis", "kaina");
    for(int i = 0; i < z; i++) {
        fprintf(fr, "%7d %11s %6d %7.2f\n", i + 1, C[i].pavadinimas, C[i].kiekis, C[i].kaina);
    }
    fclose(fr);
}

