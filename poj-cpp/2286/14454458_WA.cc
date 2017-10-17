#include <stdio.h>
#include <string.h>

int maps[8][8], ans[1024];

void rot_a()
{
	int i;
	int t = maps[0][2];
	for(i=0; i<6; i++)
		maps[i][2] = maps[i+1][2];
	maps[i][2] = t;
}

void rot_b()
{
	int i;
	int t = maps[0][4];
	for(i=0; i<6; i++)
		maps[i][4] = maps[i+1][4];
	maps[i][4] = t;
}

void rot_c()
{
	int i;
	int t = maps[2][6];
	for(i=6; i>0; i--)
		maps[2][i] = maps[2][i-1];
	maps[2][i] = t;
}

void rot_d()
{
	int i;
	int t = maps[4][6];
	for(i=6; i>0; i--)
		maps[4][i] = maps[4][i-1];
	maps[4][i] = t;
}

void rot_e()
{
	int i;
	int t = maps[6][4];
	for(i=6; i>0; i--)
		maps[i][4] = maps[i-1][4];
	maps[i][4] = t;
}

void rot_f()
{
	int i;
	int t = maps[6][2];
	for(i=6; i>0; i--)
		maps[i][2] = maps[i-1][2];
	maps[i][2] = t;
}

void rot_g()
{
	int i;
	int t = maps[4][0];
	for(i=0; i<6; i++)
		maps[4][i] = maps[4][i+1];
	maps[4][i] = t;
}

void rot_h()
{
	int i;
	int t = maps[2][0];
	for(i=0; i<6; i++)
		maps[2][i] = maps[2][i+1];
	maps[2][i] = t;
}

void rot_p(int n)
{
	switch(n) {
		case 0: rot_a(); break;
		case 1: rot_b(); break;
		case 2: rot_c(); break;
		case 3: rot_d(); break;
		case 4: rot_e(); break;
		case 5: rot_f(); break;
		case 6: rot_g(); break;
		case 7: rot_h(); break;
	}
}

void rot_n(int n)
{
	switch(n) {
		case 0: rot_f(); break;
		case 1: rot_e(); break;
		case 2: rot_h(); break;
		case 3: rot_g(); break;
		case 4: rot_b(); break;
		case 5: rot_a(); break;
		case 6: rot_d(); break;
		case 7: rot_c(); break;
	}
}

int is_ok()
{
	int n = maps[2][2];
	if(n!=maps[2][3]) return 0;
	if(n!=maps[2][4]) return 0;
	if(n!=maps[3][2]) return 0;
	if(n!=maps[3][4]) return 0;
	if(n!=maps[4][2]) return 0;
	if(n!=maps[4][3]) return 0;
	if(n!=maps[4][4]) return 0;
	return 1;
}

int dfs(int dep)
{
	if(is_ok()) return 1;
	if(dep==0) return 0;
	for(int i=0; i<8; i++) {
		rot_p(i);
		ans[dep] = i;
		if(dfs(dep-1)) return 1;
		rot_n(i);
	}
}

void print()
{
		for(int i=0; i<7; i++) {
			for(int j=0; j<7; j++)
				printf("%d ", maps[i][j]);
			printf("\n");
		}
}

int main()
{
	int dep;

	while(1) {
		memset(maps, 0, sizeof(maps));
		scanf("%d", &maps[0][2]);
		if(maps[0][2] == 0) break;
		scanf("%d", &maps[0][4]);
		scanf("%d", &maps[1][2]);
		scanf("%d", &maps[1][4]);
		for(int i=0; i<7; i++)
			scanf("%d", &maps[2][i]);
		scanf("%d", &maps[3][2]);
		scanf("%d", &maps[3][4]);
		for(int i=0; i<7; i++)
			scanf("%d", &maps[4][i]);
		scanf("%d", &maps[5][2]);
		scanf("%d", &maps[5][4]);
		scanf("%d", &maps[6][2]);
		scanf("%d", &maps[6][4]);
		for(dep=0; dep<10; dep++)
			if(dfs(dep)) break;
		//print();
		if(dep>0)
			for(int i=dep; i>0; i--)
				printf("%c", ans[i]+'A');
		else if(dep==10) printf("no");
		else printf("No moves needed");
		printf("\n%d\n", maps[2][2]);
	}


	return 0;
}












