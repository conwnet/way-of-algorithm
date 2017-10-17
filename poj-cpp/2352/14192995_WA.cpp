#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct STAR {
        int y, x;
}star[160000];

int N, M, bit[330000], ans[160000];

int sum(int pos)
{
        int s = 0;
        while(pos>0) {
                s += bit[pos];
                pos -= pos&-pos;
        }
        return s;
}

void add(int pos)
{
        while(pos<=M) {
                bit[pos]++;
                pos += pos&-pos;
        }
}

int cmp(STAR a, STAR b)
{
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
}

int main()
{
        int i;

        scanf("%d", &N);
        memset(bit, 0, sizeof(bit));
        memset(ans, 0, sizeof(ans));
        for(i=0; i<N; i++) scanf("%d%d", &star[i].x, &star[i].y);
        M = N;
        sort(star, star+N, cmp);
        for(i=0; i<N; i++) {
                ans[sum(star[i].y)]++;
                add(star[i].y);
        }
        for(i=0; i<N; i++) printf("%d\n", ans[i]);

        return 0;
}
