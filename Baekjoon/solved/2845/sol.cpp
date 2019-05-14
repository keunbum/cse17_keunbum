#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int p, a;
  cin >> p >> a;
  for (int i = 0; i < 5; i++) {
    int t;
    cin >> t;
    cout << t - p * a << ' ';
  }
  cout << '\n';
  return 0;
}