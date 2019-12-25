#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = (int) 1e6;
	int n, w;
	cin >> n >> w;
	vector<int> fenw1(n, -inf), fenw2(n, -inf);
	auto Modify = [&](int _x, int v) {
		int x = _x;
		while (x < n) {
			fenw1[x] = max(fenw1[x], v);
			x |= (x + 1);
		}
		x = _x;
		while (~x) {
			fenw2[x] = max(fenw2[x], v);
			x = (x & (x + 1)) - 1;
		}
	}; // update max
	auto Get = [&](int x, int y, vector<int>& a) {
		int v = -inf;
		int pa = x;
		int pb = (pa | (pa + 1));
		while (pb <= y) {
			v = max(v, fenw2[pa]);
			pa = pb;
			pb = (pa | (pa + 1));
		}
		v = max(v, a[pa]);
		pa = y;
		pb = (pa & (pa + 1)) - 1;
		while (pb >= x) {
			v = max(v, fenw1[pa]);
			pa = pb;
			pb = (pa & (pa + 1)) - 1;
		}
		return v;
	}; // get max
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = -x;
		Modify(i, a[i]);
	}
	vector<int> b(n);
	for (int i = 0; i < n - w + 1; i++) {
		b[i] = -Get(i, i + w - 1, a);
		Modify(i, b[i]);
	}
	long long ans1 = 0;
	int ans2 = 0;
	int pre = 0;
	int oki = -1;
	for (int i = 0; i < n; i++) {
		int cur = Get(max(0, i - w + 1), min(n - w, i), b);
		ans1 += -a[i] - cur;
		if (cur != pre || oki < i) {
			ans2++;
			pre = cur;
			oki = i + w - 1;
		}
	}
	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}
