#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (getline(cin, s)) {
    char c;
    int n = s.length();
    if (n == 1) break;
    vector<char> a;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      c = s[i];
      int l = a.size() - 1;                     
      if (c == '(' || c == '[') a.push_back(c); else                                    
      if (c == ')') {                           
        if (l >= 0 && a[l] == '(') a.pop_back();
        else {
          ok = false;                        
          break;
        }
      } else                                    
      if (c == ']') {                           
        if (l >= 0 && a[l] == '[') a.pop_back();
        else {
          ok = false;                        
          break;
        }
      }                                         
    } 
    if (a.size() != 0) ok = false;
    cout << (ok ? "yes" : "no") << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}