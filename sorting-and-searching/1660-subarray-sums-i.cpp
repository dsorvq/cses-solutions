#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, target;
  cin >> n >> target;
  
  vector<int> numbers(n);
  for (int i = 0; i != n; ++i) {
    cin >> numbers[i]; 
  }

  int res = 0;
  int cur_sum = 0;
  for (int a = 0, b = 0; b < n; ++b) {
    cur_sum += numbers[b];
    while (cur_sum > target) {
      cur_sum -= numbers[a];
      ++a;
    }
    if (cur_sum == target) {
      ++res;
    }
  }
  cout << res << '\n';
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
