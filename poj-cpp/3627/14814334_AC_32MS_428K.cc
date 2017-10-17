#include <stdio.h>
#include <algorithm>

using namespace std;

int cow[20005];

int cmp(int a, int b)
{
        return a > b;
}

int main()
{
        int N, B;

        scanf("%d%d", &N, &B);
        for(int i=0; i<N; i++)
                scanf("%d", &cow[i]);
        sort(cow, cow+N, cmp);
        for(int i=1; i<N; i++)
                cow[i] += cow[i-1];
        int ans = lower_bound(cow, cow+N, B) - cow;
        printf("%d\n", ans+1);

        return 0;
}
