#include <bits/stdc++.h>

using namespace std;

struct Node {
  long long value = 0;
  long long add = 0;
  void apply(int l, int r, long long v) {
    value += (r - l + 1) * v;
    add += v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<Node> tree(2 * n - 1);
  auto Unite = [&](const Node& a, const Node& b) {
    Node res{};
    res.value = a.value + b.value;
    return res;
  };
  auto Push = [&](int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  };
  auto Pull = [&](int x, int z) {
    tree[x] = Unite(tree[x + 1], tree[z]);
  };
  function<void(int, int, int, const vector<long long>& v)> Build = [&](int x, int l, int r, const vector<long long>& v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    Build(x + 1, l, y, v);
    Build(z, y + 1, r, v);
    Pull(x, z);
  };
  Build(0, 0, n - 1, a);
  function<Node(int, int, int, int, int)> Get = [&](int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    Push(x, l, r);
    Node res{};
    if (rr <= y) {
      res = Get(x + 1, l, y, ll, rr);
    } else
    if (ll > y) {
      res = Get(z, y + 1, r, ll, rr);
    } else {
      res = Unite(Get(x + 1, l, y, ll, rr), Get(z, y + 1, r, ll, rr));
    }
    Pull(x, z);
    return res;
  };
  function<void(int, int, int, int, int, long long)> Modify = [&](int x, int l, int r, int ll, int rr, long long v) {
//    cerr << "Modify(" << x << ", " << l << ", " << r << ", " << ll << ", " << rr << ", " << v << ")" << '\n';
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
//    cerr << "y = " << y << " z = " << z << '\n';
    Push(x, l, r);
    if (ll <= y) {
      Modify(x + 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      Modify(z, y + 1, r, ll, rr, v);
    }
    Pull(x, z);
  };
  auto Debug = [&]() {
    for (int i = 0; i < 2 * n - 1; i++) {
      cerr << i << ": " << "value = " << tree[i].value << " add = " << tree[i].add << '\n';
    }
    cerr << '\n';
  };
//  cerr << "Init" << '\n';
//  Debug();
  for (int i = 0; i < m + k; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    y--; z--;
    if (x & 1) {
//      cerr << "Modified" << '\n';
      long long w;
      cin >> w;
      Modify(0, 0, n - 1, y, z, w);
    } else {
//      cerr << "Get" << '\n';
      Node ans = Get(0, 0, n - 1, y, z);
      cout << ans.value << '\n'; 
    }
//    Debug();
  }
  return 0;
}
