#include <cstdio>

int main(){
    int x, y, m, n, l;
    int cnt;

    while(scanf("%d%d%d%d%d", &x, &y, &m, &n, &l)!=EOF){
        cnt = 0;
        if(x!=y && m==n){
            printf("Impossible\n");
            continue;
        }
        while(x!=y){
            x += m;
            if(x>=l) x%=l;
            y += n;
            if(y>=l) y%=l;
            cnt ++;
            if(cnt==999999){
                printf("Impossible\n");
                break;
            }
        }
        if(cnt!=99999) printf("%d\n", cnt);
    }
    return 0;
}
