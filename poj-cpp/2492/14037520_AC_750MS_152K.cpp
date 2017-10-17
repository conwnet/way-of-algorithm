#include<stdio.h>  
int p[4010];  
  
int find(int x) {return p[x] == x ? x : p[x]=find(p[x]);}  
  
void unite(int x, int y)  
{  
    int u = find(x);  
    int v = find(y);  
    if(u!=v) p[u] = v;  
}  
  
int main()  
{  
    int T, N, k, x, y;  
  
    scanf("%d", &T);  
    for(int i=1; i<=T; i++)  
    {  
        int flag = 0;  
        scanf("%d%d", &N,&k);  
        for(int i=1; i<=2*N; i++) p[i] = i;  
        while(k--)  
        {  
            scanf("%d%d", &x,&y);  
            if(find(x)==find(y)) flag = 1;//同雄或同雌  
            else  
            {  
                unite(x,y+N);   
                unite(x+N,y);  
            }  
        }  
        printf("Scenario #%d:\n", i);  
        if(flag) puts("Suspicious bugs found!");  
        else puts("No suspicious bugs found!");  
        puts("");  
    }  
    return 0;  
}  