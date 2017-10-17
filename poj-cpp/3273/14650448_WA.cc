#include <stdio.h>
#include <string.h>

const int maxn = 100005;
typedef long long ll;
int arr[maxn];
int N, M;

int is_ok(int n)
{
        int s = 0;
        for(int i=1; i<=n; i++)
                s += arr[i];
        int tmp = 0;
        int cnt = 0;
        for(int i=1; i<=N; i++) {
                tmp += arr[i];
                if(tmp>s) {
                        cnt++;
                        tmp = arr[i];
                }
        }
        if(tmp>s) cnt++;
        return cnt < M;
}

int main()
{
        int t;
        while(~scanf("%d%d", &N, &M)){
        for(int i=1; i<=N; i++) {
                scanf("%d", &arr[i]);
        }
        int l = 1;
        int r = N;
        while(l<r) {
                int m = (l+r)>>1;
                if(is_ok(m)) r = m;
                else l = m+1;
        }
        int s = 0;
        for(int i=1; i<=l; i++)
                s += arr[i];
        printf("%d\n", s);
        }

        return 0;
}
