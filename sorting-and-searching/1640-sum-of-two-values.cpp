#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n, target;
  cin >> n >> target;
  
  vector<pair<int, int>> data(n);
  for (int i = 0; i != n; ++i) {
    cin >> data[i].first;
    data[i].second = i;
  }
 
  auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first < b.first)
      return true;
    return false;
  };
 
  sort(begin(data), end(data), comp);
 
  int half = target / 2;
  for (auto it = begin(data); it != end(data); ++it) {
    if (it->first > half)
      break;
    pair<int, int> search = {target - it->first, -1};
    auto found = lower_bound(it + 1, end(data), search, comp);
    if (found != end(data) and found->first == search.first) {
      cout << it->second + 1 << ' ' << found->second + 1 << '\n'; 
      return;
    }
  }
  cout << "IMPOSSIBLE\n";
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
