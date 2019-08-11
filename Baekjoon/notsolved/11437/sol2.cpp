#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<vector<int>> r(2 * n + 1, vector<int>(20));
	for (int i = 0; i < 20; i++) {
		r[1][i] = 1;
	}
	vector<int> depth(2 * n + 1);
	function<void(int)> Dfs = [&](int v){
		for (int u : g[v]) {
			if (u != r[v][0]) {
				r[u][0] = v;
				depth[u] = depth[v] + 1;
				for (int i = 1; i < 20; i++) {
					r[u][i] = r[r[u][i - 1]][i - 1];
				}
				Dfs(u);
			}
		}
	};
	Dfs(1);
	auto Anc = [&](int x, int d) {
		for (int i = 0; i < 20; i++) {
			if (d & (1 << i)) {
				x = r[x][i];
			}
		}
		return x;
	};
	auto GetLca = [&](int x, int y) {
		if (depth[x] > depth[y]) {
			swap(x, y);
		}
		y = Anc(y, depth[y] - depth[x]);
		if (x == y) {
			return x;
		}
		for (int i = 19; i >= 0; i--) {
			if (r[x][i] != r[y][i]) {
				x = r[x][i];
				y = r[y][i];
			}
		}
		return r[x][0];
	};
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << GetLca(x, y) << '\n';
	}
	return 0;
}
