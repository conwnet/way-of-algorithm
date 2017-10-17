#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[30];
int N, r[30], color[30];

int cmp(int a, int b)
{
        return G[a].size() > G[b].size();
}

int main()
{
        char mstr[30];
        int vst[30];
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++)
                        G[i].clear();
                for(int i=0; i<N; i++) {
                        scanf("%s", mstr);
                        for(int j=2; mstr[j]; j++)
                                G[i].push_back(mstr[j]-'A');
                }
                for(int i=0; i<30; i++) r[i] = i;
                sort(r, r+N, cmp);
                int cnt = 0;
                memset(color, 0, sizeof(color));
                for(int i=0; i<N; i++) {
                        int t = r[i];
                        if(color[t]) continue;
                        color[t] = ++cnt;
                        memset(vst, 0, sizeof(vst));
                        for(int j=0; j<G[t].size(); j++)
                                vst[G[t][j]] = 1;
                        for(int j=0; j<N; j++)
                                if(!vst[j] && !color[j])
                                        color[j] = cnt;
                }
                printf("%d %s needed.\n", cnt, cnt==1?"channel":"channels");
        }

        return 0;
}

