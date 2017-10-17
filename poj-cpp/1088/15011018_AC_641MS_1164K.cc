#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int maps[128][128], ind[11000], vst[11000], N, M;
vector<int> G[11000];

int top_sort()
{
        queue<int> que;
        int ret = 0;
        for(int u=0; u<N*M; u++) {
                if(!vst[u] && !ind[u]) {
                        que.push(u);
                }
        }
        while(!que.empty()) {
                int u = que.front(); que.pop();
                for(int i=0; i<G[u].size(); i++)
                        ind[G[u][i]]--;
                vst[u] = 1;
                ret = 1;
        }
        return ret;
}

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                        scanf("%d", &maps[i][j]);
        for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                        if(i>0 && maps[i-1][j]<maps[i][j]) {
                                G[i*M+j].push_back((i-1)*M+j);
                                ind[(i-1)*M+j]++;
                        }
                        if(i+1<N && maps[i+1][j]<maps[i][j]) {
                                G[i*M+j].push_back((i+1)*M+j);
                                ind[(i+1)*M+j]++;
                        }
                        if(j>0 && maps[i][j-1]<maps[i][j]) {
                                G[i*M+j].push_back(i*M+j-1);
                                ind[i*M+j-1]++;
                        }
                        if(j+1<M && maps[i][j+1]<maps[i][j]) {
                                G[i*M+j].push_back(i*M+j+1);
                                ind[i*M+j+1]++;
                        }
                }
        }
        int ans = 0;
        memset(vst, 0, sizeof(vst));
        while(top_sort()) ans++;
        printf("%d\n", ans);

        return 0;
}
