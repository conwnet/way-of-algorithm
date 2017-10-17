#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dat[55], M, N, vst[25*55], use[25*55];

int main()
{
        int nC = 1;
        while(scanf("%d%d", &M, &N)) {
                if(!M && !N) break;
                memset(vst, 0, sizeof(vst));
                for(int i=0; i<N; i++) {
                        scanf("%d", &dat[i]);
                        vst[dat[i]] = 1;
                }
                sort(dat, dat+N);
                memset(use, 0, sizeof(use));
                int p = 1;
                for(int i=0; i<N; i++)
                        printf("%d ", dat[i]);
                printf("\n");
                for(int i=1; i<M; i++) {
                        for(int j=0; j<N; j++) {
                                while(vst[p]) p++;
                                vst[p] = 1;
                                int q = lower_bound(dat, dat+N, p)-dat;
                                while(q>0 && use[q-1]) q--;
                                use[q-1] = 1;
                        }
                }
                int ans = 0;
                for(int i=0; i<N; i++) if(!use[i]) ans++;
                printf("Case %d: %d\n", nC++, ans);
        }

        return 0;
}
