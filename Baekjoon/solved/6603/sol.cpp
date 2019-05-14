#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (true) {
    int a[12];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    set<vector<int>> s;
    for (int t = 0; t < (1 << n); t++) {
      vector<int> v;
      for (int i = 0; i < n; i++) {
        if (t & (1 << i)) v.push_back(a[i]);
      }
      if ((int) v.size() == 6) { s.insert(v); }
    }
    for (auto it = s.begin(); it != s.end(); it++) {
      for (int i = 0; i < 6; i++) {          
        cout << (*it)[i] << (i < 5 ? ' ' : '\n');
      }
    }                                      
    cin >> n;
    if (n) { cout << '\n'; }
    else { break; }
  }
  return 0;
}