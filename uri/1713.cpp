#include <bits/stdc++.h>

using namespace std;

#define MOD 10000

struct Matrix{
    int m[100][100] = {};
    int n;
    Matrix(int _n) : n(_n) {}
};

Matrix mult(const Matrix &m1, const Matrix &m2)
{
    int n = m1.n;
    Matrix ans(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans.m[i][j] = (ans.m[i][j] + m1.m[i][k] * m2.m[k][j]) % MOD;
            }
        }
    }
    
    return ans;
}

Matrix id(int n)
{
    Matrix ans(n);
    for (int i = 0; i < n; i++) ans.m[i][i] = 1;
    return ans;
}

Matrix power(const Matrix &matrix, int n)
{
    if (n == 0) return id(matrix.n);
    if (n == 1) return matrix;
    
    Matrix m = power(mult(matrix, matrix), n/2);
    if (n % 2 == 0) return m;
    else return mult(matrix, m);
}

int main()
{
    int n, l, s, t;
    
    while (cin >> n) {
        cin >> l >> s >> t;
        Matrix m(n);
        for (int i = 0; i < n; i++) {
            int A, B, C, D;
            cin >> A >> B >> C >> D;
            m.m[i][A-1]++, m.m[i][B-1]++, m.m[i][C-1]++, m.m[i][D-1]++;
        }
    
        Matrix ans = power(m, l);
        printf("%d\n", ans.m[s-1][t-1]);
    }
    
    return 0;
}