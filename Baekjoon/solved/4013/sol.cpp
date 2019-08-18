#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g_t(n);
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g_t[x].push_back(y);
	}
	vector<int> val(n);
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	int S;
	cin >> S;
	S--;
	vector<int> q;
	q.push_back(S);
	vector<bool> was(n, false);
	was[S] = true;
	for (int i = 0; i < (int) q.size(); i++) {
		int v = q[i];
		for (int u : g_t[v]) {
			if (!was[u]) {
				was[u] = true;
				q.push_back(u);
			}
		}
	}
	vector<vector<int>> g(n), g_rev(n);
	for (int i = 0; i < n; i++) {
		if (was[i]) {
			for (int u : g_t[i]) {
				if (was[u]) {
					g[i].push_back(u);
					g_rev[u].push_back(i);
				}
			}
		}
	}
	vector<int> order;
	function<void(int)> Dfs1 = [&](int v) {
		was[v] = true;
		for (int u : g[v]) {
			if (!was[u]) {
				Dfs1(u);
			}
		}
		order.push_back(v);
	};
	fill(was.begin(), was.end(), false);
	Dfs1(S);
	int cnt = 0;
	vector<int> c(n, -1);
	function<void(int)> Dfs2 = [&](int v) {
		for (int u : g_rev[v]) {
			if (c[u] == -1) {
				c[u] = c[v];
				Dfs2(u);
			}
		}
	};
	for (int i = order.size() - 1; i >= 0; i--) {
		int v = order[i];
		if (c[v] == -1) {
			c[v] = cnt++;
			Dfs2(v);
		}
	}
	vector<vector<int>> c_g(n);
	vector<int> deg(n, 0);
	vector<int> c_val(n, 0);
	for (int i = 0; i < n; i++) {
		if (c[i] == -1) {
			continue;
		}
		c_val[c[i]] += val[i];
		for (int u : g[i]) {
			if (c[i] != c[u]) {
				c_g[c[i]].push_back(c[u]);
				deg[c[u]]++;
			}
		}
	}
	q.clear();
	for (int i = 0; i < cnt; i++) {
		if (deg[i] == 0) {
			q.push_back(i);
		}
	}
	vector<int> dp(cnt, 0);
	int ans = 0;
	for (int i = 0; i < (int) q.size(); i++) {
		int v = q[i];
		for (int u : c_g[v]) {
			dp[u] = max(dp[v] + c_val[v], dp[u]);
			if (--deg[u] == 0) {
				q.push_back(u);
			}
		}
	}
	int P;
	cin >> P;
	while (P--) {
		int x;
		cin >> x;
		x--;
		if (c[x] != -1) {
			ans = max(ans, dp[c[x]] + c_val[c[x]]);
		}
	}
	return !printf("%d\n", ans);
}
