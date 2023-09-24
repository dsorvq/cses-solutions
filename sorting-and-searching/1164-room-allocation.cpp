#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> customers(n);
  for (int i = 0; i != n; ++i) {
    cin >> customers[i].first.first >> customers[i].first.second; 
    customers[i].second = i + 1;
  }
  sort(begin(customers), end(customers));

  int total_rooms = 0;
  vector<int> results(n + 1);
  // first = departure, second = id
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  

  for (auto& customer : customers) {
    if (!pq.empty() and pq.top().first < customer.first.first) {
      results[customer.second] = results[pq.top().second];
      pq.pop();
    }
    else {
      int sz = pq.size() + 1;
      results[customer.second] = sz;
      total_rooms = max(total_rooms, sz);
    }
    pq.push({customer.first.second, customer.second});
  }

  cout << total_rooms << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << results[i] << ' ';
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
