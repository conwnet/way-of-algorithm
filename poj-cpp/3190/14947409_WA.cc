#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 50010;
int st[maxn], et[maxn], ra[maxn];
int N, vst[50010];

int cmp(int a, int b)
{
        return st[a] < st[b];
}

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                scanf("%d%d", &st[i], &et[i]);
                ra[i] = i;
        }
        sort(ra, ra+N, cmp);
        int t, ans = 0;
        for(int i=0; i<N; i++) {
                if(vst[ra[i]]) continue;
                vst[ra[i]] = ++ans;
                st[N] = et[ra[i]];
                while(t=lower_bound(ra, ra+N, N, cmp)-ra) {
                        while(t<N && vst[ra[t]]) t++;
                        if(t==N) break;
                        vst[ra[t]] = ans;
                        st[N] = et[t];
                }
        }
        printf("%d\n", ans);
        for(int i=0; i<N; i++) printf("%d\n", vst[i]);

        return 0;
}
