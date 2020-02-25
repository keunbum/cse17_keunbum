#include <iostream>
#include <algorithm>

using namespace std;

int a[9];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = (int) -1e9;
  do {
    int sum = 0;                  
    for (int i = 0; i < n - 1; i++) { 
      sum += abs(a[i] - a[i + 1]); 
    }
    ans = max(ans, sum);
  } while (next_permutation(a, a + n));
  cout << ans << '\n';
  return 0;
}