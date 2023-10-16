#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> data(n);
  for (int i = 0; i != n; ++i) {
    cin >> data[i];
  }

  const int64_t mod = 1e9 + 7;

  vector<vector<int64_t>> dp(n, vector<int64_t>(m + 2)); 
  if (data[0] == 0) {
    fill(begin(dp[0]), end(dp[0]), 1);
    dp[0][0] = 0; dp[0].back() = 0;
  } else {
    dp[0][data[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if (data[i] == 0) {
      for (int x = 1; x <= m; ++x) {
        dp[i][x] = (dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]) % mod;
      }
    } else {
      dp[i][data[i]] = (dp[i - 1][data[i] - 1] + dp[i - 1][data[i]] + dp[i - 1][data[i] + 1]) % mod;
    }
  }

  int64_t sum = 0;
  for (int i = 1; i <= m; ++i) {
    sum = (sum + dp.back()[i]) % mod;
  }
  cout << sum << '\n';
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
