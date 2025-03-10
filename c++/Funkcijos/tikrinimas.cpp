#include <iostream>

using namespace std;

bool Zodis(string zodis)
{
    for(int i = 0; i < zodis.length(); i++) {
            if((zodis[i] >= 65 && zodis[i] <= 90) || (zodis[i] >= 97 && zodis[i] <= 122)) continue;
            else {
                return true;
            }
        }
    return false;
}

bool NesveikasSkaicius(string skaicius)
{
    for(int i = 0; i < skaicius.length(); i++) {
            if((skaicius[i] >= 48 && skaicius[i] <= 57) || skaicius[i] == 46) continue;
            else {
                return true;
            }
        }
    return false;
}

bool SveikasSkaicius(string skaicius)
{
    for(int i = 0; i < skaicius.length(); i++) {
            if(skaicius[i] >= 48 && skaicius[i] <= 57) continue;
            else {
                return true;
            }
        }
    return false;
}