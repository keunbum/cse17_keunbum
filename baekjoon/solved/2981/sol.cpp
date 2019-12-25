#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int G = 0;
  for (int i = 1; i < n; i++) {
    G = __gcd(G, abs(a[i] - a[i - 1]));
  }
  vector<int> ans;
  for (int i = 2; i * i <= G; i++) {
    if (G % i == 0) {
      ans.push_back(i);
      if (i != G / i) ans.push_back(G / i);
    }
  }
  ans.push_back(G);
  sort(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << ' ';
  }  
  return 0;
}