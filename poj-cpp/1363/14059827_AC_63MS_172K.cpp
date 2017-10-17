#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
        int N, i, arr[1024], faild;
        stack<int> stk;

        while(scanf("%d", &N), N) {
                while(1) {
                        while(!stk.empty()) stk.pop();
                        faild = 0;
                        for(i=1; i<=N; i++) {
                                scanf("%d", &arr[i]);
                                if(arr[i]==0) {
                                        faild = 1;
                                        break;
                                }
                        }
                        if(faild) break;
                        int cnt = 1;
                        for(i=1; i<=N; i++) {
                                stk.push(i);
                                while(!stk.empty() && stk.top()==arr[cnt]) {
                                        cnt++;
                                        stk.pop();
                                }
                        }
                        if(cnt==N+1) printf("Yes\n");
                        else printf("No\n");
                }
                printf("\n");
        }

        return 0;
}
