#include <stdio.h>

int p[160000];

int findp(int x)
{
        if(p[x]==x) return x;
        return p[x] = findp(p[x]);
}

int main()
{
        int N, n, op, x, y, cnt, i;

        scanf("%d%d", &N, &n);
        cnt = 0;
        for(i=0; i<=3*N; i++) {
                p[i] = i;
        }
        while(n--) {
                scanf("%d%d%d", &op, &x, &y);
                if(x>N || y>N) {
                        cnt++;
                        continue;
                }
                if(op==1) {
                        if(findp(x)==findp(y+N)) cnt++;
                        else if(findp(x)==findp(y+2*N)) cnt++;
                        else {
                                p[findp(x)] = findp(y);
                                p[findp(x+N)] = findp(y+N);
                                p[findp(x+2*N)] = findp(y+2*N);
                        }
                } else {
                        if(findp(x)==findp(y) || findp(x)==findp(y+2*N)) cnt++;
                        else {
                                p[findp(x)] = findp(y+N);
                                p[findp(x+N)] = findp(y+2*N);
                                p[findp(x+2*N)] = findp(y);
                        }
                }
        }
        printf("%d\n", cnt);

        return 0;
}
