#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, string> P;

int way[200], M;

int main()
{
        queue<P> Q;

        while(scanf("%d", &M) && M) {
      ///  for(M=1; M<300; M++) {
                while(!Q.empty()) Q.pop();
                Q.push(P(1, "1"));
                while(!Q.empty()) {
                        int n = Q.front().first;
                        string num = Q.front().second;
                        Q.pop();
                        if(n%M==0) {
                                printf("%s\n", num.c_str());
                                break;
                        }
                        Q.push(P((n%M)*10+1, num+"1"));
                        Q.push(P((n%M)*10, num+"0"));
                }
               /// printf("")
        }

        return 0;
}
