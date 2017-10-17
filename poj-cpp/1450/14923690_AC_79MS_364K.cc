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
                double ans = N*M;
                if(N*M&1) ans += 0.41;
                printf("Scenario #%d:\n%.2f\n\n", nC, ans);
        }

        return 0;
}
