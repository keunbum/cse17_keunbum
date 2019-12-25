#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4;

int q[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[y].push_back(x);
	}
	vector<int> was(n, -1), val(n);
	int mx = 1;
	for (int i = 0; i < n; i++) {
		int beg = 0, end = 1;
		q[0] = i;
		was[i] = i;
		while (beg < end) {
			int cur = q[beg];
			for (int to : g[cur]) {
				if (was[to] != i) {
					was[to] = i;
					q[end++] = to;
				}
			}
			beg++;
		}
		val[i] = end;
		mx = max(mx, end);
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (mx == val[i]) {
			ans.push_back(i);
		}
	}
	int sz = (int) ans.size();
	for (int i = 0; i < sz; i++) {
		cout << ans[i] + 1 << (i < sz - 1 ? ' ' : '\n');
	}
	return 0;
}
