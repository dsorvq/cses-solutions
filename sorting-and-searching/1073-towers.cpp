#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
 
  vector<int> towers;
  towers.reserve(n);
  for (int i = 0; i != n; ++i) {
    int a;
    cin >> a;
    auto f = upper_bound(begin(towers), end(towers), a);
    if (f == towers.end()) {
      towers.push_back(a);
    }
    else {
      *f = a;
    }
  }
  cout << towers.size() << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  //cin >> t;
  t = 1;
  while (t--) {
      solve();
  }
 
  return 0;
}
