#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Skaitymas(int *n, int *k, char ***Zodziai);
char* Sakinys(int n, char **Zodziai);
void Rasymas(char *sakinys);

int main()
{
    int n = 0, k = 0;
    char **Zodziai = NULL;
    char *sakinys;
    Skaitymas(&n, &k, &Zodziai);
    if(k != 0) {
        printf("Ivesti neteisingi duomenys. Zodziuose negali buti jokiu simboliu, prasome pataisyti duomenu faila.");
        return 0;
    }
    sakinys = Sakinys(n, Zodziai);
    if (Zodziai != NULL) {
        for (int i = 0; i < n; i++) {
            free(Zodziai[i]);
        }
        free(Zodziai);
    }
    Rasymas(sakinys);
    free(sakinys);
    return 0;
}

void Skaitymas(int *n, int *k, char ***Zodziai)
{
    FILE *fd = fopen("duomenys.txt", "r");
    char temp[1000];
    fgets(temp, sizeof(temp), fd);
    char *token = strtok(temp, " ");
    while (token != NULL) {
        (*n)++;
        token = strtok(NULL, " ");
    }
    rewind(fd);
    *Zodziai = (char **)malloc((*n) * sizeof(char *));
    int index = 0;
    fgets(temp, sizeof(temp), fd);
    token = strtok(temp, " ");
    while (token != NULL) {
        (*Zodziai)[index] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        strcpy((*Zodziai)[index], token);
        index++;
        token = strtok(NULL, " ");
    }
    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < strlen((*Zodziai)[i]); j++) 
            if(((*Zodziai)[i][j] >= 65 && (*Zodziai)[i][j] <= 90) || ((*Zodziai)[i][j] >= 97 && (*Zodziai)[i][j] <= 122)) continue;
            else {
                *k = 1;
                fclose(fd);
                return;
            }
    }
    fclose(fd);
}

char* Sakinys(int n, char **Zodziai)
{
    char *sakinys = (char *)malloc(1000 * sizeof(char));
    strcpy(sakinys, "");
    for(int i = 0; i < n; i++) {
        char temp[100];
        strcpy(temp, Zodziai[i]);
        for(int j = 0; j < strlen(Zodziai[i]); j++) {
            if(strlen(Zodziai[i]) - 2 == j) break;
            if(Zodziai[i][j] == 'l' && Zodziai[i][j+1] == 'i' && Zodziai[i][j+2] == 's') {
                char newWord[100];
                snprintf(newWord, sizeof(newWord), "%.*semi%s", j, Zodziai[i], Zodziai[i] + j);
                strcpy(temp, newWord);
                break;
            }
        }
        if(i != n - 1) strcat(sakinys, strcat(temp, " "));
        else strcat(sakinys, temp);
    }
    return sakinys;
}

void Rasymas(char *sakinys)
{
    FILE *fr = fopen("rezultatai.txt", "w");
    fprintf(fr, "%s", sakinys);
    fclose(fr);
}

