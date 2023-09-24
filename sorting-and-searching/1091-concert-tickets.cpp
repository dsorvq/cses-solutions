#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int tickets_number, customers_number;
  cin >> tickets_number >> customers_number;
  multiset<int> tickets;
  for (int i = 0; i != tickets_number; ++i) {
    int ticket;
    cin >> ticket;
    tickets.insert(ticket);
  }
 
  for (int i = 0; i != customers_number; ++i) {
    int customer;
    cin >> customer;
    auto found = tickets.lower_bound(customer);
    if (found == tickets.begin() and *found != customer) {
      cout << "-1\n";
    }
    else {
      if (*found != customer)
        --found;
      cout << *found << '\n';
      tickets.erase(found);
    }
  }
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
