#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

double hei[1024], g[1024], h[1024];
int up[1024], down[1024];

int cmp(double a, double b)
{
        return a > b;
}

int main()
{
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%lf", &hei[i]);
        for(int i=0; i<N; i++) {
                g[i] = h[i] = 0x3f3f3f3f;
        }
        for(int i=0; i<N; i++) {
                int r = lower_bound(g, g+N, hei[i]) - g;
                int s = lower_bound(h, h+N, hei[N-1-i]) - h;
                g[r] = hei[i]; h[s] = hei[i];
                if(i>0) {
                        down[i] = max(down[i-1], s+1);
                        up[i] = max(up[i-1], r+1);
                } else {
                        down[i] = s+1;
                        up[i] = r+1;
                }
        }
        //for(int i=0; i<N; i++) printf("%d ", up[i]); printf("\n");
        //for(int i=0; i<N; i++) printf("%d ", down[i]); printf("\n");
        int ans = 0;
        for(int i=0; i<N; i++) {
                if(up[i]+down[N-i-1]-1 > ans) ans = up[i]+down[N-i-1]-1;
                if(i>0 && up[i]+down[N-i-2] > ans) ans = up[i]+down[N-i-2];
                //printf("%d\n", ans);
        }
        printf("%d\n", N-ans);

        return 0;
}

