#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MY_MAX 220000
int C[MY_MAX]; typedef vector<int> VCT_INT; vector<VCT_INT> G(MY_MAX/2); //邻接表
int Lowbit[MY_MAX]; bool HasApple[MY_MAX/2]; int Start[MY_MAX]; //dfs时的开始时间
int End[MY_MAX]; //dfs时的结束时间
int nCount = 0; void Dfs(int v) {  Start[v] = ++ nCount;  for( int i = 0;i < G[v].size();i ++ )    Dfs(G[v][i]);  End[v] = ++ nCount; }
int QuerySum(int p)  //求 sum(p)
 {  int nSum = 0;  while( p > 0 ) {   nSum += C[p];   p -= Lowbit[p];  }  return nSum; }
 void Modify( int p,int val) {  while( p <= nCount ) {   C[p] += val;   p += Lowbit[p];  } }
int main() {  int n;
 scanf("%d",&n);  int x,y;  int i,j,k;  //建图
  for( i = 0;i < n -1 ;i ++ ) {   int a,b;   scanf("%d%d",&a,&b);   G[a].push_back(b); //a有边连到b
   }  nCount = 0;  Dfs(1);
 //树状数组要处理的原始数组下标范围 1 -- nCount
 for( i = 1;i <= nCount;i ++) {   Lowbit[i] = i & ( i ^( i - 1));  }  for( i = 1;i <= n;i ++ )   HasApple[i] = 1;
 int m;  //求C数组，即树状数组的节点的值
  for( i = 1;i <= nCount;i ++ )   C[i] = i - (i - Lowbit[i]);    // C[i] = Sum[i] - Sum[i-lowbit(i)]
 scanf("%d",&m);  for( i = 0;i < m;i ++ ) {   char cmd[10];   int a;   scanf("%s%d",cmd,&a);   if( cmd[0] == 'C' ) {    if( HasApple[a] ) {        Modify( Start[a],-1);  Modify( End[a],-1);     HasApple[a] = 0;    }    else {     Modify( Start[a],1);  Modify( End[a],1);     HasApple[a] = 1;    }   }   else {    int t1 = QuerySum(End[a]);    int t2 = QuerySum(Start[a]-1);    printf("%d\n",(t1-t2)/2 );   }  } }
