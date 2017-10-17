#include <stdio.h>
#include <string.h>

using namespace std;

int u[2005], v[2005];
int N, M, K;

int main()
{
        int T;

        scanf("%d", &T);
        for(int nCase=1; nCase<=T; nCase++) {
                scanf("%d%d%d", &N, &M, &K);
                for(int i=0; i<K; i++)
                        scanf("%d%d", &u[i], &v[i]);
                int ans = 0;
                for(int i=0; i<K; i++) {
                        for(int j=i+1; j<K; j++) {
                                if(u[i]==u[j] || v[i]==v[j])
                                        continue;
                                if(u[i]<u[j] != v[i]<v[j])
                                        ans++;
                        }
                }
                printf("Test case %d: %d\n", nCase, ans);
        }

        return 0;
}
