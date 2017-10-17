#include <stdio.h>

int main()
{
        int arr[10], T;

        scanf("%d", &T);
        while(T--) {
                for(int i=0; i<4; i++) scanf("%d", &arr[i]);
                int a = arr[3]-arr[2];
                int b = arr[2]-arr[1];
                int c = arr[1]-arr[0];
                for(int i=0; i<4; i++) printf("%d ", arr[i]);
                if(a==b && b==c) {
                        printf("%d\n", arr[3]+a);
                } else {
                        printf("%d\n", arr[3]*(arr[2]/arr[1]));
                }
        }

        return 0;
}
