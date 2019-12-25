#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = i + 1;
	}
	while (m--) {
		string s;
		cin >> s;
		if (s[0] >= '1' && s[0] <= '9') {
			cout << a[stoi(s) - 1] << '\n';
		} else {
			cout << mp[s] << '\n';
		}
	}
	return 0;
}
