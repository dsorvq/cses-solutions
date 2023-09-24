#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
 
  vector<bool> saw(n + 1);
  saw[0] = 1;
  int res = 1;
  for (int i = 0; i != n; ++i) {
    int a;
    cin >> a;
    if (!saw[a-1])
      ++res;
    saw[a] = 1;
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
