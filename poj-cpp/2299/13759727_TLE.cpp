#include <cstdio>

int main(){
    int nums, a[500000];
    int i, j, n, t;

    while(scanf("%d", &nums)!=EOF){
        if(nums==0) return 0;
        n = 0;
        for(i=0; i<nums; i++){
            scanf("%d", &a[i]);
        }
        for(i=nums-1; i>0; i--){
            for(j=0; j<i; j++){
                if(a[j]>a[j+1]){
                    t = a[j+1];
                    a[j+1] = a[j];
                    a[j] = t;
                    n++;
                }
            }
        }
        printf("%d\n", n);
    }
    return 0;
}
