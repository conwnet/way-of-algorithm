#include <stdio.h>

int N, K, arr[100010];

int judge(int m)
{
        int cnt = 0;
        for(int i=0; i<N; i++) {
                if(arr[i]-m <= 0)
                        continue;
                cnt += (arr[i]-m) / K;
                if((arr[i]-m)%K) cnt++;
        }
        return cnt <= m;
}

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d", &arr[i]);
        scanf("%d", &K);
        int l = 0, r = N;
        while(l<r) {
                int m = l+r >> 1;
                if(judge(m)) r = m;
                else l = m+1;
        }
        printf("%d\n", l);

        return 0;
}
