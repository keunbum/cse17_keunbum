#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
};

const int N = (int) 1e5;

bool was[N];
int dist[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<Edge> edges;
	while (n--) {
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
			int id = (int) edges.size();
			edges.push_back({x, y, z});
			g[x].push_back(id);
		}
	}
	auto RunDfs = [&](int root) {
		memset(was, false, sizeof(was));
		dist[root] = 0;
		pair<int, int> res = {-1, 0};
		function<void(int v)> Dfs = [&](int v) {
			was[v] = true;
			if (res.second < dist[v]) {
				res.second = dist[v];
				res.first = v;
			}
			for (int id : g[v]) {
				const Edge& e = edges[id];
				int to = e.to;
				if (!was[to]) {
					dist[to] = dist[v] + e.cost;
					Dfs(to);
				}
			}
		};
		Dfs(root);
		return res;
	};
	cout << RunDfs(RunDfs(0).first).second << '\n';
	return 0;
}
