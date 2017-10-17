#include <stdio.h>
#include <string.h>
#include <math.h>

int prime[1300000];

void getPrime();

int main(){
    int i, N;

    getPrime();
    //for(i=1; i<100; i++) if(!prime[i]) printf("%d ", i);
    while(scanf("%d", &N), N){
        for(i=3; i<N; i++){
            if(prime[i]!=0) continue;
            if(prime[N-i]==0) break;
        }
        if(i!=N) printf("%d = %d + %d\n", N, i, N-i);
        else printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}

void getPrime(){
    int i, j;
int t = sqrt(1200000)+0.5;
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for(i=2; i<=t; i++){
        if(!prime[i]){
            for(j=i*i; j<=1200000; j+=i)
                prime[j] = 1;
        }
    }

} 