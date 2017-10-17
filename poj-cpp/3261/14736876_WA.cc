#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


const int maxn = 20010;
int sa[maxn], rank[maxn], lcp[maxn];
int len, sa_k, tmp[maxn];

int cmp_sa(int a, int b)
{
        if(rank[a]!=rank[b])
                return rank[a]<rank[b];
        int ra = a+sa_k<=len ? rank[a+sa_k] : -1;
        int rb = b+sa_k<=len ? rank[b+sa_k] : -1;
        return ra < rb;
}

void cal_sa(char *str)
{
        len = strlen(str);
        for(int i=0; i<=len; i++) {
                sa[i] = i;
                rank[i] = str[i];
        }
        rank[len] = -1;
        for(sa_k=1; sa_k<=len; sa_k<<=1) {
                sort(sa, sa+len+1, cmp_sa);
                tmp[sa[0]] = 0;
                for(int i=1; i<=len; i++) {
                        tmp[sa[i]] = tmp[sa[i-1]] +
                        (cmp_sa(sa[i-1], sa[i]) ? 1 : 0);
                }
                for(int i=0; i<=len; i++)
                        rank[i] = tmp[i];
        }
}

void cal_lcp(char *str)
{
        for(int i=0; i<=len; i++)
                rank[sa[i]] = i;
        int h = 0;
        for(int i=0; i<len; i++) {
                int j = sa[rank[i]-1];
                if(h>0) h--;
                for(; i+h<len && j+h<len; h++)
                        if(str[i+h]!=str[j+h])
                                break;
                lcp[rank[i]-1] = h;
        }
}

char str[maxn];
int arr[maxn], N, K;

int is_ok(int n)
{
        int cnt = 0;
        for(int i=0; i<len; i++) {
                if(lcp[i]>=n)
                        cnt++;
                else cnt = 0;
                if(cnt>=K-1) return 1;
        }
        return 0;
}

int main()
{
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
                scanf("%d", &arr[i]);
        for(int i=0; i<N; i++)
                str[i] = arr[i];
        str[N] = 0;
        cal_sa(str);
        cal_lcp(str);
        int l = 0; int r = len*2;
        while(l<r) {
                int m = (l+r+1) >> 1;
                if(is_ok(m)) l = m;
                else r = m-1;
        }
        printf("%d\n", l);

        return 0;
}


/**<

12323231

8 7 0 5 3 1 6 4 2


 */


