#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n + n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ok;
			cin >> ok;
			if (ok == 1) {
				int from = i + j;
				int to = i - j + n - 1;
				g[from].push_back(to);
			}
		}
	}
	int iter = 0;
	vector<int> pa(n + n - 1, -1);
	vector<int> pb(n + n - 1, -1);
	vector<int> was(n + n - 1, 0);
	function<bool(int)> Dfs = [&](int v) {
		was[v] = iter;
		for (int u : g[v]) {
			if (pb[u] == -1) {
				pa[v] = u;
				pb[u] = v;
				return true;
			}
		}
		for (int u : g[v]) {
			if (was[pb[u]] != iter && Dfs(pb[u])) {
				pa[v] = u;
				pb[u] = v;
				return true;
			}
		}
		return false;
	};
	int ans = 0;
	while (true) {
		iter++;
		int add = 0;
		for (int i = 0; i < n + n - 1; i++) {
			if (pa[i] == -1) {
				add += (int) Dfs(i);
			}
		}
		if (add == 0) {
			break;
		}
		ans += add;
	}
	cout << ans << '\n';
	return 0;
}
