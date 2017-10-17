#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int arr[11000];

set<int> st;

int main()
{
        int T, N, i, ok;

        scanf("%d", &T);
        while(T--) {
                st.clear();
                scanf("%d", &N);
                for(i=0; i<N; i++) scanf("%d", &arr[i]);
                sort(arr, arr+N);
                for(i=0; i<N; i++) {
                        ok = 0;
                        for(int t=arr[i]; t; t/=10) {
                                if(st.find(t)!=st.end()) { ok = 1; break; }
                        }
                        if(!ok) st.insert(arr[i]);
                        else break;
                }
                if(ok) printf("NO\n");
                else printf("YES\n");
        }

        return 0;
}
