#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct ADT{
        int x;
        int y;
}star[15002];

int cmp(ADT a, ADT b)
{
        if(a.x!=b.x) {
                return a.x<b.x;
        } else {
                return a.y<b.y;
        }
}

int main()
{
        int N, i, j, cnt[15002], n;

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                scanf("%d%d", &star[i].x, &star[i].y);
        }
        sort(star, star+N, cmp);
        memset(cnt, 0, sizeof(cnt));
        for(i=0; i<N; i++) {
                n = 0;
                for(j=0; j<i; j++) {
                        if(star[j].y <= star[i].y) n++;
                }
                cnt[n]++;
        }
        for(i=0; i<N; i++) printf("%d\n", cnt[i]);

        return 0;
}
