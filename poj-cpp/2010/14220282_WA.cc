
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Cow{
        int c, w, id;
        bool operator < (const Cow& b) const {
                return c<b.c;
        }
}cow[110000];

int N, C, F, r[110000];

int cmp(int a, int b)
{
        return cow[a].w<cow[b].w;
}
int judge(int n);

int main()
{
        int i, j;

        scanf("%d%d%d", &N, &C, &F);
        for(i=0; i<C; i++) scanf("%d%d", &cow[i].w, &cow[i].c);
        sort(cow, cow+C);
        for(i=0; i<C; i++) r[i] = i;
        sort(r, r+C, cmp);
        for(i=0; i<C; i++) cow[r[i]].id = i;
        int L = 0, R = C-1;
        //for(i=0; i<C; i++) printf("%d ", cow[r[i]].w);
        for(i=0; i<100; i++) {
                int mid = (R+L)>>1;
                int t = judge(r[mid]);
                if(t==0) {
                        printf("-1\n");
                        return 0;
                } else if(t==1) {
                        L = mid;
                } else if(t==2) {
                        R = mid;
                } else if(t==3) {
                        L = mid;
                }
        }
        printf("%d\n", cow[r[L]].w);


        return 0;
}

int judge(int n)
{
        int lcnt, rcnt, i, sum;

        lcnt = rcnt = sum = 0;
        for(i=0; i<C; i++) {
                if(cow[i].id<cow[n].id && sum+cow[n].c<=F) {
                        lcnt++;
                        sum += cow[i].c;
                } else if(cow[i].id>cow[n].id && sum+cow[n].c<=F) {
                        rcnt++;
                        sum += cow[i].c;
                }
        }
        if(lcnt<N/2 && rcnt<N/2 || rcnt+lcnt<N-1) return 0;
        if(lcnt<N/2) return 1;
        if(rcnt<N/2) return 2;
        return 3;
}

