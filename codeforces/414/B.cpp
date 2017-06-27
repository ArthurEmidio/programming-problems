#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    double n, h;
    cin >> n >> h;

    double totArea = h / 2.0;
    double each = totArea / n;

    double a1 = each;
    double a2 = totArea - each;

    double b = 1.0;

    stack<double> answers;
    for (int i = 0; i < n-1; i++) {
        double ans = (sqrt(b*b*h*h + 4*b*h*(a2 - a1) + 4*(a1 + a2)*(a1 + a2)) + b*h - 2*a1 - 2*a2) / (2.0 * b);
        answers.push(ans);

        b = (2.0 * a2) / ans;
        h = ans;
        a2 -= each;
    }

    while (!answers.empty()) {
        printf("%.10f ", answers.top());
        answers.pop();
    }
    printf("\n");

    return 0;
}
