#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 50010;
int st[maxn], et[maxn], ra[maxn];
int N, vst[maxn];

struct Cmp {
        bool operator() (int a, int b) {
                return et[a] > et[b];
        }
};
priority_queue<int, vector<int>, Cmp > pq;

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
        pq.push(ra[0]); vst[ra[0]] = 1;
        for(int i=1; i<N; i++) {
                int r = ra[i];
                int t = pq.top();
                if(et[t]>=st[r]) {
                        pq.push(r);
                        vst[r] = pq.size();
                } else {
                        vst[r] = vst[t];
                        pq.pop();
                        pq.push(r);
                }
        }
        printf("%d\n", pq.size());
        for(int i=0; i<N; i++)
                printf("%d\n", vst[i]);

        return 0;
}
