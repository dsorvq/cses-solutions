#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int n;
  cin >> n;

  const int mod = 1e9 + 7;

  vector<int> dp(n);
  dp[0] = 1;
  for (int i = 0; i != n; ++i) {
    string row;
    cin >> row;

    for (int j = 0; j != n; ++j) {
      if (row[j] == '*') {
        dp[j] = 0;
      } else if (j - 1 >= 0) {
        dp[j] = (dp[j] + dp[j - 1]) % mod;
      }
    }
  }

  cout << dp.back() << '\n';
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
