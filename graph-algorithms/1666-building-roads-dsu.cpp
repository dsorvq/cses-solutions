#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class dsu {
public:
  dsu(int v) : size(v, 1), link(v) {
    iota(begin(link), end(link), 0);
  }
  
  int find(int x) {
    while (link[x] != x) {
      x = link[x];
    }
    return x;
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
  
    if (size[a] > size[b]) {
      swap(a, b);
    }
  
    size[b] += size[a];
    link[a] = b;
    size[a] = 0;
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }

  vector<int> get_representatives(int s = 0) {
    vector<int> representatives; 
    for (int i = s; i < size.size(); ++i) {
      if (size[i]) {
        representatives.push_back(i);
      }
    }
    return representatives;
  }

private:
  vector<int> size;
  vector<int> link;
};

void solve() {  
  int v, e;
  cin >> v >> e;

  dsu connections(v + 1);
  for (int i = 0; i != e; ++i) {
    int a, b;
    cin >> a >> b;
    if (!connections.same(a, b)) {
      connections.unite(a, b);
    }
  }

  auto representatives = connections.get_representatives(1);
  auto sz = representatives.size();
  cout << sz - 1 << '\n';
  for (int i = 1; i < sz; ++i) {
    cout << representatives[i - 1] << ' ' << representatives[i] << '\n';
  }
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
