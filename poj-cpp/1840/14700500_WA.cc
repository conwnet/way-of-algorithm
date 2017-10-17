#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int x5arr[105];

int is_ok(int n)
{
        int l = 0;
        int r = 99;
        while(l<r) {
                int m = (l+r) >> 1;
                if(n+x5arr[m] < 0) l = m+1;
                else r = m;
        }
        return n+x5arr[l] == 0;
}

int main()
{
        int a, b, c, d, e, ans;

        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        int cnt = 0;
        for(int i=-50; i<=50; i++)
                if(i!=0)
                x5arr[cnt++] = e*i*i*i;
        sort(x5arr, x5arr+cnt);
        ans = 0;
        for(int i=-50; i<=50; i++) {
                if(i!=0)
                for(int j=-50; j<=50; j++) {
                        if(j!=0)
                        for(int k=-50; k<=50; k++) {
                                if(k!=0)
                                for(int l=-50; l<=50; l++) {
                                        if(l!=0)
                                        if(int t = is_ok(i*i*i*a + j*j*j*b + k*k*k*c + l*l*l*d)) {
                                                ans++;
                                        }
                                        ///printf("%d %d %d %d\n", i, j, k, l);
                                }
                        }
                }
        }
        printf("%d\n", ans);

        return 0;
}
