#include <iostream>
#include <algorithm>

using namespace std;

struct Ball {
  int i;
  int color;
  int size;
};

bool comps(const Ball &a, const Ball &b) {
  return a.size < b.size;
}

const int N = (int) 2e5 + 1;

Ball a[N];
int ans[N], csum[N], tsum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    a[i].i = i;
    cin >> a[i].color >> a[i].size;
  }
  sort(a, a + n, comps);
  for (int i = 0, e = i; i < n; i = e) {
    while (e < n && a[e].size == a[i].size)
      e++;
    for (int j = i; j < e; j++) {
      ans[a[j].i] = tsum - csum[a[j].color];
    }
    for (int j = i; j < e; j++) {
      tsum += a[j].size;
      csum[a[j].color] += a[j].size;
    }
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
