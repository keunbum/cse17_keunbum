#include <iostream>

using namespace std;

const int N = 123456;

bool chk[N];
int a[N], b[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[a[i] - 1];
  }
  int p = n;
  for (int i = 0; i < n; i++) {
    if (chk[i]) continue;
    p--;
    for (int j = i; !chk[j]; j = b[j] - 1) {
      chk[j] = true;
    }
  }
  cout << (p & 1 ? "Imp" : "P") << "ossible" << '\n';
  return 0;
}
