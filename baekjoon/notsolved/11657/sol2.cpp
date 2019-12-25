#include <bits/stdc++.h>

using namespace std;

const int N = 500;

struct Edge {
	int to;
	int cost;
};

int q[N * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int INF = (int) 1e9;
	int n, m;
	cin >> n >> m;
	vector<vector<Edge>> g(n);
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		g[x].push_back({y, z});
	}
	vector<int> dist(n, INF);
	dist[0] = 0;
	int b = 0, e = 0;
	q[e++] = 0;
	vector<bool> was(n, false);
	was[0] = true;
	vector<int> cnt(n, 0);
	while (b < e) {
		int v = q[b];
		was[v] = false;
		cnt[v]++;
		if (cnt[v] >= n) {
			cout << -1 << '\n';
			return 0;
		}
		for (Edge& E : g[v]) {
			if (dist[E.to] > dist[v] + E.cost) {
				dist[E.to] = dist[v] + E.cost;
				if (!was[E.to]) {
					was[E.to] = true;
					q[e++] = E.to;
				}
			}
		}
		b++;
	}
	for (int i = 1; i < n; i++) {
		cout << (dist[i] < INF ? dist[i] : -1) << '\n';
	}
	return 0;
}
