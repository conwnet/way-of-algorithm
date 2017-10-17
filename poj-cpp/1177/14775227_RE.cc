#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 50050;
struct Edge {
        int x, y1, y2;
};
typedef pair<int, int> P;
int pos[maxn][4], N;
int mapx[maxn*2], xc = 0;
int mapy[maxn*2], yc = 0;
vector<vector<P> > Gx, Gy;

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                scanf("%d%d%d%d", &pos[i][0], &pos[i][1], &pos[i][2], &pos[i][3]);
                mapx[xc] = pos[i][0]; mapx[xc+1] = pos[i][2]; xc += 2;
                mapy[yc] = pos[i][1]; mapy[yc+1] = pos[i][3]; yc += 2;
        }
        sort(mapx, mapx+xc);
        sort(mapy, mapy+yc);
        xc = unique(mapx, mapx+xc) - mapx;
        yc = unique(mapy, mapy+xc) - mapy;
        Gx.resize(xc+10);
        Gy.resize(yc+10);
        for(int i=0; i<N; i++) {
                int p = lower_bound(mapx, mapx+xc, pos[i][0]) - mapx;
                for(; mapx[p]<pos[i][2]; p++) {
                        Gx[p].push_back(P(pos[i][1], 0));
                        Gx[p].push_back(P(pos[i][3], 1));
                }
        }
        for(int i=0; i<N; i++) {
                int p = lower_bound(mapy, mapy+yc, pos[i][1]) - mapy;
                for(; mapy[p]<pos[i][3]; p++) {
                        Gy[p].push_back(P(pos[i][0], 0));
                        Gy[p].push_back(P(pos[i][2], 1));
                }
        }
        int ans = 0;
        for(int i=0; i<xc; i++) {
                sort(Gx[i].begin(), Gx[i].end());
                int cnt = 0;
                for(int j=0; j<Gx[i].size(); j++) {
                        if(cnt==0 && Gx[i][j].second==0) ans += mapx[i+1]-mapx[i];
                        if(Gx[i][j].second==0) cnt++;
                        else cnt--;
                        if(cnt==0 && Gx[i][j].second==1) ans += mapx[i+1]-mapx[i];
                }
        }
        for(int i=0; i<yc; i++) {
                sort(Gy[i].begin(), Gy[i].end());
                int cnt = 0;
                for(int j=0; j<Gy[i].size(); j++) {
                        if(cnt==0 && Gy[i][j].second==0) ans += mapy[i+1]-mapy[i];
                        if(Gy[i][j].second==0) cnt++;
                        else cnt--;
                        if(cnt==0 && Gy[i][j].second==1) ans += mapy[i+1]-mapy[i];
                }
        }
        printf("%d\n", ans);

        return 0;
}
