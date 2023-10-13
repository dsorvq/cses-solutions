#include <bits/stdc++.h>
 
using namespace std;

template <class msa, class msb>
void balance(msa& a, msb& b) {
  int a_size = a.size();
  int b_size = b.size();
  if (abs(a_size - b_size) <= 1) {
    return;
  }
  if (a_size > b_size) {
    auto el = a.begin();
    b.insert(*el);
    a.erase(el);
  }
  else {
    auto el = b.begin();
    a.insert(*el);
    b.erase(el);
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> data(n);
  for (int i = 0; i != n; ++i) {
    cin >> data[i];
  }

  multiset<int> upper;
  multiset<int, greater<int>> lower;
  for (int i = 0; i != k - 1; ++i) {
    if (lower.empty() or *lower.begin() >= data[i]) {
      lower.insert(data[i]);
    } else {
      upper.insert(data[i]);
    }
    balance(lower, upper);
  }

  for (int l = 0, r = k - 1; r != n; ++l, ++r) {
    if ((lower.empty() and upper.empty()) or *lower.begin() >= data[r]) {
      lower.insert(data[r]);
    } else if (lower.empty()) {
      if (*upper.begin() < data[r]) {
        lower.insert(*upper.begin());
        upper.erase(upper.begin());
        upper.insert(data[r]);
      } else {
        lower.insert(data[r]);
      }
    } else {
      upper.insert(data[r]);
    }
    balance(lower, upper);

    if (lower.size() >= upper.size()) {
      cout << *lower.begin();
    } else {
      cout << *upper.begin();
    }
    cout << ' ';

    if (auto found = lower.find(data[l]); found != lower.end()) {
      lower.erase(found);
    } else {
      found = upper.find(data[l]);
      upper.erase(found);
    }
    balance(lower, upper);
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
