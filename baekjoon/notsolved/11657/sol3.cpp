#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int INF = (int) 1e9;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>(n, INF));
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		adj[x][y] = min(adj[x][y], z);
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (adj[i][k] == INF) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (adj[0][i] < INF && adj[i][i] < 0) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for (int i = 1; i < n; i++) {
		cout << (adj[0][i] < INF ? adj[0][i] : -1) << '\n';
	}
	return 0;
}
