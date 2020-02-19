#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto False = [&]() {
    cout << "0==1\n";
    exit(0);
  };
  string s;
  cin >> s;
  int l = (int) s.size();
  s += '&';
  string sa = "";
  string sb = "";
  bool equal = true;
  bool former = true;
  vector<pair<int, int>> edges_a;
  vector<pair<int, int>> edges_b;
  map<string, int> mp;
  vector<string> inv;
  vector<bool> is_num;
  vector<int> pid;
  auto Idx = [&](const string& s) {
    auto it = mp.find(s);
    if (it != mp.end()) {
      return it->second;
    }
    int id = (int) inv.size();
    mp[s] = id;
    inv.push_back(s);
    is_num.push_back(s.back() >= '0' && s.back() <= '9');
    pid.push_back(id);
    return id;
  };
  for (int i = 0; i <= l; i++) {
    if (s[i] == '&') {
      int x = Idx(sa);
      int y = Idx(sb);
      if (equal) edges_a.emplace_back(x, y);
      else edges_b.emplace_back(x, y);
      sa.clear();
      sb.clear();
      former = true;
      ++i;
      continue;
    }
    if (s[i] == '!' || s[i] == '=') {
      former = false;
      equal = (s[i] == '=');
      ++i;
      continue;
    }
    if (former) sa += s[i];
    else sb += s[i];
  }
  function<int(int)> Get = [&](int v) {
    return v == pid[v] ? v : pid[v] = Get(pid[v]);
  };
  auto Unite = [&](int x, int y) {
    x = Get(x);
    y = Get(y);
    if (inv[x].size() < inv[y].size()) {
      is_num[x] = is_num[x] || is_num[y];
      pid[y] = x;
    } else {
      is_num[y] = is_num[y] || is_num[x];
      pid[x] = y;
    }
  };
  for (const auto& e : edges_a) {
    int x, y;
    tie(x, y) = e;
    x = Get(x);
    y = Get(y);
    if (x != y && is_num[x] && is_num[y]) {
      False();
    }
    Unite(x, y); 
  }
  for (const auto& e : edges_b) {
    int x, y;
    tie(x, y) = e;
    if (Get(x) == Get(y)) {
      False();
    }
  }
  bool first = true;
  auto Put = [&](int x, int y, const string& op) {
    if (!first) {
      cout << "&&";
    }
    first = false;
    cout << inv[x] << op << inv[y]; 
  };
  int n = (int) inv.size();
  for (int i = 0; i < n; i++) {
    int I = Get(i);
    if (I != i) {
      Put(I, i, "==");
    }
  }
  set<pair<int, int>> was;
  for (const auto& e : edges_b) {
    int x, y;
    tie(x, y) = e;
    x = Get(x);
    y = Get(y);
    if (x > y) {
      swap(x, y);
    }
    if (!(is_num[x] && is_num[y]) && was.emplace(x, y).second) {
      Put(x, y, "!=");
    }
  }
  if (first) {
    cout << "1==1";
  }
  cout << '\n';
  return 0;
}
