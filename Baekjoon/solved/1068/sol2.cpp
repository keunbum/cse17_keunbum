#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int root = -1;
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == -1) {
			root = i;
		} else {
			g[p].push_back(i);
		}
	}
	int del;
	cin >> del;
	int ans = 0;
	function<void(int)> Dfs = [&](int v) {
		int cnt = 0;
		for (int u : g[v]) {
			if (u != del) {
				cnt++;
				Dfs(u);
			}
		}
		if (cnt == 0) {
			ans++;
		}
	};
	if (root != del) {
		Dfs(root);
	}
	cout << ans << '\n';
	return 0;
}
