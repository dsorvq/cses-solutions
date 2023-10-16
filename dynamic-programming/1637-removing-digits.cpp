#include <bits/stdc++.h>
 
using namespace std;

int get_max_digit(int n) {
  int res = 0;
  while (n) {
    res = max(res, n % 10);
    n /= 10;
  }

  return res;
}

void solve() {
  int n;
  cin >> n;

  int res = 0;
  while (n) {
    ++res;
    n -= get_max_digit(n);
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
