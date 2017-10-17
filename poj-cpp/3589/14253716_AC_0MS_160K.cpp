#include <stdio.h>

int main()
{
        char n1[5], n2[5];
        int i, j, ca, cb, T;

        scanf("%d", &T);
        while(T--) {
                scanf("%s%s", n1, n2);
                ca = cb = 0;
                for(i=0; i<4; i++) if(n1[i]==n2[i]) ca++;
                for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                                if(n1[i]==n2[j]) {
                                        cb++;
                                        n2[j] = '*';
                                }
                printf("%dA%dB\n", ca, cb-ca);
        }

        return 0;
}
