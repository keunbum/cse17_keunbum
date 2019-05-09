#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string con[4];
int prob[4][4][3];

inline int getn(string s) {
  for (int i = 0; i < 4; i++) {
    if (con[i] == s) return i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string con[4];
  for (int i = 0; i < 4; i++) {
    cin >> con[i];
  }
  for (int i = 0; i < 6; i++) {
    string foo, bar;
    cin >> foo >> bar;
    int a = getn(foo), b = getn(bar);
    for (int j = 0; j < 3; j++) {
      cin >> prob[a][b][j];
      prob[b][a][2 - j] = prob[a][b][j];
    }
  }
  vector<double> ans(4, 0.);
  for (int i = 0; i < 729; i++) {
    int b[4] = {0, 0, 1, 1};
    do {
    
    } while (next_permutation(b, b + 4));
    }
  return 0;
}