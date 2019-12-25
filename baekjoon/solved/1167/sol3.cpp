#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;

bool was[N];
int dist[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		while (true) {
			int y;
			cin >> y;
			if (y == -1) {
				break;
			}
			y--;
			int z;
			cin >> z;
			g[x].emplace_back(y, z);
		}
	}
	function<void(int)> Dfs = [&](int v) {
		was[v] = true;
		for (auto &e : g[v]) {
			int to = e.first;
			int cost = e.second;
			if (!was[to]) {
				dist[to] = dist[v] + cost;
				Dfs(to);
			}
		}
	};
	int s = 0;
	Dfs(s);
	for (int i = 1; i < n; i++) {
		if (dist[s] < dist[i]) {
			s = i;
		}
	}
	memset(was, false, sizeof(was));
	dist[s] = 0;
	Dfs(s);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dist[i]);
	}
	cout << ans << '\n';
	return 0;
}
