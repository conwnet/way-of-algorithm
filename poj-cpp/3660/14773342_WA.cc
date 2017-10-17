#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M, deg[128], _deg[128], tmp[128];
vector<int> G[128];
int top[128], cnt;

int main()
{
        int u, v;
        scanf("%d%d", &N, &M);
        while(M--) {
                scanf("%d%d", &u, &v);
                G[u].push_back(v);
                _deg[u]++;
                deg[v]++;
        }
        cnt = 0;
        memcpy(tmp, deg, sizeof(deg));
        while(1) {
                int i;
                for(i=1; i<=N; i++)
                        if(!tmp[i]) break;
                if(i>N) break;
                tmp[i]--;
                top[cnt++] = i;
                for(int j=0; j<G[i].size(); j++)
                        tmp[G[i][j]]--;
        }
        int ok = 1;
        int ans = 0, t = 0;
        for(int i=1; i<=N; i++) {
                if(ok) t++;
                if(ok && (_deg[i]>1 || i==N)) {
                        ans += t;
                        ok = 0;
                }
               if(deg[i]>1) {t = 0; ok = 1;}
        }
        printf("%d\n", ans);

        return 0;
}
