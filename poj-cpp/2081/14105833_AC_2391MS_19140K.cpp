#include <stdio.h>
#include <set>

using namespace std;

int arr[510000];

int main()
{
        int m, i;
        set<int> st;

        arr[0] = 0;
        st.insert(0);
        for(i=1; i<=500000; i++) {
               int n = arr[i-1]-i;
               if(n>0 && st.find(n)==st.end()) arr[i] = n;
               else arr[i] = arr[i-1]+i;
               st.insert(arr[i]);
        }
        while(scanf("%d", &m)) {
                if(m==-1) break;
                printf("%d\n", arr[m]);
        }

        return 0;
}
