#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int arr[maxn];
int num[maxn], n, m;

int cmp(int a, int b)
{
        return arr[a]<arr[b];
}

int main()
{
        int l, r, k;
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++)
                scanf("%d", &arr[i]);
        for(int i=0; i<n; i++) num[i] = i;
        sort(num, num+n, cmp);
        while(m--) {
                scanf("%d%d%d", &l, &r, &k);
                int i;
                for(i=0; i<n; i++) {
                        if(num[i]>=l-1 && num[i]<=r-1) {
                                k--;
                                if(!k) break;
                        }
                }
                printf("%d\n", arr[num[i]]);
        }

        return 0;
}