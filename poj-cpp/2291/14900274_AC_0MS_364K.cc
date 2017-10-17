#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int rop[1024], N, T;

int main()
{
        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(int i=0; i<N; i++)
                        scanf("%d", &rop[i]);
                sort(rop, rop+N);
                int ans = 0;
                for(int i=0; i<N; i++)
                        ans = max(ans, rop[i]*(N-i));
                printf("%d\n", ans);
        }

        return 0;
}
