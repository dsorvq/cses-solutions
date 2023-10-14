#include <bits/stdc++.h>
 
using namespace std;

template <class msa, class msb>
void balance(msa& a, msb& b, int64_t& a_sum, int64_t& b_sum) {
  int a_size = a.size();
  int b_size = b.size();
  if (abs(a_size - b_size) <= 1) {
    return;
  }
  if (a_size > b_size) {
    auto el = a.begin();
    b.insert(*el);
    a.erase(el);
    a_sum -= *el;
    b_sum += *el;
  }
  else {
    auto el = b.begin();
    a.insert(*el);
    b.erase(el);
    b_sum -= *el;
    a_sum += *el;
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
  int64_t upper_sum = 0;
  int64_t lower_sum = 0;
  for (int i = 0; i != k - 1; ++i) {
    if (lower.empty() or *lower.begin() >= data[i]) {
      lower.insert(data[i]);
      lower_sum += data[i];
    } else {
      upper.insert(data[i]);
      upper_sum += data[i];
    }
    balance(lower, upper, lower_sum, upper_sum);
  }

  for (int l = 0, r = k - 1; r != n; ++l, ++r) {
    if ((lower.empty() and upper.empty()) or *lower.begin() >= data[r]) {
      lower.insert(data[r]);
      lower_sum += data[r];
    } else if (lower.empty()) {
      if (*upper.begin() < data[r]) {
        lower.insert(*upper.begin());
        lower_sum += *upper.begin();
        upper_sum -= *upper.begin();
        upper.erase(upper.begin());
        upper.insert(data[r]);
        upper_sum += data[r];
      } else {
        lower.insert(data[r]);
        lower_sum += data[r];
      }
    } else {
      upper.insert(data[r]);
      upper_sum += data[r];
    }
    balance(lower, upper, lower_sum, upper_sum);

    int64_t median;
    if (lower.size() >= upper.size()) {
      median = *lower.begin();
    } else {
      median = *upper.begin();
    }
    int64_t res = lower.size() * median - lower_sum + upper_sum - upper.size() * median;

    cout << res << ' ';

    if (auto found = lower.find(data[l]); found != lower.end()) {
      lower_sum -= *found;
      lower.erase(found);
    } else {
      found = upper.find(data[l]);
      upper_sum -= *found;
      upper.erase(found);
    }
    balance(lower, upper, lower_sum, upper_sum);
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
