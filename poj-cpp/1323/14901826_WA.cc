#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dat[55], M, N, vst[25*55], use[55], big[55];

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
                int p = N*M;
                for(int i=0; i<N; i++) {
                        while(vst[p]) p--;
                        vst[p] = 1;
                        big[i] = p;
                }
                for(int i=0; i<N; i++) {
                        int p = lower_bound(dat, dat+N, big[i]) - dat;
                        while(p>0 && use[p-1]) p--;
                        if(p>0) use[p-1] = 1;
                }
                int ans = 0;
                for(int i=0; i<N; i++)
                        if(!use[i]) ans++;
                printf("Case %d: %d\n", nC++, ans);
        }

        return 0;
}
