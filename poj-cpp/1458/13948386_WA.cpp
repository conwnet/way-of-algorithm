#include <stdio.h>
#include <string.h>

int main()
{
    char str1[1024], str2[1024], *ss, *ee;
    int l1, l2, i, j, l, t, flag;

    while(~scanf("%s%s", &str1, str2)){
        l1 = strlen(str1);
        l = l2 = strlen(str2);
        do{
            flag = 0;
            for(ss=str2; *(ss+l-1)!='\0'; ss++){
                for(i=0, t=0; i<l1; i++){
                    if(str1[i]==ss[t]){
                        t++;
                    }
                }
                if(t==l){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }while(--l);
        printf("%d\n", l);
    }

    return 0;
}
