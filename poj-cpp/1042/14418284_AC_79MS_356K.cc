#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, H, Hi, ti[30], f[30], fi[30], di[30], tc[30], ftc[30];

int main()
{
        while(scanf("%d", &N) && N) {
		scanf("%d", &Hi);
                for(int i=1; i<=N; i++)
                        scanf("%d", &f[i]);
                for(int i=1; i<=N; i++)
                        scanf("%d", &di[i]);
                for(int i=1; i<N; i++)
                        scanf("%d", &ti[i]);
                Hi *= 60;
                int ans = 0;
		memset(ftc, 0, sizeof(ftc));
		ftc[1] = Hi;
                for(int x=1; x<=N; x++) {
                        int nt = 0;
                        for(int i=1; i<x; i++)
                                nt += ti[i];
                        H = Hi;
                        H -= nt*5;
                        memset(tc, 0, sizeof(tc));
                        memcpy(fi, f, sizeof(fi));
                        int tmp = 0;
                        while(H>0) {
                                int maxs = fi[1], mf = 1;
                                for(int i=2; i<=x; i++) {
                                        if(fi[i]>maxs) {
                                                maxs = fi[i];
                                                mf = i;
                                        }
                                }
                               // printf("-------------------%d\n", maxs);
                                tmp += fi[mf];
                                fi[mf] -= min(fi[mf], di[mf]);
                                tc[mf] += 5;
                                H -= 5;
                        }
                        //puts("test");
                        if(tmp>ans) {
                                ans = tmp;
                                memcpy(ftc, tc, sizeof(tc));
                        }
                }
                for(int i=1; i<N; i++)
                        printf("%d, ", ftc[i]);
                printf("%d\n", ftc[N]);
                printf("Number of fish expected: %d\n\n", ans);
        }

        return 0;
}





