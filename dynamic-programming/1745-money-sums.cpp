#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> coins(n);
  int sum = 0;
  for (int i = 0; i != n; ++i) {
    cin >> coins[i];
    sum += coins[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
  dp[0][0] = 1;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= sum; ++j) {
      dp[i][j] = dp[i-1][j];
      if (dp[i][j]) {
        continue;
      }
      auto coin = coins[i - 1];
      if (j - coin >= 0 and dp[i-1][j - coin] == 1) {
        ++res;
        dp[i][j] = 1;
      }
    }
  }

  cout << res << '\n';
  for (int i = 1; i <= sum; ++i) {
    if (dp[n][i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
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
