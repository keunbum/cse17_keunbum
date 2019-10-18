#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int INF = (int) 1e9;
	int n;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
	vector<int> dist(n + 1, INF);
	dist[1] = 0;
	s.emplace(dist[1], 1);
	vector<int> p(n + 1);
	while (!s.empty()) {
		int i, expected;
		tie(expected, i) = s.top();
		s.pop();
		if (dist[i] != expected) {
			continue;
		}
		auto Get = [&](int x, int y) {
			if (y == 0) return x + 1;
			return x * (y + 1);
		};
		for (int j = 0; j < 3; j++) {
			int u = Get(i, j);
			if (u <= n && dist[u] > dist[i] + 1) {
				dist[u] = dist[i] + 1;
				s.emplace(dist[u], u);
				p[u] = i;
			}
		}
	}
	cout << dist[n] << '\n';
	while (n != 1) {
		cout << n << ' ';
		n = p[n];
	}
	cout << 1 << '\n';
	return 0;
}
