#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 51;
	char s[N];
	cin >> s;
	int p = -2;
	function<int(char)> F = [&](char e) {
		p += 2;
		int res = 0;
		while (s[p] != e) {
			if (s[p + 1] != '(') {
				res++;
			} else {
				res += (s[p] - '0') * F(')');
			}
			p++;
		}
		return res;
	};
	cout << F(0) << '\n';
	return 0;
}
