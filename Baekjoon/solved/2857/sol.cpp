#include <iostream>

using namespace std;

bool ok;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= 5; i++) {
    string s;
    cin >> s;
    if (s.find("FBI") != string::npos) {
      ok = true;
      cout << i << ' ';
    }
  }
  if (!ok) cout << "HE GOT AWAY!" << '\n';
  return 0;
}