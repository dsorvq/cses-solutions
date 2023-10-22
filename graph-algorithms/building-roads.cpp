#include <bits/stdc++.h>
#include <ios>
#include <numeric>

using namespace std;

void solve() {  
  int v, e;
  cin >> v >> e;
  vector<vector<int>> adj(v + 1, vector<int>());
  for (int i = 0; i != e; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int comps = 0;
  vector<bool> visited(v + 1);
  vector<int> roads;
  for (int i = 1; i <= v; ++i) {
    if (visited[i]) {
      continue;
    }
    ++comps;
    roads.push_back(i);
    visited[i] = true;

    stack<int> st;
    st.push(i);
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();
      for (auto child : adj[cur]) {
        if (visited[child]) {
          continue;
        }

        visited[child] = true;
        st.push(child);
      }
    }
  }

  int res = comps - 1;
  cout << res << '\n';
  for (int i = 0; i != res; ++i) {
    cout << roads[i] << ' ' << roads[i + 1] << '\n'; 
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
