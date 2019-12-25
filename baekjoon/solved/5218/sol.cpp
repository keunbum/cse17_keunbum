#include <iostream>

using namespace std;

inline int dis(char b, char a) {
  a -= b;
  if (a < 0) a += 26;
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cout << "Distances:";
    string foo, bar;
    cin >> foo >> bar;
    int n = (int) foo.size();
    for (int i = 0; i < n; i++) {
      cout << ' ' << dis(foo[i], bar[i]); 
    }
    cout << '\n';
  }
  return 0;
}