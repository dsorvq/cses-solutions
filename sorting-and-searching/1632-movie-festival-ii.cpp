#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> movies(n);
  for (int i = 0; i != n; ++i) {
    cin >> movies[i].first >> movies[i].second;
  }
  sort(begin(movies), end(movies), 
      [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
          return a.second < b.second;
        }
        return a.first < b.first;
      }
  );

  multiset<int, greater<int>> end_times;
  for (int i = 0; i != k; ++i) {
    end_times.insert(0);
  }

  int res = 0;
  for (auto movie : movies) {
    auto found = end_times.lower_bound(movie.first);
    if (found != end_times.end()) {
      ++res;
      end_times.erase(found);
      end_times.insert(movie.second);
    }
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
