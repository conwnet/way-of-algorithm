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
                g[i] = 0;
                h[i] = 0x3f3f3f3f;
        }
        for(int i=0; i<N-1; i++) {
                int r = lower_bound(g, g+N, hei[i], cmp) - g;
                int s = lower_bound(h, h+N, hei[i]) - h;
                g[r] = hei[i]; h[s] = hei[i];
                down[i] = r; up[i] = s;
        }
        int ans = 0;
        for(int i=0; i<N; i++)
                if(up[i]+down[i] > ans) ans = up[i]+down[i];
        printf("%d\n", N-ans-1);

        return 0;
}
