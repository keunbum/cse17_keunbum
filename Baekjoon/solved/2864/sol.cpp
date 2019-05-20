#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Min = [&](int n) {
    string s(to_string(n));
    for (char &c : s) {
      if (c == '6') c--;
    }
    return stoi(s);
  };
  auto Max = [&](int n) {
    string s(to_string(n));
    for (char &c : s) {
      if (c == '5') c++;
    }
    return stoi(s);
  };
  int a, b;
  cin >> a >> b;
  cout << Min(a) + Min(b) << ' ' << Max(a) + Max(b) << '\n';
  return 0;
}