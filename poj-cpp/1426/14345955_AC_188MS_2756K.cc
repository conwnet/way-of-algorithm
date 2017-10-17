#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int> P;

void print(int n)
{
        if(n/2) print(n/2);
        printf("%d", n%2);
}

int main()
{
        queue<P> Q;
        int M;

        while(scanf("%d", &M) && M) {
                while(!Q.empty()) Q.pop();
                Q.push(P(1, 1));
                while(!Q.empty()) {
                        int n = Q.front().first;
                        int num = Q.front().second;
                        Q.pop();
                        if(n%M==0) {
                                print(num);
                                printf("\n");
                                break;
                        }
                        Q.push(P((n%M)*10+1, (num<<1)+1));
                        Q.push(P((n%M)*10, num<<1));
                }
        }

        return 0;
}
