#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> a(4, vector<bool>(8));
int b[4]; // 12 o'clock index
bool spined[4];

void rotate(int s, int d) {
  spined[s] = true;
  if (s - 1 >= 0 && !spined[s - 1] && a[s - 1][(b[s - 1] + 2) % 8] ^ a[s][(b[s] + 6) % 8]) rotate(s - 1, -d);
  if (s + 1 <= 3 && !spined[s + 1] && a[s + 1][(b[s + 1] + 6) % 8] ^ a[s][(b[s] + 2) % 8]) rotate(s + 1, -d);
  b[s] = (b[s] - d + 8) % 8;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char t;
  int k;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> t;
      a[i][j] = t - '0' ? true : false;
    }
  }
  cin >> k;
  while (k--) {
    for (int i = 0; i < 4; i++)
      spined[i] = false;
    int s, d;
    cin >> s >> d;
    rotate(--s, d);
  }
  cout << a[0][b[0]] + 2 * a[1][b[1]] + 4 * a[2][b[2]] + 8 * a[3][b[3]] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
