#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

struct ADT {
        int edge[6];

        ADT(int arr[], int n)
        {
                for(int i=0; i<6; i++) {
                        edge[i] = arr[i];
                }
        }

        bool operator < (ADT B) const
        {
                if(edge[0]<B.edge[0]) return 1;
                else if(edge[0]==B.edge[0]) {
                        if(edge[1]<B.edge[1]) return 1;
                        else if(edge[1]==B.edge[1]) {
                                if(edge[2]<B.edge[2]) return 1;
                                else if(edge[2]==B.edge[2]) {
                                        if(edge[3]<B.edge[3]) return 1;
                                        else if(edge[3]==B.edge[3]) {
                                                if(edge[4]>B.edge[4]) return 1;
                                                else if(edge[4]==B.edge[4]) {
                                                        if(edge[5]<B.edge[5]) return 1;
                                                }
                                        }
                                }
                        }
                }
                return 0;
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
                sort(arr, arr+6);
                if(!flag) {
                        ADT t = ADT(arr, 6);
                        set<ADT>::iterator it = st.find(t);
                       // if(it!=st.end()) puts("fuck");
                        if(it!=st.end()) flag = 1;
                        st.insert(t);
                }
        }
        if(flag) puts("Twin snowflakes found.");
        else puts("No two snowflakes are alike.");


        return 0;
}
