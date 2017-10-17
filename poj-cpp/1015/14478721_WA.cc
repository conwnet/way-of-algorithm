#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct ADT {
	int a, b, r;
};

bool cmp(ADT A, ADT B)
{
	return A.a-A.b < B.a-B.b;
}

ADT arr[300];
int N, M;

int main()
{
	int ss, tt, nCase = 0;

	while(scanf("%d%d", &N, &M)) {
		if(N==0 && M==0) break;
		for(int i=0; i<N; i++) {
			scanf("%d%d", &arr[i].a, &arr[i].b);
			arr[i].r = i+1;
		}
		sort(arr, arr+N, cmp);
		int ans = 1<<30;
		int cnt = -1;
		int s = 0; int t = M-1;
		for(; t<N; s++, t++) {
			int sum = 0;
			int S = 0;
			for(int i=s; i<=t; i++) {
				sum += abs(arr[i].a-arr[i].b);
				S += arr[i].a + arr[i].b;
			}
			if(sum < ans) {
				ans = sum;
				ss = s;
				tt = t;
				cnt = S;
			} else if(sum == ans && S > cnt) {
				ss = s;
				tt = t;
				cnt = S;
			}
		}
		int sa = 0;
		int sb = 0;
		for(int i=ss; i<=tt; i++) {
			sa += arr[i].a;
			sb += arr[i].b;
		}
		printf("Jury #%d\n", ++nCase);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", sa, sb);
		for(int i=ss; i<=tt; i++) printf(" %d", arr[i].r);
		printf("\n\n");
	}
	
	return 0;
}