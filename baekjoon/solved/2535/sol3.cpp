#include <iostream>
#include <algorithm>

using namespace std;

int cnt[100];

struct St {
  int con, st, score;
} a[100];

struct Cmp {
  bool operator()(const St &a, const St &b) const { return a.score > b.score; }
} cmp;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].con >> a[i].st >> a[i].score;
  }
  sort(a, a + n, cmp);
  for (int i = 0, k = 1; i < n && k < 4; i++) {
    if (cnt[a[i].con]++ >= 2) continue;
    cout << a[i].con << ' ' << a[i].st << '\n';
    k++;
  }
  return 0;
}