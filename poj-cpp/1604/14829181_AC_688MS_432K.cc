#include <stdio.h>
#include <string.h>

int ans[10000];
int lnum[10000], len = 1;

void multi(int *lnum, int n)
{
        for(int p=0; p<len; p++) {
                lnum[p] *= n;
        }
        for(int p=0; p<len; p++) {
                if(lnum[p]>10000) {
                        lnum[p+1] += lnum[p]/10000;
                        lnum[p] %= 10000;
                }
        }
        if(lnum[len]>0) len++;
}

void print(int p)
{
        if(p==len) return ;
        print(p+1);
        printf("%04d", lnum[p]);
}

void solve()
{
        lnum[0] = 1;
        for(int i=1; i<=10000; i++) {
                multi(lnum, i);
                ///printf("%3d ", i); print(0); printf("\n");
                int p;
                for(p=0; !lnum[p]; p++);
                int t = lnum[p];
                while(0==t%10) t /= 10;
                ans[i] = t%10;
        }
}

int main()
{
        solve();
        int n;
        while(~scanf("%d", &n)) {
                printf("%5d -> %d\n", n, ans[n]);
        }

        return 0;
}
