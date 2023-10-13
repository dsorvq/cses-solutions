#include <bits/stdc++.h>
 
using namespace std;

bool ok(const vector<int>& nums, int64_t sum, int k) {
  int count = 1;
  int64_t cur_sum = 0;
 
  for (auto c : nums) {
    if (cur_sum + c > sum) {
      cur_sum = 0;
      ++count;
    }
    if (c > sum) {
      return false;
    }
    cur_sum += c;
  }
  
  return count <= k;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i != n; ++i) {
    cin >> nums[i];
  }

  int64_t a = 1, b = 2e5 * 1e9;

  while (a <= b) {
    auto mid = (b - a) / 2 + a;
    if (ok(nums, mid, k)) {
      b = mid - 1;
    } else {
      a = mid + 1; 
    }
  }

  cout << a << '\n';
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
