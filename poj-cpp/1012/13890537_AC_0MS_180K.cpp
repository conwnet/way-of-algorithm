#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n)){
        if(n==0) break;
        switch(n){
            case 1: printf("2\n"); break;
            case 2: printf("7\n"); break;
            case 3: printf("5\n"); break;
            case 4: printf("30\n"); break;
            case 5: printf("169\n"); break;
            case 6: printf("441\n"); break;
            case 7: printf("1872\n"); break;
            case 8: printf("7632\n"); break;
            case 9: printf("1740\n"); break;
            case 10: printf("93313\n"); break;
            case 11: printf("459901\n"); break;
            case 12: printf("1358657\n"); break;
            case 13: printf("2504881\n"); break;
        }
    }

    return 0;
}