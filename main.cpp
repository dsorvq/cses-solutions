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

  const int wall = -1;
  const int floor = 0;
  pair<int, int> A, B;
  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i != m; ++i) {
    for (int j = 0; j != n; ++j) {
      char c;
      cin >> c;
      if (c == '#') {
        grid[i][j] = wall;
      } else if (c == 'A') {
        A = {i, j};
      } else if (c == 'B') {
        B = {i, j};
      }
    }
  }

  const pair<int, int> dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
  const char dir_desc[4] = {'D', 'R', 'L', 'U'};

  auto check = [&](const pair<int, int>& a) -> bool {
    return (a.first >= 0 and a.first < m and a.second >= 0 and a.second <= n) and grid[a.first][a.second] == 0 and a != A;
  };

  queue<pair<int, int>> q; 
  q.push(A);

  while (!q.empty() and !grid[B.first][B.second]) {
    auto cur = q.front();
    q.pop();
    
    for (auto dir : dirs) {
      auto child = cur + dir;
      if (!check(child)) {
        continue;
      }
      
      grid[child.first][child.second] = grid[cur.first][cur.second] + 1;
      if (child == B) {
        break;
      }
      q.push(child);
    }
  }

  int len = grid[B.first][B.second];

  if (!len) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";

  auto cur = B;
  vector<char> res;
  res.reserve(len);
  while (len != 0) {
    for (int d = 0; d != 4; ++d) {
      auto dir = dirs[d];
      auto child = cur + dir;
      if (child.first >= 0 and child.first < m and child.second >= 0 and child.second < n and grid[child.first][child.second] == len - 1) {
        if (len == 1 and child != A)
          continue;
        --len;
        res.push_back(dir_desc[d]);
        cur = child;
        break;
      }
    }
  }
  cout << res.size() << '\n';
  for (auto d = res.rbegin(); d != res.rend(); ++d) {
    cout << *d;
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
