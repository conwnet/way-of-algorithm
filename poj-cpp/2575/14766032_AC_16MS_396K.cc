#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vst[3010];

int main()
{
        int n, a, b, faild;

        while(~scanf("%d", &n)) {
                faild = 0;
                memset(vst, 0, sizeof(vst));
                if(n>0) scanf("%d", &a);
                for(int k=1; k<n; k++) {
                        scanf("%d", &b);
                        int c = abs(b-a);
                        if(c>0 && c<n)
                                vst[c] = 1;
                        a = b;
                }
                for(int i=1; i<n; i++) if(!vst[i]) faild = 1;
                printf("%s\n", faild ? "Not jolly" : "Jolly");
        }

        return 0;
}
