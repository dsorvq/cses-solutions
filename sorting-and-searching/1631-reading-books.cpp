#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; 
  cin >> n;
  int64_t max_element = 0;
  int64_t sum = 0;
  for (int i = 0; i != n; ++i) {
    int64_t a;
    cin >> a;
    sum += a;
    max_element = max(a, max_element);
  }
  if (sum - max_element < max_element) {
    sum = max_element * 2;
  }
  cout << sum << '\n';
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
