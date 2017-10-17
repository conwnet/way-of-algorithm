#include <stdio.h>

int main()
{
        int arr[6];

        while(1) {
                scanf("%d", &arr[0]);
                int sum = arr[0];
                int maxs = arr[0];
                int mins = arr[0];
                for(int i=1; i<6; i++) {
                        scanf("%d", &arr[i]);
                        if(arr[i]>maxs) maxs = arr[i];
                        if(arr[i]<mins) mins = arr[i];
                        sum += arr[i];
                }
                int k;
                for(k=0; k<6; k++)
                        if(arr[k]!=0) break;
                if(k==6) break;
                printf("%lg\n", (sum-maxs-mins)/4.0);
        }

        return 0;
}
