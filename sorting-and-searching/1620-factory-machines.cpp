#include <bits/stdc++.h>

using namespace std;

bool possible(vector<int>& machines, int64_t time, int64_t products_needed) {
  int64_t products = 0;
  for (auto c : machines) {
    products += time / c;
    if (products >= products_needed)
      return true;
  }
  return false;
}

void solve() {
  int n, t;
  cin >> n >> t;

  vector<int> machines(n);
  for (int i = 0; i != n; ++i) {
    cin >> machines[i];
  }
 
  int64_t a = 1, b = numeric_limits<int64_t>::max();
  while (a <= b) {
    auto mid = (b - a) / 2 + a;
    if (possible(machines, mid, t)) {
      b = mid - 1; 
    }
    else {
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
