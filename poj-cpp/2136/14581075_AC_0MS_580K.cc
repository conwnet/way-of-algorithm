#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26];

void print();

int main()
{
        int i, c;

        memset(arr, 0, sizeof(arr));
        while((c=getchar())!=EOF) {
                //if(c=='~') break;
                if(c<='Z' && c>='A') arr[c-'A']++;
        }
        print();

        return 0;
}

int cmp(int a, int b)
{
        return arr[a]<arr[b];
}

vector<int> G[1024];

void print()
{
        int max_n = 0;
        for(int i=0; i<26; i++)
                max_n = max(arr[i], max_n);
        for(int i=max_n; i>0; i--) {
                for(int j=0; j<26; j++) {
                        if(arr[j]>=i)
                                G[i].push_back(j);
                }
        }
        for(int i=1; i<=max_n; i++)
                sort(G[i].begin(), G[i].end());
        for(int i=max_n; i>0; i--) {
                if(!G[i][0]) putchar('*');
                else putchar(' ');
                for(int j=1; j<=G[i][G[i].size()-1]; j++) {
                        int k;
                        for(k=0; k<G[i].size(); k++) {
                                if(G[i][k]==j) break;
                        }
                        if(k!=G[i].size()) printf(" *");
                        else printf("  ");
                }
                putchar('\n');
        }
        putchar('A');
        for(int i=1; i<26; i++)
                printf(" %c", 'A'+i);
}
