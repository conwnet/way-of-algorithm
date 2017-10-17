#include <stdio.h>
#include <string.h>

int cnt[1000], N;
int p[1000], vst[1000];

int main()
{
        int n, u, v;
        while(~scanf("%d", &N)) {
                memset(p, 0, sizeof(p));
                memset(cnt, 0, sizeof(cnt));
                for(int i=0; i<N; i++) {
                        scanf("%d:(%d)", &u, &n);
                        while(n--) {
                                scanf("%d", &v);
                                p[v] = u;
                        }
                }
                scanf("%d", &n);
                while(n--) {
                        while(getchar()!='(');
                        scanf("%d%d", &u, &v);
                        getchar();
                        memset(vst, 0, sizeof(vst));
                        while(u) {
                                vst[u] = 1;
                                u = p[u];
                        }
                        while(!vst[v]) {
                                v = p[v];
                        }
                        cnt[v]++;
                }
                for(int i=0; i<=N; i++)
                        if(cnt[i]) printf("%d:%d\n", i, cnt[i]);
        }

        return 0;
}
