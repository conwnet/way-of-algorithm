#include<iostream>
#include<algorithm>
#include <stdio.h>
#define maxn 100010
using namespace std;
int dp[maxn],n,k;
int v[101],w[101],V;
void zero(int cost)
{
    for(int i=V;i>=cost;i--)
        dp[i]=max(dp[i],dp[i-cost]+cost);
}
void complet(int cost)
{
    for(int i=cost;i<=V;i++)
        dp[i]=max(dp[i],dp[i-cost]+cost);
}
void multi(int cost,int amount)
{
    if(cost * amount>=V)
    {
        complet(cost);
        return ;
    }
    int k=1;
    while(k<amount)
    {
        zero(k*cost);
            amount-=k;
        k<<=1;
    }
    zero(amount*cost);
}
int main()
{
    while(scanf("%d %d",&n,&V)==2&&(n||V))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(int i=1;i<=V;i++)
            dp[i]=-99999999;
        dp[0]=0;
        for(int i=0;i<n;i++)
            multi(v[i],w[i]);
        int count=0;
        for(int i=1;i<=V;i++)
            if(dp[i]>=0)
                count++;
        printf("%d\n",count);
    }
    return 0;
}
