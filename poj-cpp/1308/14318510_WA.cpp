
#include <stdio.h>
#include <string.h>

int p[10000], f[10000];

int findp(int x)
{
        return x==p[x]?x:p[x]=findp(p[x]);
}

int main()
{
        int a, b, faild, cnt, nCase=0;

        faild = cnt = 0;
        memset(f, 0, sizeof(f));
        for(int i=0; i<10000; i++) p[i] = i;
        while(scanf("%d%d", &a, &b)) {
                if(a==0 && b==0) {
                        for(int i=0; i<10000; i++) if(f[i] && p[i]==i) cnt++;
                        //if(cnt>1) faild = 1;
                        if(faild) printf("Case %d is not a tree.\n", ++nCase);
                        else printf("Case %d is a tree.\n", ++nCase);
                        faild = cnt = 0;
                        memset(f, 0, sizeof(f));
                        for(int i=0; i<10000; i++) p[i] = i;
                        continue;
                }
                if(a==-1 && b==-1) break;
                f[a] = f[b] = 1;
                if(!faild) {
                        int x = findp(a);
                        int y = findp(b);
                        if(x!=y) p[y] = x;
                        else faild = 1;
                }
        }

        return 0;
}
