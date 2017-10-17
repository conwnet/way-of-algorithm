#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dat[128], next[128], prev[128], rank[128];

int cmp(int a, int b)
{
        return dat[a] > dat[b];
}

int cal(int s)
{
        int p = prev[s];
        int q = next[s];
        int ret = dat[s]*dat[p]*dat[q];
        prev[q] = p; next[p] = q;
        return ret;
}

int main()
{
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d", &dat[i]);
        for(int i=0; i<N; i++)
                rank[i] = i;
        sort(rank, rank+N, cmp);
        for(int i=0; i<N; i++) {
                next[i] = i+1;
                prev[i] = i-1;
        }
        int ans = 0;
        for(int i=0; i<N; i++) {
                int r = rank[i];
                if(r==0 || r==N-1) continue;
                ans += cal(r);
        }
        printf("%d\n", ans);

        return 0;
}
