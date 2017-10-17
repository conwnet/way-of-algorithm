#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 10000005;

bool vst[maxn];

struct ADT {
        int k, p;
        ADT(int a, int b):
                k(a), p(b) {}
        ADT() {}
        bool operator < (const ADT &B) const {
                return p < B.p;
        }
        bool operator > (const ADT &B) const {
                return p > B.p;
        }
};

priority_queue<ADT> maxq;
priority_queue<ADT, vector<ADT>, greater<ADT> > minq;

int main()
{
        int op, k, p;

        memset(vst, 0, sizeof(vst));
        while(scanf("%d", &op) && op) {
                if(op==1) {
                        scanf("%d%d", &k, &p);
                        maxq.push(ADT(k, p));
                        minq.push(ADT(k, p));
                        vst[p] = 0;
                } else if(op==2) {
                        if(maxq.empty()) { printf("0\n"); continue; }
                        int ok = 0;
                        while(!ok && !maxq.empty()) {
                                ADT t = maxq.top(); maxq.pop();
                                if(!vst[t.p]) {
                                        vst[t.p] = 1;
                                        printf("%d\n", t.k);
                                        ok = 1;
                                }
                        }
                        if(!ok) { printf("0\n"); continue; }
                } else {
                        if(minq.empty()) { printf("0\n"); continue; }
                        int ok = 0;
                        while(!ok && !minq.empty()) {
                                ADT t = minq.top(); minq.pop();
                                if(!vst[t.p]) {
                                        vst[t.p] = 1;
                                        printf("%d\n", t.k);
                                        ok = 1;
                                }
                        }
                        if(!ok) { printf("0\n"); continue; }
                }
        }

        return 0;
}

