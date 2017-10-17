#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct Cow {
        int c, w, id;
        bool operator < (const Cow& b) const {
                return c < b.w;
        }
}cow[110000];

int N, C, F, r[110000];
int ans = -1;

int cmp(int a, int b)
{
        return cow[a].w<cow[b].w;
}

int check(int i)
{
        int scnt, bcnt, ssum, bsum, sok, bok, j;
        int mid = N/2;
        scnt = ssum = sok = 0;
        bcnt = bsum = bok = 0;
        for(j=0; j<C; j++) {
                if(cow[j].id<cow[i].id && !sok) {
                        scnt += 1;
                        ssum += cow[i].c;
                        if(scnt==mid) sok = 1;
                } else if(cow[j].id>cow[i].id && !bok) {
                        bcnt += 1;
                        bsum += cow[i].c;
                        if(bcnt==mid) bok = 1;
                }
        }
        if(ssum+bsum+cow[i].c<=F) return 1;
        return -1;
}

int main()
{
        int i, j;
        priority_queue<int, vector<int>, greater<int> > pq;

        scanf("%d%d%d", &N, &C, &F);
        for(i=0; i<C; i++) {
                scanf("%d%d", &cow[i].w, &cow[i].c);
        }
        sort(cow, cow+C);
        for(i=0; i<C; i++) {
                r[i] = i;
        }
        sort(r, r+C, cmp);
        for(i=0; i<C; i++) {
                cow[r[i]].id = i;
        }
        int L = N/2; int R = C-N/2-1;
        while(R-L>1) {
                int mid = (L+R)/2;
                int t = check(r[mid]);
                if(t>0) R = mid;
                else if(t<0) L = mid;
        }

        printf("%d\n", cow[r[R]].w);

        return 0;
}
