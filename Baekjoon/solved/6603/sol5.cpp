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
		vector<int> v;
		function<void(int)> Dfs = [&](int pos) {
			if ((int) v.size() == 6) {
				for (int i = 0; i < 6; i++) {
					if (i > 0) {
						cout << ' ';
					}
					cout << v[i];
				}
				cout << '\n';
				return;
			}
			for (int i = pos; i < k; i++) {
				v.push_back(a[i]);
				Dfs(i + 1);
				v.pop_back();
			}
		};
		Dfs(0);
		cout << '\n';
	}
	return 0;
}
