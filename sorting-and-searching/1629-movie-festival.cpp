#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> times(n);
  for (int i = 0; i != n; ++i) {
    cin >> times[i].first >> times[i].second;
  }
  sort(begin(times), end(times), [](pair<int, int>& a, pair<int, int>& b) {
    if (a.second < b.second)
      return true;
    if (a.second == b.second and a.first < b.first)
      return true;
    return false;
  });
 
  int res = 0;
  int cur_e = -1;
  for (int i = 0; i < n; ++i) {
    if (cur_e <= times[i].first) {
      cur_e = times[i].second;
      ++res;
    }
  }
 
  cout << res << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  //cin >> t;
  t = 1;
  while (t--) {
      solve();
  }
 
  return 0;
}
