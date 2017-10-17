#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

struct ADT {
        int edge[6];

        ADT(int arr[], int n)
        {
                sort(arr, arr+n);
                for(int i=0; i<6; i++) {
                        edge[i] = arr[i];
                }
        }

        bool operator < (ADT B) const
        {
                return edge[0]<B.edge[0] && edge[1]<B.edge[1] && edge[2]<B.edge[2] && edge[3]<B.edge[3] && edge[4]<B.edge[4] && edge[5]<B.edge[5];
        }
};

int main()
{
        set<ADT> st;
        int flag, N, arr[6], i;

        flag = 0;
        scanf("%d", &N);
        st.clear();
        while(N--) {
                for(i=0; i<6; i++) {
                        scanf("%d", &arr[i]);
                }
                if(!flag) {
                        ADT t = ADT(arr, 6);
                        set<ADT>::iterator it = st.find(t);
                        if(it==st.end()) flag = 1;
                        st.insert(t);
                }
        }
        if(flag) puts("Twin snowflakes found.");
        else puts("No two snowflakes are alike.");


        return 0;
}
