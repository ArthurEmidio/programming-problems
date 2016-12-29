#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007

struct Matrix
{
	ll m[100][100] = {};
	int n;
	Matrix(int _n) : n(_n) {}
};

Matrix id(int n)
{
	Matrix ans(n);
	for (int i = 0; i < n; i++) ans.m[i][i] = 1;
	return ans;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
	Matrix ans(m1.n);
	for (int i = 0; i < m1.n; i++) {
		for (int j = 0; j < m1.n; j++) {
			for (int k = 0; k < m1.n; k++) ans.m[i][j] = (ans.m[i][j] + m1.m[i][k]*m2.m[k][j]) % MOD;
		}
	}
	return ans;
}

Matrix pow(const Matrix &m, int n)
{
	if (n == 0) return id(m.n);
	if (n == 1) return m * id(m.n);
	
	Matrix mat = pow(m * m, n/2);
	if (n % 2 == 0) return mat;
	else return m * mat;
}

class ModEquationEasy
{
public:
	int count(int n, int K, int v)
	{
		Matrix mat(K);
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				int x = (i*j) % K;
				mat.m[i][x]++;
			}
		}
		
		Matrix res = pow(mat, n-1);
		ll ans = 0;
		for (int i = 0; i < K; i++) ans = (ans + res.m[i][v]) % MOD;
		
		return ans;
	}
};