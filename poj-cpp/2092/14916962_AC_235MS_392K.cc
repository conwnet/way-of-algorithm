#include <stdio.h>
#include <string.h>

int buk[10010], N, M;

int main()
{
        while(scanf("%d%d", &N, &M)) {
                if(!N && !M) break;
                memset(buk, 0, sizeof(buk));
                int u;
                for(int i=0; i<M*N; i++) {
                        scanf("%d", &u);
                        buk[u]++;
                }
                int mi, mi2;
                mi = mi2 = 0;
                for(int i=1; i<=10000; i++)
                        if(buk[i] > mi) mi = buk[i];
                for(int i=1; i<=10000; i++) {
                        if(buk[i]==mi) continue;
                        if(buk[i] > mi2) mi2 = buk[i];
                }
                int i;
                for(i=1; i<=10000; i++)
                        if(buk[i]==mi2) { printf("%d", i); break; }
                for(i++; i<=10000; i++)
                        if(buk[i]==mi2) printf(" %d", i);
                printf("\n");
        }
        return 0;
}
