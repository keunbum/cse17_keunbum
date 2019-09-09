#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<int, int>> b;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) {
			b.back().second++;
		} else {
			b.emplace_back(a[i], 1);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int low = 0;
		int high = (int) b.size() - 1;
		int mid;
		bool ok = false;
		while (low <= high) {
			mid = (low + high + 1) >> 1;
			if (b[mid].first == x) {
				ok = true;
				break;
			}
			if (b[mid].first < x) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		if (i > 0) {
			cout << ' ';
		}
		cout << (ok ? b[mid].second : 0);
	}
	cout << '\n';
	return 0;
}
