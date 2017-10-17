#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 800;

int sa[maxn], rank[maxn];
int tmp[maxn], lcp[maxn];
int len, sa_k;

int cmp_sa(int a, int b)
{
        if(rank[a] != rank[b])
                return rank[a] < rank[b];
        int x = a+sa_k<=len ? rank[a+sa_k] : -1;
        int y = b+sa_k<=len ? rank[b+sa_k] : -1;
        return x < y;
}

void cal_sa(string &str)
{
        len = str.length();
        for(int i=0; i<=len; i++) {
                sa[i] = i;
                rank[i] = str[i];
        }
        rank[len] = -1;
        for(sa_k=1; sa_k<=len; sa_k<<=1) {
                sort(sa, sa+len+1, cmp_sa);
                tmp[sa[0]] = 0;
                for(int i=1; i<=len; i++)
                        tmp[sa[i]] = tmp[sa[i-1]] + (cmp_sa(sa[i-1], sa[i]) ? 1 : 0);
                for(int i=0; i<=len; i++)
                        rank[i] = tmp[i];
        }
}

void cal_lcp(string str)
{
        for(int i=0; i<=len; i++)
                rank[sa[i]] = i;
        int h = 0;
        for(int i=0; i<len; i++) {
                int j = sa[rank[i]-1];
                if(h>0) h--;
                for(; i+h<len && j+h<len; h++)
                        if(str[i+h] != str[j+h])
                                break;
                lcp[rank[i]-1] = h;
        }
}

int cnt[15], N;
string S;
char str[80];

int judge(int n)
{
        int use[15];
        int i, j, res;
        for(i=0; i<len; i++) {
                res = 0;
                if(lcp[i]>=n) {
                        for(j=i; j<len && lcp[j]>=n; j++);
                        memset(use, 0, sizeof(use));
                        for(int k=i; k<=j; k++) {
                                int l = sa[k]/61;
                                if(!use[l]) {use[l]=1;res++;}
                        }
                        if(res==N) return i;
                        i = j;
                }
        }
        return -1;
}

int main()
{
        int T;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                S.clear();
                cnt[0] = 0;
                for(int i=1; i<=N; i++) {
                        scanf("%s", str);
                        cnt[i] = cnt[i-1] + strlen(str)+1;
                        char tmp[3] = {i, 0};
                        S = S + tmp + str;
                }
                cal_sa(S);
                cal_lcp(S);
                int l = 1;
                int r = len;
                int ss = 1;
                while(l<r) {
                        int s;
                        int m = (l+r+1) >> 1;
                        if((s=judge(m))!=-1) { l = m;}
                        else r = m-1;
                        if(s!=-1) ss = s;
                }
                if(l<3) printf("no significant commonalities\n");
                else printf("%s\n", S.substr(sa[ss], l).c_str());
        }

        return 0;
}
