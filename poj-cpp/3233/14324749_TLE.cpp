#include <stdio.h>
#include <string.h>

struct Matr {
        int mat[35][35];
        int N;
        void init(int n) {
                N = n;
                for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++)
                                scanf("%d", &mat[i][j]);
                }
        }
        Matr(){
                N = 0;
                memset(mat, 0, sizeof(mat));
        }
        Matr operator * (const Matr& B) {
                Matr C;
                C.N = B.N;
                for(int i=0; i<N; i++) {
                        for(int j=0; j<N; j++) {
                                for(int k=0; k<N; k++) {
                                        C.mat[i][j] += mat[i][k] * B.mat[k][j];
                                }
                        }
                }
                return C;
        }
        Matr operator + (const Matr& B) {
                Matr C;
                C.N = B.N;
                for(int i=0; i<C.N; i++) {
                        for(int j=0; j<C.N; j++) {
                                C.mat[i][j] = mat[i][j] + B.mat[i][j];
                        }
                }
                return C;
        }
        void MOD(int n)
        {
                for(int i=0; i<N; i++) {
                        for(int j=0; j<N; j++) {
                                mat[i][j] %= n;
                        }
                }
        }
        Matr power(int n, int m) {
                Matr C;
                for(int i=0; i<N; i++) {
                                C.mat[i][i] = 1;
                }
                C.N = N;
                if(n/2) {
                        C = power(n/2, m);
                        C = C * C;
                }
                if(n&1) C = C * (*this);
                C.MOD(m);
                return C;
        }
        void print()
        {
                for(int i=0; i<N; i++) {
                        printf("%d", mat[i][0]);
                        for(int j=1; j<N; j++) {
                                printf(" %d", mat[i][j]);
                        }
                        printf("\n");
                }
        }
};

int main()
{
        int n, k, m;
        Matr A, B;

        scanf("%d%d%d", &n, &k, &m);
        A.init(n);
        for(int i=1; i<=k; i++) {
                B = B + A.power(i, 100);
                B.MOD(m);
        }
        B.print();

        return 0;
}
