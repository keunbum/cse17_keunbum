#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n), g_rev(n);
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g_rev[y].push_back(x);
	}
	vector<int> order;
	vector<bool> was(n, false);
	function<void(int)> Dfs1 = [&](int v) {
		was[v] = true;
		for (int u : g[v]) {
			if (!was[u]) {
				Dfs1(u);
			}
		}
		order.push_back(v);
	};
	for (int i = 0; i < n; i++) {
		if (!was[i]) {
			Dfs1(i);
		}
	}
	fill(was.begin(), was.end(), false);
	vector<vector<int>> ans;
	function<void(int)> Dfs2 = [&](int v) {
		was[v] = true;
		for (int u : g_rev[v]) {
			if (!was[u]) {
				ans.back().push_back(u);
				Dfs2(u);
			}
		}
	};
	for (int i = n - 1; i >= 0; i--) {
		int v = order[i];
		if (!was[v]) {
			ans.push_back(vector<int>(1, v));
			Dfs2(v);
		}
	}
	for (auto& s : ans) {
		sort(s.begin(), s.end());
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& s : ans) {
		for (int x : s) {
			cout << x + 1 << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}
