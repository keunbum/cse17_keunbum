#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e6;

long long q[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	map<long long, int> mp;
	map<long long, long long> p;
	int b = 0, e = 1;
	q[0] = n;
	mp[n] = 0;
	p[n] = 0;
	while (b < e) {
//    cerr << q[b] << '\n';
	  if (q[b] == 1) {
	    break;
	  }
    if (q[b] + 1 <= n + n && mp.count(q[b] + 1) == 0) {
      q[e] = q[b] + 1;
      mp[q[e]] = mp[q[b]] + 1;
      ++e;
    }
    if (q[b] - 1 > 0 && mp.count(q[b] - 1) == 0) {
      q[e] = q[b] - 1;
      mp[q[e]] = mp[q[b]] + 1;
      ++e;
    }
    long long r;
    if (Get(q[b], r)) {
      // Oh.. shiit...
    }
	  ++b;
	}
  /*
	cerr << "start" << '\n';
	int pp = n;
	while (pp > 0) {
	  cout << pp << '\n';
	  pp = p[pp];
	}
	cerr << "end" << '\n';
  */
	cout << mp[1] << '\n';
	return 0;
}
