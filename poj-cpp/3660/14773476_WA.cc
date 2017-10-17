#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M, deg[128], _deg[128];
vector<int> G[128], _G[128];
int cnt[128], _cnt[128], cc;

int main()
{
        int u, v;
        scanf("%d%d", &N, &M);
        while(M--) {
                scanf("%d%d", &u, &v);
                G[u].push_back(v);
                deg[v]++;
                _G[v].push_back(u);
                _deg[u]++;
        }
        cc = 0;
        while(1) {
                int i;
                for(i=1; i<=N; i++)
                        if(!deg[i]) break;
                if(i>N) break;
                deg[i]--;
                cnt[i] = cc++;
                for(int j=0; j<G[i].size(); j++)
                        deg[G[i][j]]--;
        }
        cc = 0;
        while(1) {
                int i;
                for(i=1; i<=N; i++)
                        if(!_deg[i]) break;
                if(i>N) break;
                _deg[i]--;
                _cnt[i] = cc++;
                for(int j=0; j<_G[i].size(); j++)
                        _deg[_G[i][j]]--;
        }
        int ans = 0;
        for(int i=1; i<=N; i++)
                if(cnt[i]+_cnt[i]==N-1) ans++;

        printf("%d\n", ans);

        return 0;
}

