#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, w;
	getline(cin, s);
	getline(cin, w);
	int n = (int) w.size();
	vector<int> p(n, 0);
  // p[i] is the length of the longest of the substrings that
  // can be prefix == suffix among the substrings from 0 to i of the given string.
	int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(w[i] == w[k])) {
      k = p[k - 1];
    }
    if (w[i] == w[k]) {
      k++;
    }
    p[i] = k;
  }
	vector<int> ans;
	k = 0;
	int m = (int) s.size();
	for (int i = 0; i < m; i++) {
		while (k > 0 && (k == n || s[i] != w[k])) {
			k = p[k - 1];
		}
		if (s[i] == w[k]) {
			k++;
		}
		if (k == n) {
			ans.push_back(i - n + 1);
		}
	}
	n = (int) ans.size();
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << '\n';
	}
	return 0;
}

