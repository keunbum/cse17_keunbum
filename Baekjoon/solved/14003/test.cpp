#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;
const int INF = (int) 2e9;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  fill(a, a + n, -INF);
  while (n--) {
    int x;
    cin >> x;
    *lower_bound(a, a + cnt, x) = x;
    cnt += (int) (a[cnt] > -INF);
  }
  cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << a[i];
	}
	cout << '\n';
  return 0;
}
