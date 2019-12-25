#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (int) s.size();
	string ans;
	for (int i = n - 1; i >= 0; i -= 3) {
		int foo = 0;
		for (int j = 2; j >= 0; j--) {
			if (i - j >= 0) {
				foo = foo * 2 + (s[i - j] - '0');
			}
		}
		ans.push_back(foo + '0');
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}
