#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int, int> P;
char str[128][128][30];
P prev[128][128];

void print(P ans, int h)
{
        if(ans.first==0 && ans.second==0) { printf("%d\n", h); return; }
        else print(prev[ans.first][ans.second], h+1);
        printf("%s\n", str[ans.first][ans.second]);
}

int main()
{
        int A, B, C;
        queue<P> que;
        P ans = P(-1, -1);
        for(int i=0; i<16384; i++) prev[0][i] = P(-1, -1);
        scanf("%d%d%d", &A, &B, &C);
        que.push(P(0, 0));
        while(!que.empty()) {
                P t = que.front(); que.pop();
                int a = t.first, b = t.second;
                if(t.first==C || t.second==C) { ans = t; break; }

                if(prev[A][b].first==-1 && prev[A][b].second==-1) {
                        que.push(P(A, b));
                        prev[A][b] = P(a, b);
                        strcpy(str[A][b], "FILL(1)");
                }

                if(prev[a][B].first==-1 && prev[a][B].second==-1) {
                        que.push(P(a, B));
                        prev[a][B] = P(a, b);
                        strcpy(str[a][B], "FILL(2)");
                }

                if(prev[a][0].first==-1 && prev[a][0].second==-1) {
                        que.push(P(a, 0));
                        prev[a][0] = P(a, b);
                        strcpy(str[a][0], "DROP(2)");
                }

                if(prev[0][b].first==-1 && prev[0][b].second==-1) {
                        que.push(P(0, b));
                        prev[0][b] = P(a, b);
                        strcpy(str[0][b], "DROP(1)");
                }

                if(prev[a>B-b?a+b-B:0][a>B-b?B:b+a].first==-1 && prev[a>B-b?a+b-B:0][a>B-b?B:b+a].second==-1) {
                        que.push(P(a>B-b?a+b-B:0, a>B-b?B:b+a));
                        prev[a>B-b?a+b-B:0][a>B-b?B:b+a] = P(a, b);
                        strcpy(str[a>B-b?a+b-B:0][a>B-b?B:b+a], "POUR(1,2)");
                }

                if(prev[b>A-a?A:a+b][b>A-a?b+a-A:0].first==-1 && prev[b>A-a?A:a+b][b>A-a?b+a-A:0].second==-1) {
                        que.push(P(b>A-a?A:a+b, b>A-a?b+a-A:0));
                        prev[b>A-a?A:a+b][b>A-a?b+a-A:0] = P(a, b);
                        strcpy(str[b>A-a?A:a+b][b>A-a?b+a-A:0], "POUR(2,1)");
                }
        }
        if(ans.first==-1 && ans.second==-1) printf("impossible\n");
        else print(ans, 0);

        return 0;
}

