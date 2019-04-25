#include <iostream>
#include <deque>

using namespace std;

deque<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;   
  while (n--) {
    string cmd;
    cin >> cmd;
    char c = cmd[0];
    switch (c) {
      case 'p':
        int v;
        if (cmd[1] == 'u') {
          cin >> v;
          if (cmd[5] == 'f') a.push_front(v);
          else a.push_back(v);
        }
        else {
          if (cmd[4] == 'f') {
            if (!a.empty()) { v = a.front(); a.pop_front(); }
            else v = -1;
            cout << v << '\n';
          } else {
            if (!a.empty()) { v = a.back(); a.pop_back(); }
            else v = -1;                                     
            cout << v << '\n';                               
          }
        }
        break;
      case 's':
        cout << a.size() << '\n';
        break;
      case 'e':
        cout << (a.empty() ? 1 : 0) << '\n';
        break;
      case 'f':
        cout << (a.empty() ? -1 : a.front()) << '\n';
        break;
      case 'b':
        cout << (a.empty() ? -1 : a.back()) << '\n';
        break;
      default:
        break;
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
