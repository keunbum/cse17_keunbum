#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> mp;
  vector<pair<string, int>> record;
  for (int i = 0; i < n; i++) {
		string who;
		int score;
		cin >> who >> score;
		mp[who] += score;
		record.emplace_back(who, mp[who]);
	}
	int mx = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second > mx) {
			mx = it->second;
		}
	}
	set<string> s;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second == mx) {
			s.insert(it->first);
		}
	}
	for (int i = 0; i < n; i++) {
		if (s.count(record[i].first) && record[i].second >= mx) {
			cout << record[i].first << '\n';
			return 0;
		}
	}
	assert(0);
  return 0;
}
