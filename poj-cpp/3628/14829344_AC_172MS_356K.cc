#include <stdio.h>

int main()
{
        int N, B, cow[20];
        scanf("%d%d", &N, &B);
        for(int i=0; i<N; i++)
                scanf("%d", &cow[i]);
        int ans = 0x3f3f3f3f;
        for(int i=0; i<1<<N; i++) {
                int sum = 0;
                for(int j=0; j<N; j++) {
                        if(i & 1<<j) sum += cow[j];
                }
                if(sum>=B && sum-B<ans) ans = sum-B;
        }
        printf("%d\n", ans);

        return 0;
}
