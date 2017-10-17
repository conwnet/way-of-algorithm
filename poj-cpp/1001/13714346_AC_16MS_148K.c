#include <stdio.h>
#include <string.h>

typedef char BigInt[1024];

void Add(BigInt a, BigInt b, BigInt sum);
void Mule(BigInt a, BigInt b, BigInt sum);
void Mul(BigInt a, BigInt b, BigInt sum);

int main()
{
    BigInt a, b, sum, temp, rzt;
    int n, i, l, fyn, df, tb;
    while(scanf("%s%d", a, &n)!=EOF){
        l=strlen(a);
        fyn = 0;
        df = 0;
        for(i=0; i<l; i++){
            if(a[i]=='.'){
                fyn = 1;
                break;
            }
        }
        if(fyn==1){
            for(i=l-1; a[i]=='0'; i--){
                a[i] = '\0';
            }
        }
        l=strlen(a);
        if(a[l-1]=='.'){
            a[l-1] = '\0';
            fyn = 0;
        }

        if(1==n){
            printf("%s\n", a);
            continue;
        }
        if(0==n){
            printf("1\n");
            continue;
        }

        if(fyn==1){
            l=strlen(a);
            tb = l-1;
            b[tb--]='\0';
            for(i=l-1; i>0; i--){
                if(a[i]!='.') df++;
                else break;
            }

            for(i=l-1; i>=0; i--){
                if(a[i]=='.'){
                    continue;
                }
                b[tb--] = a[i];
            }
            strcpy(a, b);
        }
        else strcpy(b, a);

        for(i=1; i<n; i++){
            Mul(a, b, sum);
            strcpy(b, sum);
        }

        if(df!=0){
            df *= n;
            l = strlen(sum);
            tb = l+1;
            b[tb--] = '\0';
            for(i=l-1; i>=0; i--){
                if(l-i-1==df){
                    b[tb--] = '.';
                }
                b[tb--] = sum[i];
            }
        }

        if('0'==b[0]) printf("%s\n", b+1);
        else printf("%s\n", b);
    }
    return 0;
}


void Add(BigInt a, BigInt b, BigInt sum){
    int ta[1024], tb[1024], tsum[1024];
    int i, j, k=0, t, b0=0, b1=1;
    memset(sum, 0, 1024);
    for(i=0; a[i]!='\0'; i++){
        ta[i] = a[i]-'0';
    }
    for(j=0; b[j]!='\0'; j++){
        tb[j] = b[j]-'0';
    }
    if(i>j){
        k = i;
        while(j--){
            i--;
            tsum[i] = ta[i]+tb[j];
        }
        while(i--){
            tsum[i] = ta[i];
        }
    }
    else{
        k = j;
        while(i--){
            j--;
            tsum[j] = tb[j]+ta[i];
        }
        while(j--){
            tsum[j] = tb[j];
        }
    }
    for(t=k-1; t>=1; t--){
        if(tsum[t]>=10){
            tsum[t-1] += 1;
            tsum[t] %= 10;
        }
    }
    if(tsum[0]>=10){
        tsum[0] %= 10;
        for(t=0; t<k; t++){
            sum[t+1] = tsum[t]+'0';
        }
        sum[0] = '1';
    }
    else{
        for(t=0; t<k; t++){
            sum[t] = tsum[t]+='0';
        }
    }
}

void Mule(BigInt a, int b, BigInt sum){
    int l, i;
    int tsum[1024]={0};
    int tnum[1024];
    memset(sum, 0, 1024);
    l = strlen(a);
    for(i=0; i<l; i++){
        tnum[i] = a[i]-'0';
    }
    for(i=0; i<l; i++){
        tsum[i+1] = tnum[i]*b;
    }
    for(i=l; i>0; i--){
        tsum[i-1] += tsum[i]/10;
        tsum[i] %= 10;
    }
    if(tsum[0]==0){
        for(i=1; i<=l; i++){
            sum[i-1] = tsum[i] + '0';
        }
    }
    else{
        for(i=0; i<=l; i++){
            sum[i] = tsum[i] + '0';
        }
    }
}

void Mul(BigInt a, BigInt b, BigInt sum){
    int tnum[1024];
    BigInt tsum, ta, tb;
    int lb, i, ltb;
    memset(sum, 0, 1024);
    lb = strlen(b);
    for(i=0; i<lb; i++){
        tnum[i] = b[i] - '0';
    }
    Mule(a, tnum[0], sum);
    for(i=1; i<lb; i++){
        Mule(a, tnum[i], ta);
        strcpy(tb, sum);
        ltb = strlen(tb);
        tb[ltb] = '0';
        tb[ltb+1] = '\0';
        Add(tb, ta, sum);
    }
}
