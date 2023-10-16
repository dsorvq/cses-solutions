#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> pages(n + 1);
  vector<int> prices(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> prices[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> pages[i];
  }

  vector<int> dp(x + 1);

  for (int book = 1; book <= n; ++book) {
    for (int spend = x; spend > 0; --spend) {
      if (spend - prices[book] >= 0) {
        dp[spend] = max(dp[spend], dp[spend - prices[book]] + pages[book]);
      }
    }
  }

  cout << dp[x] << '\n';
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
