#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[10], t;
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    cin >> t;
    cnt += a[i] > t ? 1 : a[i] < t ? -1 : 0;
  }
  cout << (cnt == 0 ? 'D' : (cnt > 0 ? 'A' : 'B')) << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
