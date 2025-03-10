#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Zodis(const char *zodis) {
    for(int i = 0; i < strlen(zodis); i++) {
        if(isalpha(zodis[i])) continue;
        else {
            return 1;
        }
    }
    return 0;
}

int NesveikasSkaicius(const char *skaicius) {
    for(int i = 0; i < strlen(skaicius); i++) {
        if(isdigit(skaicius[i]) || skaicius[i] == '.') continue;
        else {
            return 1;
        }
    }
    return 0;
}

int SveikasSkaicius(const char *skaicius) {
    for(int i = 0; i < strlen(skaicius); i++) {
        if(isdigit(skaicius[i])) continue;
        else {
            return 1;
        }
    }
    return 0;
}

