#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  list<int> ls;
  for (int i = 1; i <= n; ++i) {
    ls.push_back(i);
  }
 
  auto it = next(ls.begin());
  while (n > 1) {
    if (it == ls.end()) {
      it = ls.begin();
    }
    cout << *it << ' ';
    it = ls.erase(it);
    if (it != ls.end())
      ++it;
    else 
      it = ++(++it);
    --n;
  }
  
  if (!ls.empty())
    cout << *ls.begin() << '\n';
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
