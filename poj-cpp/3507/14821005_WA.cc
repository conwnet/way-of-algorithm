#include <stdio.h>

int main()
{
        int arr[6];

        while(1) {
                int maxs = 0;
                int mins = 0x3f3f3f3f;
                int sum = 0;
                for(int i=0; i<6; i++) {
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
