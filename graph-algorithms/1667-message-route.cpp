#include <bits/stdc++.h>
#include <ios>
#include <numeric>

using namespace std;

void solve() {  
  int v, e;
  cin >> v >> e;
  vector<vector<int>> adj(v + 1);
  for (int i = 0; i != e; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> distances(v + 1);
  distances[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    
    for (auto child : adj[cur]) {
      if (!distances[child] and child != 1) {
        q.push(child);
        distances[child] = distances[cur] + 1;
      }
    }
  }

  auto len = distances[v];
  if (!len) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  cout << len + 1 << '\n';

  int cur = v;
  vector<int> path;
  path.reserve(len + 1);
  path.push_back(cur);
  --len;

  while (len >= 0) {
    for (auto child : adj[cur]) {
      if (distances[child] == len) {
        --len;
        cur = child;
        path.push_back(child);
        break;
      }
    }
  }
  for (auto p = path.rbegin(); p != path.rend(); ++p) {
    cout << *p << ' '; 
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
