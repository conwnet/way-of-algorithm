
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
#include <queue>
#include <algorithm>

using namespace std;

int N, L, A, B;
int cow[1000010];
int dp[1000010];
int minv[4000040];

typedef pair<int, int> P;

priority_queue<P, vector<P>, greater<P> > pq;

void init() {
        for(int i=0; i<=L*4; i++)
                minv[i] = 1<<30;
}

int change(int L, int R, int o, int pos, int x)
{
        //printf("----%d %d %d\n", o, pos, R);

        if(L==R) return minv[o] = x;
        if(L>pos || R<pos) return minv[o];
        int M = (L+R)>>1;
        int a = change(L, M, o*2, pos, x);
        int b = change(M+1, R, o*2+1, pos, x);
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
        init();
        memset(cow, 0, sizeof(cow));
        for(int i=0; i<N; i++) {
                scanf("%d%d", &s, &e);
                cow[s+1] += 1;
                cow[e] -= 1;
        }
        if(L&1) {
                printf("-1\n");
                return 0;
        }
        for(int i=1; i<=L; i++) {
                cow[i] += cow[i-1];
        }
        for(int i=0; i<1000010; i++)
                dp[i] = 1<<30;
        dp[0] = 1;
        for(int i = A*2; i<=B*2; i+=2) {
                if(!cow[i]) {
                        dp[i] = 1;
                }
                pq.push(P(dp[i-A*2], i-A*2));
        }
     //   for(int i=1; i<=L*2; i++) printf("%2d  %d \n", i,minv[i]); printf("\n");
        for(int i=B*2+2; i<=L; i+=2) {
                pq.push(P(dp[i-A*2], i-A*2));
                if(!cow[i]) {
                        //printf("%d ", query(1, L, 1, i-2*B, i-2*A)); printf("\n");
                        //if(i==L) printf("%d-----\n", query(1, L, 1, i-2*B, i-2*A));
                        P top;
                        while(!pq.empty()) {
                                top = pq.top();
                                if(top.second<i-B*2);
                                else break;
                                pq.pop();
                        }
                        //printf("%d %d\n", top.first, top.second);
                        dp[i] = top.first + 1;
                      //  printf("%2d %d\n", i, dp[i]);
                }

        }
     //   for(int i=1; i<=L*2; i++) printf("%d ", minv[i]); printf("\n");
    // for(int i=1; i<=L*2; i++) printf("%2d  %d \n", i,minv[i]); printf("\n");
        if(dp[L]<(1<<30)) printf("%d\n", dp[L]);
        else printf("-1\n");

        return 0;
}


/**<

1 f 1 f 1 f


2 8
1 2
6 7
3 6
        1 1
F F F F F F F F F
1 F 1 F F F 2 F 3
0 1 2 3 4 5 6 7 8

1 0
1 2


        1
   1        I
 1   I    I   I




 */
