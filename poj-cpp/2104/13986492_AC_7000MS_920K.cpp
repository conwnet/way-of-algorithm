#include <stdio.h>
#include <algorithm>

using namespace std;

struct ADT{
        int num;
        int r;
}arr[150000];

int cmp(ADT a, ADT b)
{
        return a.num<b.num;
}

int main()
{
        int N, M, i, L, R, k;

        scanf("%d%d", &N, &M);
        for(i=1; i<=N; i++){
                scanf("%d", &arr[i].num);
                arr[i].r = i;
        }
        sort(arr+1, arr+N+1, cmp);
        while(M--){
                scanf("%d%d%d", &L, &R, &k);
                for(i=1; i<=N && k>0; i++){
                        if(L<=arr[i].r && R>=arr[i].r) k--;
                }

                printf("%d\n", arr[i-1].num);
        }

        return 0;
}
