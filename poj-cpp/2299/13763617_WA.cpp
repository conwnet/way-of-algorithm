#include <cstdio>
#include <cstdlib>

int cnt;

void Merge(int a[], int s, int m, int e){
    int i, j, t=0;
    int *temp = (int *)malloc((e-s+1)*sizeof(int));
    for(i=s, j=m+1; i<=m && j<=e; ){
        if(a[i]<=a[j]){
            temp[t++] = a[i++];
        }
        else{
            temp[t++] = a[j++];
            cnt += m-i+1;
        }
    }
    while(j<=e){
        temp[t++] = a[j++];
    }
    while(i<=m){
        temp[t++] = a[i++];
    }
    t = 0;
    for(i=s; i<=e; i++){
        a[i] = temp[t++];
    }
    free(temp);
}


void Msort(int a[], int s, int e){
    int m;

    if(s<e){
        m = (s+e)>>1;
        Msort(a, s, m);
        Msort(a, m+1, e);
        Merge(a, s, m, e);
    }
}


int main(){
    int n, i;
    int a[500000];

    while(scanf("%d", &n)!=EOF){
        if(0==n) break;
        cnt = 0;
        for(i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        Msort(a, 0, n-1);
        printf("%d\n", cnt);
    }

    return 0;
}
