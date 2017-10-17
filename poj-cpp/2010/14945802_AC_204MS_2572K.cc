#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 100010;
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
        l = 0; m = N/2+1; tmp = 0;
        for(int i=0; i<C; i++) {
                int c = ra[i];
                tmp += aid[c];
                if(i<m-1) { larr[c] = INF; pq.push(aid[c]); continue; }
                if(i==m-1) { larr[c] = tmp; pq.push(aid[c]); continue; }
                int t = pq.top(); pq.pop(); pq.push(aid[c]);
                tmp -= t; larr[c] = tmp;

        }
        while(!pq.empty()) pq.pop();
        r = 0; tmp = 0;
        for(int i=C-1; i>=0; i--) {
                int c = ra[i];
                tmp += aid[c];
                if(C-i<m) { rarr[c] = INF; pq.push(aid[c]); continue; }
                if(C-i==m) { rarr[c] = tmp; pq.push(aid[c]); continue; }
                int t = pq.top(); pq.pop(); pq.push(aid[c]);
                tmp -= t; rarr[c] = tmp;
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
