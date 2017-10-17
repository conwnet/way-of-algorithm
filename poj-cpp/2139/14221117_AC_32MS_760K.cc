#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M, maps[310][310], cow[310], ans;

int main()
{
        int i, j, k, t;

        for(i=0; i<310*310; i++) maps[0][i] = 9999999;
        scanf("%d%d", &N, &M);
        while(M--) {
                scanf("%d", &t);
                for(i=0; i<t; i++) scanf("%d", &cow[i]);
                for(i=0; i<t; i++) {
                        for(j=0; j<t; j++) {
                                if(i!=j) maps[cow[i]][cow[j]] = 1;
                               // else maps[cow[i]][cow[j]] = 0;
                        }
                }
        }

        for(k=1; k<=N; k++) {
                for(i=1; i<=N; i++) {
                        for(j=1; j<=N; j++) {
                                maps[i][j] = min(maps[i][j], maps[i][k]+maps[k][j]);
                        }
                }
        }
        ///for(i=1; i<=N; i++) { for(j=1; j<=N; j++) printf("%d ", maps[i][j]); puts("");}
        for(i=1; i<=N; i++) {
                cow[i] = 0;
                for(j=1; j<=N; j++) {
                                if(j!=i) cow[i] += maps[i][j];
                }
                cow[i] = cow[i]*100/(N-1);
        }
        ans = cow[1];
        for(i=2; i<=N; i++) ans = min(ans, cow[i]);
        printf("%d\n", ans);

        return 0;
}



