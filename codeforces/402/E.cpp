#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

enum oper {NONE, XOR, AND, OR};

struct var
{
    string num;
    int op1, op2;
    oper oper = NONE;
};

int n, m;
vector<var> vars;

bool g(bool op1, bool op2, oper operat)
{
    switch (operat) {
        case XOR: return op1 ^ op2;
        case AND: return op1 & op2;
        case OR: return op1 | op2;
        default: return 0;
    }
    return 0;
}

int f(char bit, int i)
{
    bool bits[5005];
    bits[n] = (bit == '1');

    for (int j = 0; j < n; j++) {
        const var &v = vars[j];
        if (v.oper == NONE) bits[j] = v.num[i] == '1';
        else bits[j] = g(bits[v.op1], bits[v.op2], v.oper);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans += bits[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    map<string, int> varsMap;
    varsMap["?"] = n;

    for (int i = 0; i < n; i++) {
        var v;
        string name, as, op1;
        cin >> name >> as >> op1;
        if (!isdigit(op1[0])) {
            string oper;
            cin >> oper;
            if (oper == "XOR") v.oper = XOR;
            else if (oper == "OR") v.oper = OR;
            else v.oper = AND;

            string op2;
            cin >> op2;
            v.op1 = varsMap[op1];
            v.op2 = varsMap[op2];
        } else v.num = op1;

        varsMap[name] = i;
        vars.push_back(v);
    }

    string ans1, ans2;
    for (int i = 0; i < m; i++) {
        int w0 = f('0', i);
        int w1 = f('1', i);
        ans1 += w0 <= w1 ? '0' : '1';
        ans2 += w0 >= w1 ? '0' : '1';
    }

    cout << ans1 << endl << ans2 << endl;

    return 0;
}
