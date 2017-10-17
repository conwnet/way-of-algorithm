#include <stdio.h>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    map<int, int>::iterator l, i, t;
    int nCase, N, L, R;
    scanf("%d", &nCase);
    while(nCase--){
        mp.clear();
        scanf("%d", &N);
        mp[0] = 0;
        scanf("%d%d", &L, &R);
        mp[L] = R;
        N--;
        while(N--){
            scanf("%d%d", &L, &R);
            l = mp.lower_bound(L);
            for( ; l!=mp.end(); l++){

                if((l->second)<=R){
                    t = l--;
                    mp.erase(t);
                }


            }
            mp[L] = R;

        }
        printf("%d\n", mp.size()-1);
    }

    return 0;
}