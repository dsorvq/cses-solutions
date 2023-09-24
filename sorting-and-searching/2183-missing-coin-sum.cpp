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

  int64_t cur_sum = 0;
  for (int i = 0; i != n; ++i) {
    if (cur_sum + 1 < nums[i]) {
      break;
    }
    cur_sum += nums[i];
  }
  cout << cur_sum + 1 << '\n';
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
