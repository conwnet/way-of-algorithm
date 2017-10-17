
#include <stdio.h>


int gcd(int a, int b){
	if(!b) return a;
	else return gcd(b, a%b);
}

int lcm(int a, int b){
	return a*b/gcd(a, b);
}


int main(){
	long long x, y, a, b, L, n, i;

	while(~scanf("%d%d%d%d%d", &x, &y, &a, &b, &L)){

				x %= L;  y %= L;  a %= L;  b %= L;
				
				n = lcm(L/gcd(L, a), L/gcd(L, b));
				for(i=1; i<=n; i++){
					if( (x+a*i)%L == (y+b*i)%L ) break;
				}
				if(i==n+1) printf("Impossible\n");
				else printf("%d\n", i);

			}

	return 0;
}