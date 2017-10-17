#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
        int i, N, t, c;
        stack<int> rail;

        while(scanf("%d", &N)&&N) {
                while(scanf("%d", &t)){
                        if(t==0) { printf("\n"); break; }
                        while(!rail.empty()) rail.pop();
                        rail.push(0);
                        for(i=1; i<t; i++) rail.push(i);
                        c = t+1;
                        for(i=1; i<N; i++) {
                                scanf("%d", &t);
                                if(rail.top()==t) { rail.pop(); continue; }
                                do rail.push(c++); while(rail.top()!=t && c<=N);
                                if(rail.top()==t) { rail.pop(); continue; }
                        }
                        if(rail.size()==1) printf("Yes\n");
                        else printf("No\n");
                }
        }

        return 0;
}
