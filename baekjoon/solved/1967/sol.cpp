#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
};

const int N = 10010;

int q[N];
int dist[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<Edge> edges;
	for (int i = 0; i < n - 1; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		int id = (int) edges.size();
		g[x].push_back(id);
		g[y].push_back(id);
		edges.push_back({x, y, z});
	}
	auto RunBfs = [&](int st) {
		const int INF = (int) 1e9;
		fill_n(dist, n, INF);
		dist[st] = 0;
		int b = 0, e = 1;
		q[0] = st;
		while (b < e) {
			int i = q[b];
			for (int id : g[i]) {
				const Edge& edge = edges[id];
				int to = edge.from ^ edge.to ^ i;
				if (dist[to] > dist[i] + edge.cost) {
					dist[to] = dist[i] + edge.cost;
					q[e] = to;
					++e;
				}
			}
			++b;
		}
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			if (dist[maxi] < dist[i]) {
				maxi = i;
			}
		}
		return make_pair(maxi, dist[maxi]);
	};
	cout << RunBfs(RunBfs(0).first).second << '\n';
	return 0;
}
