#include <iostream>
#include <algorithm>

using namespace std;

const int inf = (int) 1e9;

int a[20][20];
bool b[20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  int ans = inf;
  for (int i = n / 2; i < n; i++) {
    b[i] = true;
  }
  do {
   int s[2] = {0, 0};
   for (int i = 0; i < n; i++) {
     for (int j = i + 1; j < n; j++) {
       s[b[i]] += (!(b[i] ^ b[j])) * (a[i][j] + a[j][i]);
     }
   }
   ans = min(ans, abs(s[0] - s[1])); 
  } while (next_permutation(b, b + n));
  cout << ans << '\n';
  return 0;
}
