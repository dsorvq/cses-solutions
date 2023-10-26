#include <bits/stdc++.h>

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

  const int NA = -1;
  vector<int> parent(v + 1, NA);

  for (int i = 1; i <= v; ++i) {
    if (parent[i] != NA) {
      continue;
    }
    
    parent[i] = 0; // no parent
    stack<int> st;
    st.push(i);
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();

      for (auto child : adj[cur]) {
        if (parent[child] == NA) {
          parent[child] = cur;
          st.push(child);
        } else if (parent[cur] != child) {
          auto bound = parent[child];
          vector<int> res;
          while (cur != bound) {
            res.push_back(cur); 
            cur = parent[cur];
          }
          cout << res.size() + 3 << '\n';
          cout << child << ' ';
          for (auto r : res) {
            cout << r << ' ';
          }
          cout << cur << ' ';
          cout << child << '\n';
          return;
        }
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
