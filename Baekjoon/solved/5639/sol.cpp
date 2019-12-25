#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int MAX = (int) 1e6;
	int x;
	vector<int> a;
	while (cin >> x) {
		a.push_back(x);
	}
	int n = (int) a.size();
	if (n == 0) {
		return 0;
	}
	vector<int> l(MAX, -1);
	vector<int> r(MAX, -1);
	function<void(int, int)> Push = [&](int pv, int cv) {
		if (pv > cv) {
			if (l[pv] != -1) Push(l[pv], cv);
			else l[pv] = cv;
		} else {
			if (r[pv] != -1) Push(r[pv], cv);
			else r[pv] = cv;
		}
	};
	for (int i = 1; i < n; i++) {
		Push(a[0], a[i]);
	}
	function<void(int)> Print = [&](int v) {
		if (l[v] != -1) Print(l[v]);
		if (r[v] != -1) Print(r[v]);
		cout << v << '\n';
	};
	Print(a[0]);
	return 0;
}
