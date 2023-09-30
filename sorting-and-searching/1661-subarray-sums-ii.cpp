#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, target;
  cin >> n >> target;
 
  unordered_map<int64_t, int64_t> psum_map;
  vector<int64_t> psum_arr(n + 1);
  psum_map[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> psum_arr[i];
    psum_arr[i] += psum_arr[i-1];
    ++psum_map[psum_arr[i]];
  }

  int64_t res = 0;
  for (int i = n; i > 0; --i) {
    --psum_map[psum_arr[i]];
    int64_t search = psum_arr[i] - target;
    auto f = psum_map.find(search);
    if (f != end(psum_map)) {
      res += f->second;
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
