#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Stk {
        int a, b;
        int r;
        bool operator < (const Stk& B) const {
                return b<B.b;
        }
};

Stk stk[6000], tmp[6000];
int vst[6000], N;

int cmp(Stk A, Stk B) {
        if(A.a!=B.a) return A.a < B.a;
        return A.b < B.b;
}

int main()
{
        int T, i, cnt, ans, k;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(i=0; i<N; i++) scanf("%d%d", &stk[i].a, &stk[i].b);
                sort(stk, stk+N, cmp);
                for(i=0; i<N; i++) stk[i].r = i;
                ans = cnt = 0;
                memset(vst, 0, sizeof(vst));
                while(cnt<N) {
                        for(i=0; i<=N; i++)
                                tmp[i].a = tmp[i].b = 99999;
                        for(i=0; i<N; i++) {
                                if(vst[i]) continue;
                                k = upper_bound(tmp, tmp+N, stk[i]) - tmp;
                                tmp[k] = stk[i];
                        }
                        for(i=0; tmp[i].a!=99999; i++) {
                                vst[tmp[i].r] = 1;
                                cnt++;
                        }
                        ans++;
                }
                printf("%d\n", ans);
        }

        return 0;
}
