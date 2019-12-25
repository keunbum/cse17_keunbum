#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> who(n);
	vector<int> delta(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> who[i] >> delta[i];
		mp[who[i]] += delta[i];
	}
	int mx = 0;
	for (auto x : mp) {
		mx = max(mx, x.second);
	}
	set<string> possible;
	for (auto x : mp) {
		if (x.second == mx) {
			possible.insert(x.first);
		}
	}
	mp.clear();
	string ans;
	for (int i = 0; i < n; i++) {
		mp[who[i]] += delta[i];
		if (possible.count(who[i]) && mp[who[i]] >= mx) {
			ans = who[i];
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
