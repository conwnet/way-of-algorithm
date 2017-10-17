#include <stdio.h>

int p[6000], N, M;

int findp(int a)
{
        return p[a]==a ? a : p[a]=findp(p[a]);
}

int main()
{
        int i, nCase, a, b, flag, T=1;

        scanf("%d", &nCase);
        while(nCase--) {
                scanf("%d%d", &N, &M);
                for(i=0; i<N*2; i++) {
                        p[i] = i;
                }
                flag = 0;
                for(i=0; i<M; i++) {
                        scanf("%d%d", &a, &b);
                        int x = findp(a);
                        int y = findp(b);
                        if(x==y) flag = 1;
                        else {
                                p[x] = y;
                        }
                }
                printf("Scenario #%d:\n", T++);
                if(flag) printf("Suspicious bugs found!\n");
                else printf("No suspicious bugs found!\n");
                if(T!=nCase) printf("\n");
        }


        return 0;
}

