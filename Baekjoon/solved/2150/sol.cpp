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
	vector<int> c(n, -1);
	function<void(int)> Dfs2 = [&](int v) {
		for (int u : g_rev[v]) {
			if (c[u] == -1) {
				c[u] = c[v];
				Dfs2(u);
			}
		}
	};
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		int v = order[i];
		if (c[v] == -1) {
			c[v] = cnt++;
			Dfs2(v);
		}
	}
	vector<vector<int>> ans(cnt);
	for (int i = 0; i < n; i++) {
		ans[c[i]].push_back(i);
	}
	for (int i = 0; i < cnt; i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		for (int x : ans[i]) {
			cout << x + 1 << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}
