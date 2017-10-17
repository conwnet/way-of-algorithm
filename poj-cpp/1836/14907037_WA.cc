#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

double hei[1024], g[1024];

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
        for(int i=0; i<N; i++)
                g[i] = 0;
        int ans = 0;
        for(int i=0; i<N-1; i++) {
                int r = lower_bound(g, g+N, hei[i], cmp) - g;
                g[r] = hei[i];
                if(r>ans) ans = r;
        }
        printf("%d\n", N-ans-2);

        return 0;
}
