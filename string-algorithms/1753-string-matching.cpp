#include <bits/stdc++.h>

using namespace std;

auto prefix_function(string& s) {
  vector<int> pi(s.size() + 1);  
  pi[0] = -1;
  for (int i = 1; i <= s.size(); ++i) {
    auto len = pi[i - 1];
    while (len != -1 and s[len] != s[i - 1]) {
      len = pi[len];
    }
    pi[i] = len + 1;
  }

  return pi;
}

void solve() {  
  string s;
  string p;
  cin >> s >> p;
  auto p_len = p.size();
  p += '#';
  p += s;
  auto pi = prefix_function(p);

  cout << count(begin(pi) + p_len, end(pi), p_len) << '\n';
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
