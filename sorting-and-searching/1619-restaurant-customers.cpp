#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> begins(n);
  vector<int> ends(n);
 
  for (int i = 0; i != n; ++i) {
    cin >> begins[i] >> ends[i];
  }
 
  sort(begin(begins), end(begins));
  sort(begin(ends), end(ends));
 
  int cur = 0;
  int res = 0;
 
  int b = 0, e = 0;
  while (b < n) {
    if (begins[b] < ends[e]) {
      ++cur;
      ++b;
      res = max(res, cur);
    }
    else {
      --cur;
      ++e;
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
