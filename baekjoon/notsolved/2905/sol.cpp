#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = -x;
	}
	vector<int> tree(n + n - 1);
	function<void(int, int, int, vector<int>& a)> Build = [&](int x, int l, int r, vector<int>& a) {
		if (l == r) {
			tree[x] = a[l];
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		Build(x + 1, l, y, a);
		Build(z, y + 1, r, a);
		tree[x] = max(tree[x + 1], tree[z]);
	};
	Build(0, 0, n - 1, a);
	vector<int> b(n, 0);
	function<int(int, int, int, int, int)> Get = [&](int x, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
			return tree[x];
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		int res;
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
	for (int i = 0; i + w - 1 < n; i++) {
		b[i] = -Get(0, 0, n - 1, i, i + w - 1);
	}
	Build(0, 0, n - 1, b);
	long long ans1 = 0;
	int ans2 = 0;
	int pre = 0;
	int oki = -1;
	for (int i = 0; i < n; i++) {
		int cur = Get(0, 0, n - 1, max(0, i - w + 1), i);
		ans1 += -a[i] - cur;
		if (cur != pre || i > oki) {
			ans2++;
			oki = i + w - 1;
			pre = cur;
		}
	}
	cout << ans1 << '\n' << ans2 << '\n';
//	cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
	return 0;
}
