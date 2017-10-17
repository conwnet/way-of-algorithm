
/**
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
        srand((int)time(NULL));
        int N = rand()%100;
        int L = rand()%10000*2;
        int B = rand()%1000;
        int A = rand()%B;
        printf("%d %d\n%d %d\n", N, L, A, B);
        for(int i=0; i<N; i++) {
                int B = rand()%L/10;
                int A = rand()%B;
                printf("%d %d\n", A, B);
        }

        return 0;
}
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, L, A, B;
int cow[1000010];
int dp[1000010];
int minv[4000040];

void init() {
        for(int i=0; i<4000040; i++)
                minv[i] = 1<<30;
}

int change(int L, int R, int o, int pos, int x)
{
        int a = 1<<30; int b = 1<<30;
        if(L==R) return minv[o] = x;
        int M = (L+R)>>1;
        if(M<pos) a = change(M+1, R, o*2+1, pos, x);
        else b = change(L, M, o*2, pos, x);
        return minv[o] = min(a, b);
}

int query(int L, int R, int o, int l, int r)
{
        int a = 1<<30; int b = 1<<30;
        if(l<=L && r>=R) return minv[o];
        int M = (L+R)>>1;
        if(l<=M) a = query(L, M, o*2, l, r);
        if(r>M) b = query(M+1, R, o*2+1, l, r);
        return min(a, b);
}

int main()
{
        int s, e;
        scanf("%d%d%d%d", &N, &L, &A, &B);
        if(L&1) {
               // printf("-1\n");
              //  return 0;
        }
        init();
        memset(cow, 0, sizeof(cow));
        for(int i=0; i<N; i++) {
                scanf("%d%d", &s, &e);
                if(e-s==1) continue;
                cow[s+1] += 1;
                cow[e] -= 1;
        }
        for(int i=1; i<=L; i++) {
                cow[i] += cow[i-1];
        }
        for(int i=0; i<1000010; i++)
                dp[i] = 1<<30;
        for(int i = A*2; i<=B*2; i+=2) {
                if(!cow[i]) {
                        dp[i] = 1;
                        change(1, L, 1, i, dp[i]);
                }
        }
        for(int i=B*2+2; i<=L; i+=2) {
                if(!cow[i]) {
                        dp[i] = query(1, L, 1, i-2*B, i-2*A)+1;
                        change(1, L, 1, i, dp[i]);
                }
        }
        if(dp[L]<(1<<30)) printf("%d\n", dp[L]);
        else printf("-1\n");

        return 0;
}


/**<

2 8
1 2
6 7
3 6
        1 1
F F F F F F F F F
F F 1 F F F 2 F 3
0 1 2 3 4 5 6 7 8

        1
   1        I
 1   I    I   I


 */
