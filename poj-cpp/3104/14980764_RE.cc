#include <stdio.h>

typedef long long ll;
int N, K, arr[100010];

int judge(ll m)
{
        ll cnt = 0;
        for(int i=0; i<N; i++) {
                if(arr[i]-m <= 0)
                        continue;
                cnt += (arr[i]-m) / (K-1);
                if((arr[i]-m)%(K-1)) cnt++;
        }
        return cnt <= m;
}

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d", &arr[i]);
        scanf("%d", &K);
        ll l = 0, r = (ll)1<<35;
        while(l<r) {
                ll m = l+r >> 1;
                if(judge(m)) r = m;
                else l = m+1;
        }
        printf("%lld\n", l);

        return 0;
}
