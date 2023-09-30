#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> numbers(n);
  for (int i = 0; i != n; ++i) {
    cin >> numbers[i];
  }

  unordered_map<int, int> window;
  int distinct = 0;
  int64_t res = 0;
  for (int a = 0, b = 0; b < n; ++b) {
    ++window[numbers[b]];
    if (window[numbers[b]] == 1) {
      ++distinct;
    }
    while (distinct > k) {
      if (--window[numbers[a++]] == 0) {
        --distinct;
      }
    }
    res += b - a + 1ll; 
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
