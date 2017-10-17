#include <iostream>
#include<stdio.h>
using namespace std;
int sum,n[7];
bool dfs(int a,int num)
{
    if(a==sum/2)
        return true;
    for(;num>0;num--)
    {
        if(n[num]&&a+num<=sum/2)
            {
                n[num]--;
                if(dfs(a+num,num))
                    return true;
               //n[num]++;   // 为什么剪这个枝，不剪就超时？？？？？？
             }
    }
    return false;
}
int main()
{
   // freopen("input.txt","r",stdin);
    int count=1;
    while(scanf("%d%d%d%d%d%d",&n[1],&n[2],&n[3],&n[4],&n[5],&n[6]),n[1]||n[2]||n[3]||n[4]||n[5]||n[6])
    {
        sum=0;
        for(int i=1;i<=6;i++)
            sum+=n[i]*i;
        if(sum%2==1)
        {
           printf("Collection #%d:\nCan't be divided.\n\n",count++);
            continue;
        }
        else{
            if(dfs(0,6))
              printf("Collection #%d:\nCan be divided.\n\n",count++);
            else
                printf("Collection #%d:\nCan't be divided.\n\n",count++);

           }
    }
    return 0;
}