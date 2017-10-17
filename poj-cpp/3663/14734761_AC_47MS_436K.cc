#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int len[20005];
int N, S;

int main()
{
        scanf("%d%d", &N, &S);
        for(int i=0; i<N; i++)
                scanf("%d", &len[i]);
        sort(len, len+N);
        int sum = 0;
        for(int i=0; i<N; i++) {
                int t = upper_bound(len+i+1, len+N, S-len[i]) - len - i - 1;
                sum += t;
        }
        printf("%d\n", sum);

        return 0;
}
