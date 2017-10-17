#include <cstdio>

int main(){
    int nums, a[500000];
    int i, j, n, t, jds;

    while(scanf("%d", &nums)!=EOF){
        if(nums==0) return 0;
        n = 0;
        for(i=0; i<nums; i++){
            scanf("%d", &a[i]);
        }
        jds = 0;
        for(i=nums-1; i>0; i--){
            for(j=0; j<i; j++){
                if(a[j]>a[j+1]){
                    t = a[j+1];
                    a[j+1] = a[j];
                    a[j] = t;
                    n++;
                    jds = 1;
                }
            }
            if(jds==0) break;
            jds = 0;
        }
        printf("%d\n", n);
    }
    return 0;
}
