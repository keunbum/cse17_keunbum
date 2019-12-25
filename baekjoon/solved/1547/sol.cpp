#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int v[] = { 0, 1, 2, 3 };
  int inv[] = { 0, 1, 2, 3 };
  while (n--) {
    int a, b;
    cin >> a >> b;
    swap(v[inv[a]], v[inv[b]]);
    swap(inv[a], inv[b]);
  }
  cout << v[1] << '\n';
  return 0;
}