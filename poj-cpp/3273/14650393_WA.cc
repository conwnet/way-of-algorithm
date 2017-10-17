#include <stdio.h>
#include <string.h>

const int maxn = 100005;

int sum[maxn], arr[maxn];
int N, M;

int is_ok(int n)
{
        int s = sum[n];
        int tmp = 0, cnt = 0;
        for(int i=1; i<=N; i++) {
                tmp += arr[i];
                if(tmp>s) {
                        cnt++;
                        tmp = arr[i];
                }
        }
        return cnt < M;
}

int main()
{
        int t;
        sum[0] = 0;
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++) {
                scanf("%d", &arr[i]);
                sum[i] = sum[i-1]+arr[i];
        }
        int l = 1;
        int r = N;
        while(l<r) {
                int m = (l+r)>>1;
                if(is_ok(m)) r = m;
                else l = m+1;
        }
        printf("%d\n", sum[l]);

        return 0;
}
