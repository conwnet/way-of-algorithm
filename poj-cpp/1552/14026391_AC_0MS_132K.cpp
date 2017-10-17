#include <stdio.h>

int main()
{
        int arr[30], i, j, k, cnt;

        while(1){
                for(i=0; scanf("%d", &arr[i]) && arr[i] && arr[i]!=-1; i++) ;
                if(arr[i]==-1) break;
                cnt = 0;
                for(j=0; j<i; j++) {
                        for(k=j+1; k<i; k++) {
                                if(arr[k]==arr[j]*2 || arr[j]==arr[k]*2) cnt++;
                        }
                }
                printf("%d\n", cnt);

        }

        return 0;
}
