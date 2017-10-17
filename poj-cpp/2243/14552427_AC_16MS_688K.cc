//POJ2243
//BFS standard first
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#define N 10
using namespace std;
int x1,y1,x2,y2;
int sum;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
queue<int> xx;//辅助队列
queue<int> yy;
bool map[N][N];//访问标志数组
int levels[N][N];//表示i,j的树装层次,这类题中就是记录steps
bool inmap(int x,int y){//judge if the point is in the map
    return ( x<=8 && y<=8 && x>0 && y>0 );
}
void bfs(int x,int y){
    for(int k=0;k<8;k++)
        if(inmap(x+dx[k],y+dy[k]) && !map[x+dx[k]][y+dy[k]]){
            map[x+dx[k]][y+dy[k]] = true;
            levels[x+dx[k]][y+dy[k]] = levels[x][y] + 1; 
            xx.push(x+dx[k]);
            yy.push(y+dy[k]);
            //sum++;
            if(x+dx[k]==x2 && y+dy[k]==y2){
                sum = levels[x+dx[k]][y+dy[k]];
                return;
            }
        }
    if(!xx.empty()){
        xx.pop();
        yy.pop();
    }
    if(!xx.empty())
        bfs( xx.front(),yy.front() );
}
int main(){
    char s[10];
    while( gets(s) ){//pay attention to the way to input
        //also: while (cin>>ln1>>pt1.col>>ln2>>pt2.col)  
        //input
        sum = 0;
        x1 = (int)s[0] - 96;
        y1 = (int)s[1] - 48;
        x2 = (int)s[3] - 96;
        y2 = (int)s[4] - 48;
        //init
        while(!xx.empty()){
            xx.pop();
            yy.pop();
        }
        memset(map,false,sizeof(map));
        memset(levels,0,sizeof(levels));
        xx.push(x1);
        yy.push(y1);
        map[x1][y1] = true;//have been searched
        levels[x1][y1] = 0;
        bfs(x1,y1);

        cout <<"To get from "<<s[0]<<y1<<" to "<<s[3]<<y2<<" takes "<<sum<<" knight moves."<< endl;
    }
    return 0;
}