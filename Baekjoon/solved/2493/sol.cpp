#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n + 1, 0), stk;
  for (int i = n; i > 0; i--) {
    while (!stk.empty() && a[i] > a[stk.back()]) {  
      ans[stk.back()] = i;                       
      stk.pop_back();                                
    }
    stk.push_back(i);                                                
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}