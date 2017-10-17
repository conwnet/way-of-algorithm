#include <stdio.h>
#include <algorithm>

using namespace std;

int buy[20010], N;

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(int i=0; i<N; i++)
                        scanf("%d", &buy[i]);
                sort(buy, buy+N);
                int ans = 0;
                for(int i=N-3; i>=0; i-=3) {
                        ans += buy[i];
                }
                printf("%d\n", ans);
        }

        return 0;
}
