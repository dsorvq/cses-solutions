#include <bits/stdc++.h>
#include <ios>
#include <numeric>

using namespace std;

pair<int, int> operator+(pair<int, int>& a, pair<int, int>& b) {
  return {a.first + b.first, a.second + b.second};  
}

void solve() {  
  int m, n;
  cin >> m >> n;

  const char floor = '.';
  const char wall = '#';
  vector<vector<char>> grid(m, vector<char>(n));
  for (int i = 0; i != m; ++i) {
    for (int j = 0; j != n; ++j) {
      cin >> grid[i][j];
    }
  }

  auto check = [&](pair<int, int> a) -> bool {
    int i = a.first; int j = a.second;
    return (i >= 0 and i < m and j >= 0 and j < n) and (grid[i][j] == floor);
  };

  int res = 0;
  pair<int, int> dirs[4] = {{-1,  0}, {0, -1}, {0, 1}, {1, 0}};
  for (int i = 0; i != m; ++i) {
    for (int j = 0; j != n; ++j) {
      if (grid[i][j] == wall) {
        continue;
      }

      ++res;
      stack<pair<int, int>> st;
      st.push({i, j});
      grid[i][j] = wall;
      while (!st.empty()) {
        auto cur = st.top();
        st.pop();
        for (auto dir : dirs) {
          auto child = cur + dir;
          if (!check(child)) {
            continue;
          }

          grid[child.first][child.second] = wall;
          st.push(child);
        }
      }

    }
  }

  cout << res << '\n';
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
