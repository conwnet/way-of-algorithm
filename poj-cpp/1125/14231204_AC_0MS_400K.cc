#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[110][110], N;

void init()
{
        for(int i=0; i<110; i++)
                for(int j=0; j<110; j++)
                        arr[i][j] = 999999;
}

int main()
{
        int n, i, j, k, to, time;

        while(scanf("%d", &N)&&N) {
                init();
                for(i=1; i<=N; i++) {
                        scanf("%d", &n);
                        while(n--) {
                                scanf("%d%d", &to, &time);
                                arr[i][to] = time;
                        }
                }
                for(k=1; k<=N; k++)
                        for(i=0; i<=N; i++)
                                for(j=0; j<=N; j++)
                                        arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
                int ansi, ans = 999999;
                for(i=1; i<=N; i++) {
                        int t = 0;
                        for(j=1; j<=N; j++) {
                                if(i!=j) {
                                        t = max(t, arr[i][j]);
                                }
                        }
                        if(t<ans) {
                                ansi = i;
                                ans = t;
                        }
                }
                if(ans<999999) printf("%d %d\n", ansi, ans);
                else printf("disjoint\n");
        }

        return 0;
}



