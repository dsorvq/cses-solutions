#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
 
  long long cur = 0;
  long long res = numeric_limits<int>::min();
  for (int i = 0; i != n; ++i) {
    if (cur < 0)
      cur = 0;
    int a; cin >> a;
    cur += a;
    res = max(res, cur);
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
