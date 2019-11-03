#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = (int) 1e9;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> tree(n + n - 1);
	function<void(int, int, int)> Build = [&](int x, int l, int r) {
		if (l == r) {
			tree[x] = a[l];
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		Build(x + 1, l, y);
		Build(z, y + 1, r);
		tree[x] = min(tree[x + 1], tree[z]);
	};
	Build(0, 0, n - 1);
	function<int(int, int, int, int, int)> Get = [&](int x, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
			return tree[x];
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		int res = inf;
		if (rr <= y) {
			res = Get(x + 1, l, y, ll, rr);
		} else
		if (ll > y) {
			res = Get(z, y + 1, r, ll, rr);
		} else {
			res = min(Get(x + 1, l, y, ll, rr), Get(z, y + 1, r, ll, rr));
		}
		return res;
	};
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << Get(0, 0, n - 1, x, y) << '\n';
	}
	return 0;
}
