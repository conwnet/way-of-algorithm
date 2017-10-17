#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define INF 300 
int dx[]={-1,0,0,0,1};
int dy[]={0,1,0,-1,0};

int map[15][15],flip[15][15],ans[15][15];
int m,n;

int get(int x,int y)//（x,y）的颜色
{
    int res=map[x][y];
    for(int i=0;i<5;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=0&&a<m&&b>=0&&b<n)
        {
            res+=flip[a][b];
        }
    }
    return res&1;
}

int calc()//求出第一行确定的情况下的最小操作次数，
{
    for(int i=1;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(get(i-1,j))//（i-1，j）是黑色，就要翻转
            {
                flip[i][j]=1;
            }
        }

    for(int i=0;i<n;i++)//无解
    {
        if(get(m-1,i)) return INF;
    }

    int res=0;//翻转次数
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            res+=flip[i][j];
    return res;
}
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&map[i][j]);
        int res=INF;
        memset(ans,0,sizeof(ans));
        for(int i=0;i< 1<<n;i++)//枚举第一行的所有翻转情况
        {
            memset(flip,0,sizeof(flip));
            for(int j=0;j<n;j++)
            {
                flip[0][j]= i>>j&1;//在i的状态下，第一行的j是否翻转
            }
            int temp=calc();
            if(temp<res)
            {
                res=temp;
                for(int i=0;i<m;i++)
                    for(int j=0;j<n;j++) ans[i][j]=flip[i][j];
            }
        }
        if(res==INF)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                printf("%d",ans[i][j]);
                if(j!=n-1) printf(" ");
                else   printf("\n");
            }
    }
}
