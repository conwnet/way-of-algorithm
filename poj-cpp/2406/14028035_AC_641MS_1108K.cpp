#include <stdio.h>
#include <string.h>

char str[1000010];

int main()
{
        int i, j, k, l, t, faild;

        while(scanf("%s", str)) {
                if(str[0]=='.' && str[1]=='\0') break;
                l = strlen(str);
                for(i=l; i>0; i--) {
                        if(l%i!=0) continue;
                        t = l/i;
                        faild = 0;
                        for(j=0; j<t; j++) {
                                for(k=1; k<i; k++) {
                                        if(str[j]!=str[j+k*t]) {
                                                faild = 1;
                                                break;
                                        }
                                }
                                if(faild) break;
                        }
                        if(!faild) break;
                }
                printf("%d\n", i);
        }

        return 0;
}
