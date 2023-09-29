#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> tasks(n);
  for (int i = 0; i != n; ++i) {
    cin >> tasks[i].first >> tasks[i].second;
  }
  sort(begin(tasks), end(tasks));

  int64_t res = 0;
  int64_t elapsed = 0;
  for (auto& t : tasks) {
    elapsed += t.first;
    res += t.second - elapsed;
  }
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while (t--) {
      solve();
  }

  return 0;
}
