#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  string word1, word2;
  cin >> word1 >> word2;
  
  int m = word1.size();
  int n = word2.size();

  vector<int> dp(n + 1);
  for (int i = 0; i <= n; ++i) {
    dp[i] = i; 
  }

  for (int i = 1; i <= m; ++i) {
    dp[0] = i;
    auto prev = dp[0] - 1;
    for (int j = 1; j <= n; ++j) {
      auto tmp = dp[j];
      dp[j] = min({dp[j - 1] + 1, dp[j] + 1, prev + !(word1[i - 1] == word2[j - 1])});
      prev = tmp;
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
