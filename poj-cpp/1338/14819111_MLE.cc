#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
int arr[2][maxn], ans[maxn], lc, rc, l, r, n;

int main()
{
        arr[0][0] = 3; arr[1][0] = 4;
        ans[0] = 1; int cnt = 1;
        lc = rc = 1; l = r = 0;
        while(cnt<maxn) {
                int n = arr[0][l]<arr[1][r] ? arr[0][l++] : arr[1][r++];
                if(ans[cnt-1]==n) continue;
                ans[cnt++] = n;
                arr[0][lc++] = n*2+1;
                arr[1][rc++] = n*3+1;
        }
        while(~scanf("%d", &n)) {
                printf("%d\n", ans[n-1]);
        }

        return 0;
}
