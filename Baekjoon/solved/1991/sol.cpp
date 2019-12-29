#include <bits/stdc++.h>

using namespace std;

char tree[128][2];

void Dfs(char v, int order) {
  if (v == '.') return;
  int j = 0;
  for (int i = 0; i < 3; i++) {
    if (i == order) cout << v;
    else Dfs(tree[v][j++], order);
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  char x, y, z;
	  cin >> x >> y >> z;
	  tree[x][0] = y;
	  tree[x][1] = z;
	}
	for (int i = 0; i < 3; i++) {
	  Dfs('A', i);
	  cout << '\n';
	}
	return 0;
}
