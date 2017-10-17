#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Dot {
        int x, y;
        double get_rake(Dot B) {
                if(x==B.x) return 99999;
                return (double)(B.y-y)/(B.x-x);
        }
}dot[705];

int N;
vector<double> rake[705];

int main()
{
        int i, j, ans, maxs;

        while(scanf("%d", &N) && N) {
                for(i=0; i<N; i++)
                        scanf("%d%d", &dot[i].x, &dot[i].y);
                for(i=0; i<N; i++) rake[i].clear();
                for(i=0; i<N; i++) {
                        for(j=i+1; j<N; j++) {
                                rake[i].push_back(dot[i].get_rake(dot[j]));
                        }
                }
                for(i=0; i<N; i++) {
                        sort(rake[i].begin(), rake[i].end());
                }
                ans = 2;
                for(i=0; i<N; i++) {
                        maxs = 2;
                        for(j=1; j<rake[i].size(); j++) {
                                if(fabs(rake[i][j]-rake[i][j-1])<1e-8) maxs++;
                                else {
                                        if(maxs>ans) ans = maxs;
                                        maxs = 2;
                                }
                        }
                        if(maxs>ans) ans = maxs;
                }
                printf("%d\n", ans);
        }

        return 0;
}
