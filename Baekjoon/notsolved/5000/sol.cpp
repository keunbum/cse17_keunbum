#include <iostream>
#include <algorithm>

using namespace std;

const int N = 123456;

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
    cout << a[i] << ' ';
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  
  return 0;
}