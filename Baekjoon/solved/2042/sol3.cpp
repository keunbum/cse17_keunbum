#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> fenw(n);
	auto Modify = [&](int x, long long v) {
		while (x < n) {
			fenw[x] += v;
			x |= (x + 1);
		}
	};
	auto Get = [&](int x) {
		long long v = 0;
		while (~x) {
			v += fenw[x];
			x = (x & (x + 1)) - 1;
		}
		return v;
	};
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {	
		cin >> a[i];
		Modify(i, a[i]);
	}
	m += k;
	while (m--) {
		int x, y;
		cin >> x >> y;
		y--;
		if (x & 1) {
			long long z;
			cin >> z;
			Modify(y, z - a[y]);
			a[y] = z;
		} else {
			int z;
			cin >> z;
			z--;
			cout << Get(z) - Get(y - 1) << '\n';
		}
	}
	return 0;
}
