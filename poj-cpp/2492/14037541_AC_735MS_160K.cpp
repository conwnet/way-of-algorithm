#include <stdio.h>

int p[6000], N, M;

int findp(int a)
{
        return p[a]==a ? a : p[a]=findp(p[a]);
}

void connect(int a, int b)
{
        int x = findp(a);
        int y = findp(b);
        if(x!=y) {
                p[x] = y;
        }
}

int main()
{
        int i, nCase, a, b, flag, T=1;

        scanf("%d", &nCase);
        while(nCase--) {
                scanf("%d%d", &N, &M);
                for(i=0; i<N*3; i++) {
                        p[i] = i;
                }
                flag = 0;
                for(i=0; i<M; i++) {
                        scanf("%d%d", &a, &b);
                        
                        if(findp(a)==findp(b)) flag = 1;
                        else {
                                connect(a, b+N);
                                connect(a+N, b);
                        }
                }
                printf("Scenario #%d:\n", T++);
                if(flag) puts("Suspicious bugs found!");
                else puts("No suspicious bugs found!");
                puts("");
        }


        return 0;
}


