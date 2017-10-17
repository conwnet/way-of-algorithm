#include <stdio.h>
#include <algorithm>

using namespace std;

pair<int, int> cow[60000];
int N, K, r[60000];

int cmp(int a, int b)
{
        return cow[a].first < cow[b].first;
}

int main()
{
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
                scanf("%d%d", &cow[i].first, &cow[i].second);
        for(int i=0; i<N; i++) r[i] = i;
        sort(r, r+N, cmp);
        int maxs = 0,  maxf = 0;
        for(int i=N-K; i<N; i++) {
                int t = r[i];
                if(cow[t].second > maxs) {
                        maxs = cow[t].second;
                        maxf = t;
                }
        }
        printf("%d\n", maxf+1);

        return 0;
}
