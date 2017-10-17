#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 1024;
const int Mod = 100007;

int dx[maxn], dy[maxn], next[maxn];
int fir[Mod], N;

int is_in(int x, int y)
{
        int hs = abs(x*y) % Mod;
        for(int i=fir[hs]; i!=-1; i=next[i])
                if(dx[i]==x && dy[i]==y)
                        return 1;
        return 0;
}

int judge(int a, int b)
{
        int x1, y1, x2, y2, ret = 0;
        x1 = dx[a] - (dy[b] - dy[a]);
        y1 = dy[a] + (dx[b] - dx[a]);
        x2 = dx[b] + (dy[a] - dy[b]);
        y2 = dy[b] - (dx[a] - dx[b]);
        if(is_in(x1, y1) && is_in(x2, y2))
                ret++;
        x1 = dx[a] + (dy[b] - dy[a]);
        y1 = dy[a] - (dx[b] - dx[a]);
        x2 = dx[b] - (dy[a] - dy[b]);
        y2 = dy[b] + (dx[a] - dx[b]);
        if(is_in(x1, y1) && is_in(x2, y2))
                ret++;
        return ret;
}

int main()
{
        while(scanf("%d", &N) && N) {
                memset(fir, -1, sizeof(fir));
                for(int i=0; i<N; i++) {
                        scanf("%d%d", &dx[i], &dy[i]);
                        int hs = abs(dx[i] * dy[i]) % Mod;
                        next[i] = fir[hs];
                        fir[hs] = i;
                }
                int ans = 0;
                for(int i=0; i<N; i++) {
                        for(int j=i+1; j<N; j++) {
                                ans += judge(i, j);
                        }
                }
                printf("%d\n", ans/4);
        }

        return 0;
}
