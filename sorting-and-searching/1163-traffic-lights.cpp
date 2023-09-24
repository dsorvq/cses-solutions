#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int len, n;
  cin >> len >> n;
  
  set<int> lights;
  lights.insert(0);
  lights.insert(len);
  multiset<int> distances;
  distances.insert(len);
  
  for (int i = 0; i != n; ++i) {
    int l;
    cin >> l;
    auto lb = lights.lower_bound(l);
    int b = *lb;
    int a = *prev(lb);
    lights.insert(l);
 
    int dist = b - a;
    distances.erase(distances.find(dist));
    distances.insert(l - a);
    distances.insert(b - l);
 
    cout << *distances.rbegin() << '\n';
  }
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
