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
                        if(findp[x]==findp[y] || findp[x]==findp[y+2*N]) cnt++;
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



/**
#include <stdio.h>
#include <string.h>

int boss[60000], same[60000];

int findr(int a){
    return same[a]==a ? a : same[a] = findr(same[a]);
}

int isSame(int a, int b){
    int x = boss[a], y = boss(b);
    if(x==0)
    if(findr(x)==findr(y)) return 1;
    else return 0;

}

int main(){
    int N, K, op, a, b, cnt=0, i;

    scanf("%d%d", &N, &K);
    memset(boss, 0, sizeof(boss));
    for(i=0; i<60000; i++) same[i] = i;
    while(K--){
        scanf("%d%d%d", &op, &a, &b);
        if(a>N || b>N) cnt++;
        if(op==1){
            int x = findr(a);
            int y = findr(b);

            if(isSame(x, y)) continue;
            else cnt++;

        }
        else{
            if(a==b) cnt++;
            int x = findr(a);
            int y = findr(b);

            if(boss[y]==x)
        }
    }

    return 0;
}
*/
