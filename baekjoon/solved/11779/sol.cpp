#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n));
	vector<Edge> edges;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		int id = (int) edges.size();
		g[x].push_back(id);
		edges.push_back({x, y, z});
	}
	int start, end;
	cin >> start >> end;
	start--; end--;
	vector<int> p(n, -1);
	auto Dijkstra = [&]() {
		const int INF = (int) 1e9;
		vector<int> dist(n, INF);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
		dist[start] = 0;
		s.emplace(dist[start], start);
		while (!s.empty()) {
			int expected, i;
			tie(expected, i) = s.top();
			s.pop();
			if (expected != dist[i]) {
				continue;
			}
			for (int id : g[i]) {
				const Edge& e = edges[id];
				int to = e.to;
				if (dist[to] > dist[i] + e.cost) {
					p[to] = i;
					dist[to] = dist[i] + e.cost;
					s.emplace(dist[to], to);
				}
			}
		}
		return dist;
	};
	auto dist = Dijkstra();
	cout << dist[end] << '\n';
	int x = end;
	vector<int> res;
	while (x != -1) {
		res.push_back(x);
		x = p[x];
	}
	int sz = (int) res.size();
	cout << sz << '\n';
	for (int i = sz - 1; i >= 0; i--) {
		if (i < sz - 1) {
			cout << ' ';
		}
		cout << res[i] + 1;
	}
	cout << '\n';
	return 0;
}
