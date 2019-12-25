#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto Build = [&](int i, int e, vector<int>& b) {
		b.push_back(0);
		while (i < e) {
			int sz = (int) b.size();
			for (int j = 0; j < sz; j++) {
				b.push_back(b[j] + a[i]);
			}
			i++;
		}
		sort(b.begin(), b.end());
	};
	int m = n >> 1;
	vector<int> u, v;
	Build(0, m, u);
	Build(m, n, v);
	auto Merge = [](vector<int>& A, vector<pair<int, long long>>& B) {
		int b = 0;
		int e = (int) A.size();
		for (int i = 0; i < e; i++) {
			if (i + 1 == e || A[i + 1] != A[b]) {
				B.emplace_back(A[b], i - b + 1);
				b = i + 1;
			}
		}
	};
	vector<pair<int, long long>> U, V;
	Merge(u, U);
	Merge(v, V);
	auto Cnt = [&]() {
		long long res = 0;
		int pa = 0, e = U.size(), pb = V.size() - 1;
		while (pa < e && pb >= 0) {
			int cur = U[pa].first + V[pb].first;
			if (cur == s) {
				res += U[pa].second * V[pb].second;
				pa++; pb--;
			} else
			if (cur > s) pb--;
			else pa++;
		}
		return res;
	};
	long long ans = Cnt();
	cout << (ans - (int) (s == 0)) << '\n';
	return 0;
}
