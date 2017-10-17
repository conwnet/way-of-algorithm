#include <stdio.h>
#include <string.h>

const int maxn = 1e6;
int vst[maxn], num[400], N;

int modul(int n)
{
        memset(vst, 0, sizeof(vst));
        for(int i=0; i<N; i++) {
                int m = num[i]%n;
                if(!vst[m]) vst[m] = 1;
                else return 0;
        }
        return 1;
}

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(int i=0; i<N; i++)
                        scanf("%d", &num[i]);
                int i;
                for(i=1; ; i++)
                        if(modul(i)) break;
                printf("%d\n", i);
        }

        return 0;
}
