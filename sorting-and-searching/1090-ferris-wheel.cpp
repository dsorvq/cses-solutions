#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n, x;
  cin >> n >> x;
 
  vector<int> children(n);
  for (int i = 0; i != n; ++i) {
    cin >> children[i];
  }
  sort(begin(children), end(children));
 
  int res = 0;
  int l = 0, r = n - 1;
 
  while (l <= r) {
    if (children[l] + children[r] <= x) {
      ++l;
    }
    --r;
    ++res;
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
