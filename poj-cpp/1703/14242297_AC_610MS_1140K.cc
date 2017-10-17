#include <stdio.h>

int p[210000];

int findp(int x)
{
        return x==p[x]?x:p[x]=findp(p[x]);
}

int main()
{
        int i, T, N, M, a, b;
        char cmd[5];

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &M);
                for(i=0; i<=N*2; i++) p[i] = i;
                while(M--) {
                        scanf("%s%d%d", cmd, &a, &b);
                        if(cmd[0]=='D') {
                                p[findp(a)] = findp(b+N);
                                p[findp(b)] = findp(a+N);
                        } else {
                                if(findp(a)==findp(b)) printf("In the same gang.\n");
                                else if(findp(a)==findp(b+N)) printf("In different gangs.\n");
                                else printf("Not sure yet.\n");
                        }
                }
        }

        return 0;
}

