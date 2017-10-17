#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[400][400], N;

int main()
{
        int i, j;

        scanf("%d", &N);
        for(i=1; i<=N; i++) {
                for(j=1; j<=i; j++) scanf("%d", &arr[i][j]);
        }
        for(i=N-1; i>0; i--) {
                for(j=1; j<=i; j++) {
                        arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
                }
        }
        printf("%d", arr[1][1]);


        return 0;
}
