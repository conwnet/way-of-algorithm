#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

double hei[1024], g[1024];

int main()
{
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%lf", &hei[i]);
        for(int i=0; i<N; i++)
                g[i] = 0x3f3f3f3f;
        int ans = 0;
        for(int i=0; i<N; i++) {
                int r = lower_bound(g, g+N, hei[i]) - g;
                g[r] = hei[i];
                if(r>ans) ans = r;
        }
        printf("%d\n", N-ans-1);

        return 0;
}
