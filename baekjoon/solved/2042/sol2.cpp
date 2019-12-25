#include <bits/stdc++.h>

using namespace std;

struct Node {
	long long x;
	void apply(int l, int r, int v) {
		x = v;
	};
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<Node> tree(2 * n - 1);
	auto Unite = [&](const Node& a, const Node& b) {
		Node res;
		res.x = a.x + b.x;
		return res;
	};
	auto Pull = [&](int x, int z) {
		tree[x] = Unite(tree[x + 1], tree[z]);
	};
	function<void(int, int, int, const vector<int>&)> Build = [&](int x, int l, int r, const vector<int>& v) {
		if (l == r) {
			tree[x].apply(l, r, v[l]);
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		Build(x + 1, l, y, v);
		Build(z, y + 1, r, v);
		Pull(x, z);
	};
	Build(0, 0, n - 1, a);
	function<void(int, int, int, int, int, int)> Modify = [&](int x, int l, int r, int ll, int rr, int v) {
		if (ll <= l && r <= rr) {
			tree[x].apply(l, r, v);
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
		Pull(x, z);
	};
	function<Node(int, int, int, int, int)> Get = [&](int x, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
			return tree[x];
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		Node res{};
		if (rr <= y) {
			res = Get(x + 1, l, y, ll, rr);
		} else
		if (ll > y) {
			res = Get(z, y + 1, r, ll, rr);
		} else {
			res = Unite(Get(x + 1, l, y, ll, rr), Get(z, y + 1, r, ll, rr));
		}
		return res;
	};
	for (int i = 0; i < m + k; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x & 1) {
			y--;
			Modify(0, 0, n - 1, y, y, z);
		} else {
			y--; z--;
			if (y > z) {
				swap(y, z);
			}
			Node ans = Get(0, 0, n - 1, y, z);
			cout << ans.x << '\n';
		}
	}
  return 0;
}
