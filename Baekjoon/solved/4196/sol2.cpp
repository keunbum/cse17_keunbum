#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> p(n);
		iota(p.begin(), p.end(), 0);
		function<int(int)> GetId = [&](int v) {
			return v == p[v] ? v : p[v] = GetId(p[v]);
		};
		vector<bool> chk(n, false);
		while (m--) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			chk[y] = true;
			p[GetId(x)] = GetId(y);
		}
		vector<vector<int>> des(n);
		for (int i = 0; i < n; i++) {
			des[GetId(i)].push_back(i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (des[i].empty()) {
				continue;
			}
			int cnt = 0;
			for (int c : des[i]) {
				if (!chk[c]) {
					cnt++;
				}
			}
			ans += max(1, cnt);
		}
		cout << ans << '\n';
	}
	return 0;
}
