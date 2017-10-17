#include <stdio.h>
#include <set>

using namespace std;

struct ADT {
        int arr[6];
        ADT(int *a) {
                for(int i=0; i<6; i++) arr[i] = a[i];
        }
        ADT(){}
        bool operator < (const ADT &b) const{
                for(int i=0; i<6; i++) {
                        if(arr[i]==b.arr[i]) continue;
                        return arr[i]<b.arr[i];
                }
                return 0;
        }
};

int maps[7][7], arr[6];
set<ADT> st;

int dfs(int y, int x, int n);

int main()
{
        int i, j;

        for(i=1; i<=5; i++) {
                for(j=1; j<=5; j++)
                        scanf("%d", &maps[i][j]);
        }
        for(i=1; i<=5; i++) {
                for(j=1; j<=5; j++)
                        dfs(i, j, 0);
        }
        printf("%d\n", st.size());

        return 0;
}

int dfs(int y, int x, int n)
{
        arr[n] = maps[y][x];

        if(n==5) {
                st.insert(ADT(arr));

        } else {
                if(y+1<6) dfs(y+1, x, n+1);
                if(y-1>0) dfs(y-1, x, n+1);
                if(x+1<6) dfs(y, x+1, n+1);
                if(x-1>0) dfs(y, x-1, n+1);
        }

}

