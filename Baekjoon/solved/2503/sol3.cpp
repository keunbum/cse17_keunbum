#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<bool> ans(1000, true);
	while (n--) {
		string s;
		cin >> s;
		int st, ba;
		cin >> st >> ba;
		for (int i = 100; i <= 999; i++) {
			string t = to_string(i);
			if ((t[0] == t[1] || t[1] == t[2] || t[0] == t[2]) || (t[1] == '0' || t[2] == '0')) {
				ans[i] = false;
				continue;
			}
			int m_st = 0;
			int m_ba = 0;
			for (int j = 0; j < 3; j++) {
				if (s[j] == t[j]) {
					m_st++;
				}
				for (int k = 0; k < 3; k++) {
					if (j != k && s[j] == t[k]) {
						m_ba++;
					}
				}
			}
			if (st != m_st || ba != m_ba) {
				ans[i] = false;
			}
		}
	}
	int ans_n = 0;
	for (int i = 100; i <= 999; i++) {
		if (ans[i]) {
			ans_n++;
			//cerr << i << '\n';
		}
	}
	cout << ans_n << '\n';
	return 0;
}
