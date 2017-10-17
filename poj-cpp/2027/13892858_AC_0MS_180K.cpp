#include <stdio.h>

int main(){
    int Q, a, b;
    scanf("%d", &Q);
    while(Q--){
        scanf("%d%d", &a, &b);
        if(a<b) printf("NO BRAINS\n");
        else printf("MMM BRAINS\n");
    }
    return 0;
}