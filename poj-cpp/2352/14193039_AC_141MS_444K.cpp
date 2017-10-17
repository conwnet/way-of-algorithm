#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct STAR {
        int y, x;
}star[16000];

int N, M, bit[33000], ans[16000];

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

int main()
{
        int i;

        scanf("%d", &N);
        memset(bit, 0, sizeof(bit));
        memset(ans, 0, sizeof(ans));
        for(i=0; i<N; i++) scanf("%d%d", &star[i].x, &star[i].y);
        M = 33000;
        for(i=0; i<N; i++) {
                ans[sum(star[i].x+1)]++;
           ///     for(int j=0; j<N; j++) printf("%d ", ans[j]);
                printf("");
                add(star[i].x+1);
        }
        for(i=0; i<N; i++) printf("%d\n", ans[i]);

        return 0;
}
