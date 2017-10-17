

#include <stdio.h>

int main(){
	long long x, y, a, b, L, i, t1, t2, faild;

	while(~scanf("%lld%lld%lld%lld%lld", &x, &y, &a, &b, &L)){
		t1 = y-x;
		if(!t1){
			printf("0\n");
			continue;
		}
		t2 = 1;
		faild = 0;
		for(i=1; ; i++){
			t2 = a*i%L - b*i%L;
			if(t2==t1) break;
			if(!t2){
				faild = 1;
				break;
			}
		}
		if(faild) printf("Impossible\n");
		else printf("%Ild\n", i);
	}

	return 0;
}

