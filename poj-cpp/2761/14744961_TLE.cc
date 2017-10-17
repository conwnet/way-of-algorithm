#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const int BS = 1000;
vector<int> B[maxn/BS];
int arr[maxn], N, M;
int num[maxn];

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++) {
                scanf("%d", &arr[i]);
                B[i/BS].push_back(arr[i]);
                num[i] = arr[i];
        }
        for(int i=0; i<N/BS; i++)
                sort(B[i].begin(), B[i].end());
        sort(num, num+N);
        int L, R, k;
        while(M--) {
                scanf("%d%d%d", &L, &R, &k);
                int l = 0;
                int r = N-1;
                while(l<r) {
                        int m = num[(l+r)>>1];
                        int tl = L-1;
                        int tr = R;
                        int c = 0;
                        while(tl<tr && tl%BS)
                                if(arr[tl++]<=m) c++;
                        while(tl<tr && tr%BS)
                                if(arr[--tr]<=m) c++;
                        for(int i=tl/BS; i<tr/BS; i++) {
                                c += upper_bound(B[i].begin(), B[i].end(), m) - B[i].begin();
                        }
                        if(c<k) l = (l+r)/2+1;
                        else r = (l+r)/2;
                }
                printf("%d\n", num[l]);
        }


        return 0;
}
