#include <bits/stdc++.h>
 
using namespace std;
 
// do not blow my hashes :|
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
 
void solve() {
  int n;
  cin >> n;
  vector<int> data(n);
  for (int i = 0; i != n; ++i) {
    cin >> data[i];
  }
  
  int res = 0;
    
  unordered_set<int, custom_hash> saw;
  for (int l = 0, r = 0; r < n; ++r) {
    if (saw.count(data[r])) {
      while (data[l] != data[r]) {
        saw.erase(data[l]);
        ++l;
      }
      ++l;
    }
    else {
      res = max(res, r - l + 1);
      saw.insert(data[r]);
    }
  }
  
  cout << res << '\n';
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
