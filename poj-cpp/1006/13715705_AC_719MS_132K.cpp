#include <cstdio>

int main(){
    int p, e, i, d, day, nCase=0, t;
    while(scanf("%d%d%d%d", &p, &e, &i, &d)){
        if(-1==p) break;
        for(day=1; day<=21252; day++){
            t = day+d;
            if(0==(t-p)%23 && 0==(t-e)%28 && 0==(t-i)%33)
                break;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", ++nCase, day);
    }
    return 0;
}
