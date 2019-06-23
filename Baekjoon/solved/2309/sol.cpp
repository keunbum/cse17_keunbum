#include <bits/stdc++.h>

using namespace std;

vector<int> a(9);

int main() {
  int i, j, sum = 0;
  for (i = 0; i < 9; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum -= 100;
  bool found = false;
  for (i = 0; i < 8; i++)
    for (j = i+1; j < 9; j++) {
      if (a[i] + a[j] == sum) {
        a[i] = 100;
        a[j] = 100;
        found = true;
        break;
      }
      if (found)
        break;
    }
  sort(a.begin(), a.end());
  for (i = 0; i < 7; i++)
    cout << a[i] << '\n';
  return 0;
}