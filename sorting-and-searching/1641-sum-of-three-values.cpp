#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, target;
  cin >> n >> target;
  vector<pair<int, int>> numbers(n);
  for (int i = 0; i != n; ++i) {
    cin >> numbers[i].first;
    numbers[i].second = i;
  }
  sort(begin(numbers), end(numbers));

  for (int i = 0; i != n; ++i) {
    int a = i + 1, b = n - 1;
    while (a < b) {
      int diff = target - numbers[i].first - numbers[a].first - numbers[b].first;
      if (diff == 0) {
        cout << numbers[i].second + 1 << ' ' 
             << numbers[a].second + 1 << ' ' 
             << numbers[b].second + 1 << '\n';
        return;
      }
      else if (diff < 0) {
        --b;
      }
      else {
        ++a;
      }
    }
  }

  cout << "IMPOSSIBLE\n";
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
