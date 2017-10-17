#include <stdio.h>
#include <algorithm>

using namespace std;

struct Coin {
        int v;
        int b;
        bool operator < (const Coin& oth) const {
                return v<oth.v;
        }
}coin[30];

int N, C;

int main()
{
        int i, j, ans;

        scanf("%d%d", &N, &C);
        for(i=0; i<N; i++) scanf("%d%d", &coin[i].v, &coin[i].b);
        sort(coin, coin+N);
        ans = 0;
        for(i=N-1; i>=0; i--) {
                while(coin[i].b>0) {
                        int tv = C-coin[i].v;
                        if(tv<=0) {
                                ans += coin[i].b;
                                coin[i].b = 0;
                                continue;
                        }
                        for(j=0; j<N; j++) {
                                if(coin[j].b>0 && coin[j].v>=tv) break;
                        }
                        if(j==i) {
                                ans += coin[i].b/2;
                                coin[i].b -= coin[i].b/2*2;
                                break;
                        }
                        if(j!=N) {
                                int tn = min(coin[j].b, coin[i].b);
                                ans += tn;
                                coin[j].b -= tn;
                                coin[i].b -= tn;
                        } else break;
                }
        }
        printf("%d\n", ans);

        return 0;
}






