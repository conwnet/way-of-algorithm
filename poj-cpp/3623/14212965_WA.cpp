#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char str[2048], N;
vector<char> s;

int main()
{
        int i, j, l, r, tl, tr;

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                getchar();
                str[i] = getchar();
        }
        l = 0;
        r = N-1;
        while(l<r) {
                if(str[l]<str[r]) {
                        s.push_back(str[l]);
                        l++;
                } else if(str[l]>str[r]) {
                        s.push_back(str[r]);
                        r--;
                } else {
                        tl = l; tr = r;
                        while(str[tl]==str[tr]) { tl++; tr--; }
                        if(str[tl]<str[tr]) {
                                s.push_back(str[l]);
                                l++;
                        } else {
                                s.push_back(str[r]);
                                r--;
                        }
                }

        }
        s.push_back(str[l]);
        for(i=0; i<s.size(); i++) {
              //  if(i!=0 && i%80==0) putchar('\n');
                putchar(s[i]);
        }

        return 0;
}
