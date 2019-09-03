#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int MAX_X = (int) 3e4;
	const int MAX_LEAF = 1 << ((int) log2(MAX_X) + 1);
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> a(MAX_X + 1), b(MAX_X + 1);
	for (int i = 0; i < n; i++) {
		int xa, ya, xb, yb;
		cin >> xa >> ya >> xb >> yb;
		yb--;
		a[xa].emplace_back(ya, yb);
		b[xb].emplace_back(ya, yb);
	}
	vector<int> val(2 * MAX_LEAF, 0), add(2 * MAX_LEAF, 0);
	function<void(int, int, int, int, int, int)> Modify = [&](int x, int l, int r, int ll, int rr, int v) {
		if (ll <= l && r <= rr) {
			add[x] += v;
			return;
		}
		int y = (l + r) >> 1;
		if (ll <= y) {
			Modify(x + x, l, y, ll, rr, v);
		}
		if (rr > y) {
			Modify(x + x + 1, y + 1, r, ll, rr, v);
		}
		val[x] = 0;
		val[x] += add[x + x] > 0 ? y - l + 1 : val[x + x];
		val[x] += add[x + x + 1] > 0 ? r - y : val[x + x + 1];
	};
	int ans = 0;
	for (int i = 0; i < MAX_X; i++) {
		for (auto &e : a[i]) {
			Modify(1, 0, MAX_LEAF, e.first, e.second, 1);
		}
		for (auto &e : b[i]) {
			Modify(1, 0, MAX_LEAF, e.first, e.second, -1);
		}
		ans += val[1];
	}
	cout << ans << '\n';
	return 0;
}	
