#include <bits/stdc++.h>

using namespace std;

long long getDiff(long long n)
{
    string s = to_string(n);
    int q = 0;
    for (char c : s) q += (c - '0');
    return n - q;
}

int main()
{
    long long n, s;
    cin >> n >> s;

    long long left = 1;
    long long right = n + 1;

    while (left < right) {
        long long mid = (left + right) / 2;
        if (getDiff(mid) >= s) right = mid;
        else left = mid + 1;
    }

    cout << n - left + 1 << endl;

    return 0;
}
