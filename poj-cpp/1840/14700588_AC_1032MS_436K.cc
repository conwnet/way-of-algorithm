#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int x5arr[105], x4arr[105], arr[10005], cnt;

int is_ok(int n)
{
        int l = 0;
        int r = cnt-1;
        while(l<r) {
                int m = (l+r) >> 1;
                if(n+arr[m] < 0) l = m+1;
                else r = m;
        }
        int ret = 0;
        if(n+arr[l]==0) {
                for(int i=l; arr[i]==arr[l]; i++)
                        ret++;
        }
        return ret;
}

int main()
{
        int a, b, c, d, e;
        long long ans;

        while(~scanf("%d%d%d%d%d", &a, &b, &c, &d, &e)) {
        int c4 = 0;
        for(int i=-50; i<=50; i++)
                if(i) x4arr[c4++] = d*i*i*i;
        int c5 = 0;
        for(int i=-50; i<=50; i++)
                if(i) x5arr[c5++] = e*i*i*i;
        cnt = 0;
        for(int i=0; i<c4; i++)
                for(int j=0; j<c5; j++)
                        arr[cnt++] = x4arr[i]+x5arr[j];
        sort(arr, arr+cnt);
        ans = 0;
        for(int i=-50; i<=50; i++) {
                if(!i) continue;
                for(int j=-50; j<=50; j++) {
                        if(!j) continue;
                        for(int k=-50; k<=50; k++) {
                                if(!k) continue;
                                ans += is_ok(i*i*i*a + j*j*j*b + k*k*k*c);
                        }
                }
        }
        printf("%lld\n", ans);
        }

        return 0;
}
