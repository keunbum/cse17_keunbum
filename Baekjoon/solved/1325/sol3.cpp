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
		g[y].push_back(x);
		g_rev[x].push_back(y);
	}
	vector<int> order;
	vector<bool> was(n, false);
	function<void(int)> Dfs1 = [&](int v) {
		was[v] = true;
		for (int to : g[v]) {
			if (!was[to]) {
				Dfs1(to);
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
	int cnt = 0;
	function<void(int)> Dfs2 = [&](int v) {
		for (int to : g_rev[v]) {
			if (c[to] == -1) {
				c[to] = c[v];
				Dfs2(to);
			}
		}
	};
	for (int t = n - 1; t >= 0; t--) {
		int i = order[t];
		if (c[i] == -1) {
			c[i] = cnt++;
			Dfs2(i);
		}
	}
	vector<int> dp(cnt, 0);
	vector<vector<int>> g_c(cnt);
	for (int i = 0; i < n; i++) {
		dp[c[i]]++;
		for (int to : g[i]) {
			if (c[i] != c[to]) {
				g_c[c[i]].push_back(c[to]);
			}
		}
	}
	int iter;
	vector<int> rnd(n, -1);
	function<int(int)> Dfs3 = [&](int v) {
		rnd[v] = iter;
		int res = dp[v];
		for (int to : g_c[v]) {
			if (rnd[to] != iter) {
				res += Dfs3(to);
			}
		}
		return res;
	};
	int mx = 1;
	vector<int> val(n);
	for (int i = 0; i < cnt; i++) {
		rnd[i] = iter = i;
		val[i] = Dfs3(i);
		mx = max(mx, val[i]);
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (mx == val[c[i]]) {
			ans.push_back(i);
		}
	}
	int sz = (int) ans.size();
	for (int i = 0; i < sz; i++) {
		cout << ans[i] + 1 << (i < sz - 1 ? ' ' : '\n');
	}
	return 0;
}
