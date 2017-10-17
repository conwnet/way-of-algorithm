#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MOD = 1e8;
int fib[10000][10000], len[10000];

void add(int *a, int &la, int *b, int lb)
{
        for(int i=0; i<lb; i++)
                a[i] += b[i];
        if(lb>la) la = lb;
        for(int i=0; i<la; i++)
        if(a[i]>=MOD) {
                a[i+1] += a[i]/MOD;
                a[i] %= MOD;
        }
        if(a[la]) la++;
}

void solve()
{
        fib[0][0] = 0; fib[1][0] = 1;
        for(int i=0; i<10000; i++)
                len[i] = 1;
        for(int i=2; i<=5000; i++) {
                add(fib[i], len[i], fib[i-1], len[i-1]);
                add(fib[i], len[i], fib[i-2], len[i-2]);
        }
}

void print(int *a, int l)
{
        printf("%d", a[l-1]);
        for(int i=l-2; i>=0; i--)
                printf("%08d", a[i]);
        printf("\n");
}

int stoi(char *a, char *b)
{
        int s = 0;
        for(; a<b; a++)
                s = s*10 + *a-'0';
        return s;
}

void str2int(char *s, int *a, int &l)
{
        int ls = strlen(s);
        l = 0;
        for(; ls-8>=0; ls-=8)
                a[l++] = stoi(s+ls-8, s+ls);
        if(ls>0) a[l++] = stoi(s, s+ls);
}

int cmp(int *a, int la, int *b, int lb)
{
        if(la != lb) return la<lb ? -1 : 1;
        for(int i=la-1; i>=0; i--) {
                if(a[i]!=b[i]) return a[i]<b[i] ? -1 : 1;
        }
        return 0;
}

int tn[10010], ll;
int main()
{
        int l, r;
        char A[1024], B[1024];
        solve();
        while(scanf("%s%s", &A, &B)) {
                if(A[0]=='0' && B[0]=='0') break;
                l = 0, r = 5000;
                str2int(A, tn, ll);
                while(l<r) {
                        int m = (l+r)>>1;
                        int cc = cmp(fib[m], len[m], tn, ll);
                        if(cc==-1) l = m+1;
                        else r = m;
                }
                int a = l;
                l = 0, r = 5000;
                str2int(B, tn, ll);
                while(l<r) {
                        int m = (l+r+1)>>1;
                        int cc = cmp(fib[m], len[m], tn, ll);
                        if(cc==1) r = m-1;
                        else l = m;
                }
                int b = l;
                printf("%d\n", b-a+1);
        }

        return 0;
}

/**<

0 1 1 2 3 5 8

 */
