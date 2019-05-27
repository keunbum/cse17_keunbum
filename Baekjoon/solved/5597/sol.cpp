#include <iostream>

using namespace std;

bool a[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 28; i++) {
    int t;
    cin >> t;
    a[t] = true;
  }
  for (int i = 1; i <= 30; i++) {
    if (!a[i]) cout << i << '\n';
  }
  return 0;
}