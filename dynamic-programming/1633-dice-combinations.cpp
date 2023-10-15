#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <limits>
 
using namespace std;

void solve() {
  int n;
  cin >> n;

  const int mod = 1e9 + 7;

  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i != n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i + j > n) {
        break;
      }
      dp[i + j] = (dp[i + j] + dp[i]) % mod;
    }
  }
  cout << dp[n] << '\n';
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
