#include <bits/stdc++.h>

using namespace std;

class SwapAndArithmetic
{
public:
	string able(vector<int> x)
	{
		sort(x.begin(), x.end());
		int d = x[1] - x[0];
		
		bool ans = true;
		for (int i = 1; i < x.size() && ans; i++) {
			if (x[i] - x[i-1] != d) ans = false;
		}
		
		return ans ? "Possible" : "Impossible";
	}
};