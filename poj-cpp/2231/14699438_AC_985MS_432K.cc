#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 10005;

int N, arr[maxn];

int main()
{
        ll ans = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d", &arr[i]);
        for(int i=0; i<N; i++) {
                for(int j=i+1; j<N; j++) {
                        if(i!=j) {
                                ans += abs(arr[i]-arr[j]);
                        }
                }
        }
        printf("%lld\n", ans*2);

        return 0;
}
