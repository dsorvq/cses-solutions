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

  const int inf = numeric_limits<int>::max() / 10;
  vector<int> dp(target + 1, inf);
  dp[0] = 0;

  for (int i = 1; i <= target; ++i) {
    for (auto coin : coins) {
      if (i - coin < 0) {
        break;
      }
      dp[i] = min(dp[i], dp[i - coin] + 1);
    }
  }

  cout << (dp[target] == inf ? -1 : dp[target]) << '\n';
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
