#include <stdio.h>
#include <algorithm>

using namespace std;

struct point
{
    int x , y;
} p[50005];

int top , stack[50005]; // 凸包的点存在于 stack[]中

inline double dis(const point &a , const point &b)
{
    return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}

inline int max(int a , int b)
{
    return a > b ? a : b;
}

inline int xmult(const point &p1 , const point &p2 , const point &p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}

int cmp(const void * a , const void * b)  //逆时针排序 返回正数要交换
{
    struct point *p1 = (struct point *)a;
    struct point *p2 = (struct point *)b;
    int ans = xmult(*p1 , *p2 , p[0]); //向量叉乘
    if(ans < 0) //p0p1 线段在 p0p2 线段的上方，需要交换
        return 1;
    else if(ans == 0 && ( (*p1).x >= (*p2).x)) //斜率相等时，距离近的点在先
        return 1;
    else
        return -1;
}

void graham(int n)  //形成凸包
{
    qsort(p+1 , n-1 , sizeof(point) , cmp);
    int i;
    stack[0] = 0 , stack[1] = 1;
    top = 1;
    for(i = 2 ; i < n ; ++i)
    {
        while(top > 0 && xmult( p[stack[top]] , p[i] , p[stack[top-1]]) <= 0)
            top--; //顺时针方向--删除栈顶元素
        stack[++top] = i; //新元素入栈
    }
    int temp = top;
    for(i = n-2 ; i >= 0 ; --i)
    {
        while(top > temp && xmult(p[stack[top]] , p[i] , p[stack[top-1]]) <= 0)
            top--;
        stack[++top] = i; //新元素入栈
    }
}
int rotating_calipers()  //卡壳
{
    int i , q=1;
    int ans = 0;
    stack[top]=0;
    for(i = 0 ; i < top ; i++)
    {
        while(  xmult(  p[stack[i+1]]  ,  p[stack[q+1]]  ,  p[stack[i]]  )  >
                xmult( p[stack[i+1]] , p[stack[q]] , p[stack[i]] ) )
            q = (q+1)%(top);
        ans = max(ans , max( dis(p[stack[i]] , p[stack[q]]) , dis(p[stack[i+1]] ,
                             p[stack[q+1]])));
    }
    return ans;
}
int main()
{
    int i , n , leftdown;
    scanf("%d",&n);
    leftdown = 0;
    for(i = 0 ; i < n ; ++i)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
        if(p[i].y < p[leftdown].y || (p[i].y == p[leftdown].y && p[i].x < p[leftdown].x))
            leftdown = i;
    }
    swap(p[0] , p[leftdown]);
    graham(n);
    printf("%d\n",rotating_calipers());
    return 0;
}
