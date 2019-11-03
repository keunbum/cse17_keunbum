#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	const int MAX = 1 << (32 - __builtin_clz(n - 1) + 1);
	vector<long long> tree(MAX);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	function<void(int, int, int)> Build = [&](int x, int l, int r) {
		if (l == r) {
			tree[x] = a[l];
			return;
		}
		int y = (l + r) >> 1;
		Build(x + x, l, y);
		Build(x + x + 1, y + 1, r);
		tree[x] = tree[x + x] + tree[x + x + 1];
	};
	Build(1, 0, n - 1);
	m += k;
	function<void(int, int, int, int, int)> Modify = [&](int x, int l, int r, int pos, int v) {
		if (l == r) {
			tree[x] += v;
			return;
		}
		int y = (l + r) >> 1;
		if (pos <= y) {
			Modify(x + x, l, y, pos, v);
		} else {
			Modify(x + x + 1, y + 1, r, pos, v);
		}
		tree[x] = tree[x + x] + tree[x + x + 1];
	};
	function<long long(int, int, int, int, int)> Get = [&](int x, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
			return tree[x];
		}
		int y = (l + r) >> 1;
		long long res = 0L;
		if (rr <= y) {
			res = Get(x + x, l, y, ll, rr);
		} else
		if (ll > y) {
			res = Get(x + x + 1, y + 1, r, ll, rr);
		} else {
			res = Get(x + x, l, y, ll, rr) + Get(x + x + 1, y + 1, r, ll, rr);
		}
		return res;
	};
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		y--;
		if (x & 1) {
			Modify(1, 0, n - 1, y, z - a[y]);
			a[y] = z;
		} else {
			z--;
			cout << Get(1, 0, n - 1, y, z) << '\n';
		}
	}
	return 0;
}
