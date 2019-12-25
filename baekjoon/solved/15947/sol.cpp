#include <iostream>

using namespace std;

string a[] = { 
  "baby", "sukhwan", "tu", "tu",
  "very", "cute", "tu", "tu",
  "in", "bed", "tu", "tu",
  "baby", "sukhwan"
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int q = (n - 1) / 14;
  int r = (n - 1) % 14;
  int rr = r % 4;
  //cerr << "q = " << q << " r = " << r << " rr = " << rr << "  ";
  if (rr < 2) { cout << a[r] << '\n'; return 0; }
  cout << a[r];
  if (q - rr >= 1) {
    cout << "+ru*" + to_string(q - rr + 4);
  } else {
    for (int i = 0; i < q - rr + 4; i++) {
      cout << "ru";
    }
  }
  cout << '\n';
  return 0;
}