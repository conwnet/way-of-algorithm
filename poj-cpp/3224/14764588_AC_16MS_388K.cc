#include <stdio.h>

int cnt[101];

int main()
{
        int n, a;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                        scanf("%d", &a);
                        if(a==3) cnt[i]++;
                }
        }
        int ans = 0, maxs = cnt[0];
        for(int i=0; i<n; i++) {
                if(cnt[i]>maxs) {
                        maxs = cnt[i];
                        ans = i;
                }
        }
        printf("%d\n", ans+1);

        return 0;
}