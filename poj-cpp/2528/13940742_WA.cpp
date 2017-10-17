#include <stdio.h>
#include <map>

using namespace std;

int main(){
    multimap<int, int> mp;
    multimap<int, int>::iterator l, i, t;
    int nCase, N, L, R;
    scanf("%d", &nCase);
    while(nCase--){
        mp.clear();
        scanf("%d", &N);
        mp.insert(pair<int, int>(0, 0));
        scanf("%d%d", &L, &R);
        mp.insert(pair<int, int>(L, R));
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
            mp.insert(pair<int, int>(L, R));

        }
        printf("%d\n", mp.size()-1);
    }

    return 0;
}