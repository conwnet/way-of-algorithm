#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef vector<vector<int> > Mat;

Mat mat_mul(Mat &a, Mat &b, int m)
{
        Mat c;
        c.resize(a.size());
        for(int i=0; i<a.size(); i++) {
                c[i].resize(b[0].size());
                for(int j=0; j<b[0].size(); j++) {
                        c[i][j] = 0;
                        for(int k=0; k<a.size(); k++) {
                                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
                        }
                }
        }
        return c;
}

Mat mat_pow(Mat &a, int n, int m)
{
        Mat c;
        c.resize(a.size());
        for(int i=0; i<a.size(); i++) {
                c[i].resize(a.size());
                c[i][i] = 1;
        }
        if(!n) return c;
        c = mat_pow(a, n>>1, m);
        c = mat_mul(c, c, m);
        if(n&1) c = mat_mul(c, a, m);
        return c;
}

void print(Mat a)
{
        for(int i=0; i<a.size(); i++) {
                for(int j=0; j<a[0].size(); j++)
                        printf("%d ", a[i][j]);
                printf("\n");
        }
}

Mat mat, tmp, ans, t;

int main()
{
        int n, m, k;
        scanf("%d%d%d", &n, &k, &m);
        mat.resize(n*2);
        t.resize(n*2);
        for(int i=0; i<n*2; i++) {
                mat[i].resize(n*2);
                t.resize(n*2);
                if(i<n) {
                        for(int j=0; j<n; j++)
                                scanf("%d", &mat[i][j]);
                        for(int j=n; j<n*2; j++)
                                mat[i][j] = 0;
                } else {
                        mat[i][i-n] = 1;
                        mat[i][i] = 1;
                }
        }
        tmp.resize(n*2);
        ans.resize(n*2);
        for(int i=0; i<n*2; i++) {
                tmp[i].resize(n);
                ans[i].resize(n);
                if(i<n) tmp[i][i] = 1;
        }
        t = mat_pow(mat, k+1, m);
        ans = mat_mul(t, tmp, m);
        for(int i=n; i<n*2; i++)
                ans[i][i-n] = (ans[i][i-n]+m-1)%m;
        for(int i=n; i<n*2; i++) {
                printf("%d", ans[i][0]);
                for(int j=1; j<n; j++)
                        printf(" %d", ans[i][j]);
                printf("\n");
        }

        return 0;
}
