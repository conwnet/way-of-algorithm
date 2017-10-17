#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M;

int main()
{
        int T;
        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                scanf("%d%d", &N, &M);
                double ans = 0;
                if(0==N%2 || 0==M%2) ans = N*M;
                else {
                        int n = N<M ? N : M;
                        n -= 2;
                        ans = N*M - n + n*sqrt(2);
                }
                printf("Scenario #%d:\n%.2f\n\n", nC, ans);
        }

        return 0;
}
