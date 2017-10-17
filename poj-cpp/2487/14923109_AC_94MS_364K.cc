#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dat[1024], N, M;

int main()
{
        int T;

        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                scanf("%d%d", &N, &M);
                for(int i=0; i<M; i++)
                        scanf("%d", &dat[i]);
                sort(dat, dat+M);
                int ans = 0;
                for(int i=M-1; i>=0 && N>0; i--) {
                        ans++; N -= dat[i];
                }
                printf("Scenario #%d:\n", nC);
                if(N>0) printf("impossible\n");
                else printf("%d\n", ans);
                printf("\n");
        }

        return 0;
}
