#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> data(n);
  for (int i = 0; i != n; ++i) {
    cin >> data[i];
  }
  sort(begin(data), end(data));
 
  int median = data[n / 2];
 
  long long res = 0;
  for (int i = 0; i != n; ++i) {
    res += abs(median - data[i]);
  }
  cout << res << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  //cin >> t;
  t = 1;
  while (t--) {
      solve();
  }
 
  return 0;
}
