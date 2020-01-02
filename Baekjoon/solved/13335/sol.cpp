#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int a[N];
int q[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, w;
  cin >> n >> l >> w;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int passed = 0;
  int time = 0;
  int sum = 0;
  int b = 0, e = 0;
  int i = 0;
  while (passed < n) {
    if (b < e && time - q[b] == l) {
      sum -= a[passed++];
      ++b;
    }
    if (i < n && sum + a[i] <= w) {
      sum += a[i++];
      q[e++] = time;
    }
    time++;
  }
  cout << time << '\n';
  return 0;
}
