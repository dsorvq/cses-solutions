#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int coins_number, target;
  cin >> coins_number >> target;

  vector<int> coins(coins_number);
  for (int i = 0; i != coins_number; ++i) {
    cin >> coins[i];
  }
  sort(begin(coins), end(coins));

  const int mod = 1e9 + 7;
  vector<int64_t> dp(target + 1, 0);
  dp[0] = 1;

  for (int i = 0; i <= target; ++i) {
    for (auto coin : coins) {
      if (i - coin < 0) {
        break;
      }
      dp[i] += dp[i - coin];
    }
    dp[i] %= mod;
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
