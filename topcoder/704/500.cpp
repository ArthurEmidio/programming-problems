#include <bits/stdc++.h>

using namespace std;

class ConnectedComponentConstruction
{
public:
	vector<string> construct(vector<int> s)
	{
		int n = s.size();
		map<int,vector<int>> v;
		for (int i = 0; i < n; i++) v[s[i]].push_back(i);
		
		vector<string> ans(n, string(n, 'N'));
		
		for (const pair<int,vector<int>> &p : v) {
			int cmpSize = p.first;
			const vector<int> &vertices = p.second;
			
			if (vertices.size() % cmpSize != 0) return vector<string>();
			
			int qnt = vertices.size() / cmpSize;
			int j = 0;
			for (int i = 0; i < qnt; i++) {
				for (int k = 0; k < cmpSize-1; k++, j++) {
					ans[vertices[j]][vertices[j+1]] = 'Y';
					ans[vertices[j+1]][vertices[j]] = 'Y';
				}
				j++;
			}
		}
		
		return ans;
	}
};