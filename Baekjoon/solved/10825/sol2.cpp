#include <bits/stdc++.h>

using namespace std;

struct St {
	int x, y, z;
	string s;
	bool operator<(St& o) {
		if (x != o.x) return x > o.x;
		if (y != o.y) return y < o.y;
		if (z != o.z) return z > o.z;
		return s < o.s;
	}
} a[123456];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int x, y, z;
		cin >> s >> x >> y >> z;
		a[i] = {x, y, z, s};
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout << a[i].s << '\n';
	}
	return 0;
}
