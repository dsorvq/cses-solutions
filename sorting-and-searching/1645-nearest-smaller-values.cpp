#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  stack<pair<int, int>> st;
  st.push({0, -1});
  for (int i = 0; i != n; ++i) {
    int a;
    cin >> a;
    while (st.top().first >= a) {
      st.pop();
    }
    cout << st.top().second + 1 << ' ';
    st.push({a, i});
  }
  cout << '\n';
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
