#include <bits/stdc++.h>

using namespace std;

int a[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		bool ok = false;
		for (int j = 0; j < n; j++) {
			if (x == i) {
				ok = true;
				break;
			}
			x = a[x];
		}
		if (ok) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << '\n';
	}
	return 0;
}
