#include <stdio.h>
#include <string.h>

using namespace std;

const int maxn = 1000010;
int N;
char str[maxn];
int cnt[maxn];

int main()
{
        int nCase = 0;
        while(scanf("%d", &N) && N) {
                getchar();
                for(int i=0; i<N; i++)
                        str[i] = getchar();
                str[N] = 0;
                memset(cnt, 0, sizeof(cnt));
                for(int i=1; i<N; i++) {
                        for(int j=i; j+i<N+5; j+=i) {
                                if(!strncmp(str, str+j, i)) {
                                        if(j/i+1>cnt[j+i])
                                                cnt[j+i] = j/i+1;
                                        else break;
                                } else break;
                        }
                }
                printf("Test case #%d\n", ++nCase);
                for(int i=1; i<=N; i++)
                        if(cnt[i]>0)
                                printf("%d %d\n", i, cnt[i]);
                printf("\n");
        }

        return 0;
}
