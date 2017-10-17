#include <stdio.h>
#include <string.h>

using namespace std;

const int maxn = 1000010;
int N;
char str[maxn];
int cnt[maxn];

void getf(int l)
{
        cnt[0] = cnt[1] = 0;
        for(int i=1; i<l; i++) {
                int j = cnt[i];
                while(j && str[i]!=str[j])
                        j = cnt[j];
                cnt[i+1] = str[i]==str[j] ? j+1 : 0;
        }
}

int main()
{
        int nCase = 0;
        while(scanf("%d", &N) && N) {
                getchar();
                for(int i=0; i<N; i++)
                        str[i] = getchar();
                str[N] = 0;
                memset(cnt, 0, sizeof(cnt));
                getf(N);
                printf("Test case #%d\n", ++nCase);
                for(int i=1; i<=N; i++)
                        if(cnt[i]>0 && !(i%(i-cnt[i])))
                                printf("%d %d\n", i, i/(i-cnt[i]));
                printf("\n");
        }

        return 0;
}
