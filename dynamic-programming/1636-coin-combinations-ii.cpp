#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int coins_number, target;
  cin >> coins_number >> target;

  vector<int> coins(coins_number);
  for (int i = 0; i != coins_number; ++i) {
    cin >> coins[i];
  }

  const int mod = 1e9 + 7;
  vector<int> dp(target + 1, 0);
  dp[0] = 1;

  for (auto coin : coins) {
    for (int i = 0; i <= target; ++i) {
      if (i - coin < 0) {
        continue;
      }
      dp[i] = (dp[i - coin] + dp[i]) % mod;
    }
  }

  cout << dp[target] << '\n';
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
