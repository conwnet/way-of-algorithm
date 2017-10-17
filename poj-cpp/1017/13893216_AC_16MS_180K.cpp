#include <stdio.h>

int prdu[7];

int solve();

int main(){
    int i, sum;

    while(scanf("%d%d%d%d%d%d", &prdu[1], &prdu[2], &prdu[3], &prdu[4], &prdu[5], &prdu[6])){
        if(!prdu[1] && !prdu[2] && !prdu[3] && !prdu[4] && !prdu[5] && !prdu[6]) break;
        printf("%d\n", solve()+prdu[6]);
    }
    return 0;
}

int solve(){
    int t, s, cnt=0;

    while(1){
        if(prdu[5]>0){
            prdu[5]--;
            for(t=0; t<11 && prdu[1]>0; prdu[1]--, t++);
        }
        else if(prdu[4]>0){
            prdu[4]--;
            for(t=0; t<5 && prdu[2]>0; prdu[2]--, t++);
            s = 20-t*4;
            for(t=0; t<s && prdu[1]>0; prdu[1]--, t++);
        }
        else if(prdu[3]>0){
            for(t=0; t<4 && prdu[3]>0; prdu[3]--, t++);
            if(t==1){
                for(t=0; t<5 && prdu[2]>0; prdu[2]--, t++);
                s = 27-t*4;
                for(t=0; t<s && prdu[1]>0; prdu[1]--, t++);
            }
            else if(t==2){
                for(t=0; t<3 && prdu[2]>0; prdu[2]--, t++);
                s = 18-t*4;
                for(t=0; t<s && prdu[1]>0; prdu[1]--, t++);
            }
            else if(t==3){
                if(prdu[2]>0){
                    prdu[2]--;
                    for(t=0; t<5 && prdu[1]>0; prdu[1]--, t++);
                }
                else{
                    for(t=0; t<9 && prdu[1]>0; prdu[1]--, t++);
                }
            }
        }
        else if(prdu[2]>0){
            for(t=0; t<9 && prdu[2]>0; prdu[2]--, t++);
            s = 36-t*4;
            for(t=0; t<s && prdu[1]>0; prdu[1]--, t++);
        }
        else if(prdu[1]>0){
            for(t=0; t<36 && prdu[1]>0; prdu[1]--, t++);
        }
        else break;
        cnt ++;
    }
    return cnt;
}