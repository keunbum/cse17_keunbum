#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}
		vector<int> a(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		vector<vector<int>> ans;
		for (int tt = 0; tt < (1 << k); tt++) {
			vector<int> b;
			for (int i = 0; i < k; i++) {
				if (tt & (1 << i)) {
					b.push_back(a[i]);
				}
			}
			if ((int) b.size() == 6) {
				ans.push_back(b);
			}
		}
		sort(ans.begin(), ans.end());
		for (auto& x : ans) {
			for (int i = 0; i < 6; i++) {
				if (i > 0) {
					cout << ' ';
				}
				cout << x[i];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
