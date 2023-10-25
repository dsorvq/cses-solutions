#include <bits/stdc++.h>
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

  const int NA = -1;
  vector<int> color(v + 1, NA);
  vector<int> parent(v + 1, NA);
  for (int i = 1; i <= v; ++i) {
    if (color[i] != NA) {
      continue;
    }

    color[i] = 1;
    stack<int> st;
    st.push(i);
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();

      auto child_color = 1 - color[cur];
      for (auto child : adj[cur]) {
        if (color[child] == NA) {
          st.push(child);
          color[child] = child_color;
          parent[child] = cur;
        } else if (color[child] == color[cur] and parent[cur] != child){
          cout << "IMPOSSIBLE\n";
          return;
        }
      }

    }
  }

  for (int i = 1; i <= v; ++i) {
    cout << color[i] + 1 << ' ';
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
