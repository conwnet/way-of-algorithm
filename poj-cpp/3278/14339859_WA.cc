#include <iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
bool map[200005];
int deep[200005];
int k;
int bfs(int n)
{
    //int i=0;
    queue<int> a;
    a.push(n);
    map[n]=1;
    while(!a.empty())
    {

        int p=a.front();
        if(p==k)
        {
            return deep[p];
        }
        a.pop();
        if(p-1>=0 && !map[p-1])
        {
            a.push(p-1);
            deep[p-1]=deep[p]+1;
            map[p-1]=1;
        }
        if(p+1<=100000 && !map[p+1])
        {
            deep[p+1]=deep[p]+1;
            a.push(p+1);
            map[p+1]=1;
        }
        if(p*2<=100000 && !map[p*2])
        {
            deep[p*2]=deep[p]+1;
            a.push(p*2);
            map[p*2]=1;
        }
    }
}
int main()
{
    memset(map,0,sizeof(map));
    int n;
    scanf("%d%d",&n,&k);
    printf("%d\n",bfs(n));
    return 0;
}