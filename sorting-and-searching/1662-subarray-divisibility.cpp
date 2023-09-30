#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, target;
  cin >> n;
  target = n;

  int64_t sum = 0;
  vector<int64_t> modulo_space(n);
  modulo_space[0] = 1;
  for (int i = 0; i != n; ++i) {
    int64_t a;
    cin >> a;
    /* Should work, but doesn't, don't know why :\
    sum = (sum + abs(a % n)) % n;
    ++modulo_space[sum];
    */
    sum += a;
    ++modulo_space[(sum % n + n) % n];
  }

  int64_t res = 0;
  for (auto c : modulo_space) {
    res += (c * (c - 1)) / 2;
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
