#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = (int) 1e9;
	int n, m;
	cin >> n >> m;
	const int MAX = 1 << (32 - __builtin_clz(n - 1));
	vector<int> tree(n + MAX);
	auto Modify = [&](int x, int v) {
		x += MAX - 1;
		tree[x] = v;
		while (x > 1) {
			x >>= 1;
			tree[x] = min(tree[x + x], tree[x + x + 1]);
		}
	};
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		Modify(i, x); 
	}
	auto Get = [&](int x, int y) {
		int v = inf;
		x += MAX - 1;
		y += MAX - 1;
		while (x <= y) {
			if ((x & 1) == 1) {
				v = min(v, tree[x++]);
			}
			if ((y & 1) == 0) {
				v = min(v, tree[y--]);
			}
			x >>= 1;
			y >>= 1;
		}
		return v;
	};
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << Get(x, y) << '\n';
	}
	return 0;
}
