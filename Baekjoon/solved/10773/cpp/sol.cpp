#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  vector<int> a;
  while (k--) {
    int n;
    cin >> n;
    if (n) a.push_back(n);
    else a.pop_back();
  }
  int sum = 0;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  cout << sum << '\n';
  return 0;
}
