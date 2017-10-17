#include <stdio.h>

int p[10000];

int findp(int x)
{
        return x==p[x]?x:p[x]=findp(p[x]);
}

int main()
{
        int a, b, faild, nCase=0;

        faild = 0;
        for(int i=0; i<10000; i++) p[i] = i;
        while(scanf("%d%d", &a, &b)) {
                if(a==0 && b==0) {
                        if(faild) printf("Case %d is not a tree\n", ++nCase);
                        else printf("Case %d is a tree\n", ++nCase);
                        faild=0;
                        for(int i=0; i<10000; i++) p[i] = i;
                        continue;
                }
                if(a==-1 && b==-1) break;
                if(!faild) {
                        int x = findp(a);
                        int y = findp(b);
                        if(x!=y) p[x] = y;
                        else faild = 1;
                }
        }

        return 0;
}
