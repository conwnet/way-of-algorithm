#include <stdio.h>
#include <string.h>


int next[15], dat[15], vst[15];

int main()
{
        int T, N;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(int i=0; i<N-1; i++)
                        next[i] = i+1;
                next[N-1] = 0;
                memset(vst, 0, sizeof(vst));
                memset(dat, 0, sizeof(dat));
                dat[1] = 1; int p = 1; vst[1] = 1;
                for(int i=1; i<N; i++) {
                        int n = i+1;
                        while(vst[dat[p]]) p = next[p];
                        while(n) {
                                p = next[p];
                                if(vst[dat[p]]) continue;
                                n--;
                        }
                        dat[p] = i+1;
                        vst[dat[p]] = 1;
                }
                printf("%d", dat[0]);
                for(int i=1; i<N; i++)
                        printf(" %d", dat[i]);
                printf("\n");
        }

        return 0;
}
