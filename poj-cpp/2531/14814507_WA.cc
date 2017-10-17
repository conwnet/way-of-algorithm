#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int f[25][25], N, d[25], vst[25];

int prim()
{
        int ret = 0;
        int s = 1;
        for(int i=1; i<N; i++) {
                vst[s] = 1;
                int maxs = 0, maxf = 0;
                for(int j=1; j<=N; j++) {
                        if(vst[j]) continue;
                        if(f[s][j]>d[j])
                                d[j] = f[s][j];
                        if(d[j]>maxs) {
                                maxs = d[j];
                                maxf = j;
                        }
                }
                s = maxf;
                ret += maxs;
        }
        return ret;
}

int main()
{
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                for(int j=1; j<=N; j++) {
                        scanf("%d", &f[i][j]);
                }
        }
        printf("%d\n", prim());

        return 0;
}
