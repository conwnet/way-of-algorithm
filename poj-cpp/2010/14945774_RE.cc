#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 20010;
const int INF = 0x3f3f3f3f;
int ra[maxn], score[maxn], aid[maxn];
int larr[maxn], rarr[maxn], N, C, F;

int cmp(int a, int b)
{
        return score[a] > score[b];
}

int main()
{
        scanf("%d%d%d", &N, &C, &F);
        for(int i=0; i<C; i++)
                scanf("%d%d", &score[i], &aid[i]);
        for(int i=0; i<C; i++) ra[i] = i;
        sort(ra, ra+C, cmp);
        priority_queue<int> pq;
        int l, r, m, tmp;
        l = r = 0; m = N>>1; tmp = 0;
        for(int i=0; i<C; i++) {
                int c = ra[i];
                if(l<m) { pq.push(aid[c]); larr[c] = INF; l++; continue; }
                int t = pq.top(); pq.pop(); pq.push(aid[c]);
                tmp = tmp - t + aid[c];
                larr[c] = tmp;
        }
        while(!pq.empty()) pq.pop();
        for(int i=C-1; i>=0; i--) {
                int c = ra[i];
                if(r<m) { pq.push(aid[c]); rarr[c] = INF; r++; continue; }
                int t = pq.top(); pq.pop(); pq.push(aid[c]);
                tmp = tmp - t + aid[c];
                rarr[c] = tmp;
        }
        int ans = -1;
        for(int i=0; i<C; i++) {
                int c = ra[i];
                if(larr[c]+rarr[c]-aid[c]<=F) {
                        ans = score[c];
                        break;
                }
        }
        printf("%d\n", ans);

        return 0;
}
