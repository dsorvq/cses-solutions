#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i != n; ++i) {
    cin >> nums[i];
  }
 
  sort(begin(nums), end(nums));
 
  int res = 1;
  for (int i = 1; i != n; ++i) {
    if (nums[i-1] == nums[i])
      continue;
    ++res;
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
