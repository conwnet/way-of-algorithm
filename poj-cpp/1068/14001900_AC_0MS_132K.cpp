#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
        int seq[100];
        int i, j, t, n, m, cnt, v[100], rzt[100], tt;

//        seq.clear();
        scanf("%d", &t);
        while(t--){
                scanf("%d", &n);
                cnt = 0;
                int l = 0;
                for(i=0; i<n; i++){
                        scanf("%d", &m);
                        while(cnt<m){
                                seq[l++] = 0;
                                cnt++;
                        }
                        seq[l++] = 1;
                }
                memset(v, 0, sizeof(v));
                int t = 0;
                for(i=0; i<l; i++){
                        if(seq[i]==1){
                                for(j=i, cnt=0, tt=0; j>=0; j--){
                                        if(seq[j]==1) tt++;
                                        if(!v[j] && seq[j]==0){
                                                v[j] = 1;
                                                break;
                                        }
                                }
                                rzt[t++] = tt;
                        }
                }
                printf("%d", rzt[0]);
                for(i=1; i<t; i++){
                        printf(" %d", rzt[i]);
                }
                printf("\n");
        }

        return 0;
}
