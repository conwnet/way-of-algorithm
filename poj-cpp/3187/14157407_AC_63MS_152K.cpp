#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, sum, arr[15], arr2[15];

int main()
{
        int i, j, k, t, n, cnt, ok;

        scanf("%d%d", &N, &sum);
        t = 1<<10;
        ok = 0;
        for(i=1; i<t; i++) {
                for(j=0, n=0; j<10; j++) if(i&(1<<j)) n++;
                if(n!=N) continue;
                for(j=0, cnt=0; j<10; j++)
                        if(i&(1<<j)) arr[cnt++] = j+1;

                do {
                        memcpy(arr2, arr, sizeof(arr));
                        for(j=N-1; j>0; j--) {
                                for(k=0; k<j; k++) {
                                        arr2[k] = arr2[k]+arr2[k+1];
                                }
                        }
                        if(arr2[0]==sum) {
                                ok = 1;
                                break;
                        }
                } while(next_permutation(arr, arr+N));
                if(ok) break;
        }
        for(i=0; i<N; i++) printf("%d ", arr[i]);

        return 0;
}

