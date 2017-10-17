#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct Cow {
        int c, w, id;
        bool operator < (const Cow& b) const {
                return c < b.w;
        }
}cow[21000];

int N, C, F, r[21000];

int cmp(int a, int b)
{
        return cow[a].w<cow[b].w;
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
        int mid = N/2;
        int scnt, bcnt, ssum, bsum, sok, bok;
        scnt = ssum = sok = 0;
        bcnt = bsum = bok = 0;
        int ans = -1;
        for(i=0; i<C; i++) {
                if(cow[i].id<mid || cow[i].id>=C-mid) continue;
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
                if(ssum+bsum+cow[i].c<=F) ans = max(ans, cow[i].w);
        }
        printf("%d\n", ans);

        return 0;
}
