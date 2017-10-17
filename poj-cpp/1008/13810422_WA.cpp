#include <stdio.h>
#include <string.h>

int main(){
    int n, i, hd, hy, day, ty;
    char Haab[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    char Tzol[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    char hm[10];

    while(~scanf("%d", &n)){
printf("%d\n", n);
        while(n--){
            scanf("%d.%s%d", &hd, hm, &hy);
            ty = hy*365/260;
            for(i=0; i<20; i++){
                if(strcmp(Haab[i], hm)==0) break;
            }
            day = i*20 + hd + 1 + hy*365%260;
            if(day/260>0 && day%260>0){
                ty += day/260;
                day %= 260;
            }
            printf("%d %s %d\n", day%13, Tzol[day%20-1], ty);
        }
    }

    return 0;
}