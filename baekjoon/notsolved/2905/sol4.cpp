#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = (int) 1e6;
	int n, w;
	cin >> n >> w;
	vector<int> tree(n + n - 1, -inf);
	function<void(int, int, int, int, int, int)> Modify = [&](int x, int l, int r, int ll, int rr, int v) {
		if (ll <= l && r <= rr) {
			tree[x] = max(tree[x], v);
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		if (ll <= y) {
			Modify(x + 1, l, y, ll, rr, v);
		}
		if (rr > y) {
			Modify(z, y + 1, r, ll, rr, v);
		}
		tree[x] = max(tree[x + 1], tree[z]);
	};
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = -x;
		Modify(0, 0, n - 1, i, i, a[i]);
	}
	function<int(int, int, int, int, int)> Get = [&](int x, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
			return tree[x];
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		int res = 0;
		if (rr <= y) {
			res = Get(x + 1, l, y, ll, rr);
		} else
		if (ll > y) {
			res = Get(z, y + 1, r, ll, rr);
		} else {
			res = max(Get(x + 1, l, y, ll, rr), Get(z, y + 1, r, ll, rr));
		}
		return res;
	};
	vector<int> b(n);
	for (int i = 0; i < n - w + 1; i++) {
		b[i] = -Get(0, 0, n - 1, i, i + w - 1);
		Modify(0, 0, n - 1, i, i, b[i]);
	}
	long long ans1 = 0;
	int ans2 = 0;
	int pre = 0;
	int oki = -1;
	for (int i = 0; i < n; i++) {
		int cur = Get(0, 0, n - 1, max(0, i - w + 1), min(i, n - w + 1));
		ans1 += -a[i] - cur;
		if (cur != pre || oki < i) {
			ans2++;
			pre = cur;
			oki = i + w - 1;
		}
	}
	cout << ans1 << '\n' << ans2 << '\n';
//	cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
	return 0;
}
