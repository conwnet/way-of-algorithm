#include <stdio.h>
#include <string.h>

char str[15];

int main()
{
        scanf("%s", str);
        int pos = -1;
        for(int i=0; str[i]; i++) {
                if(str[i]=='?') {
                        pos = i;
                        break;
                }
        }
        int sum = 0;
        for(int i=0; str[i]; i++) {
                if(i==pos) continue;
                if(str[i]!='X')
                        sum += (str[i]-'0') * (10-i);
                else sum += 10 * (10-i);
        }
        int ok = 0;
        for(int i=0; i<11; i++) {
                if(pos!=9 && i==10) break;
                if((sum + i*(10-pos)) % 11 == 0) {
                        if(i==10) printf("X\n");
                        else printf("%d\n", i);
                        ok = 1; break;
                }
        }
        if(!ok) printf("-1\n");

        return 0;
}





