#include <bits/stdc++.h>

using namespace std;

void solve() {  
  int n, q;
  cin >> n >> q;

  vector<int64_t> prefix_sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> prefix_sum[i];
    prefix_sum[i] += prefix_sum[i - 1];
  }

  for (int i = 0; i != q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << prefix_sum[b] - prefix_sum[a - 1] << '\n';
  }
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
