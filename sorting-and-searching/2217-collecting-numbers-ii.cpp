#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  
  unordered_map<int, int> indexes;
  unordered_map<int, int> numbers;
  numbers.insert({0, 0});
  indexes.insert({0, 0});
  numbers.insert({n+1, n+1});
  indexes.insert({n+1, n+1});

  int res = 1;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    if (!numbers.count(a-1)) {
      ++res; 
    }
    
    indexes.insert({i, a});
    numbers.insert({a, i});
  }

  for (int i = 0; i != k; ++i) {
    int id_a, id_b;
    cin >> id_a >> id_b;
    int a = indexes.find(id_a)->second;
    int b = indexes.find(id_b)->second;

    // a
    int prev_a = a - 1;
    int next_a = a + 1;
    int id_prev_a = numbers.find(prev_a)->second;
    int id_next_a = numbers.find(next_a)->second;
    // b
    int prev_b = b - 1;
    int next_b = b + 1;
    int id_prev_b = numbers.find(prev_b)->second;
    int id_next_b = numbers.find(next_b)->second;

    if (id_prev_a > id_a and id_prev_a <= id_b) {
      --res;
    }
    if (id_prev_a < id_a and id_prev_a >= id_b) {
      ++res;
    }
    if (id_next_a > id_a and id_next_a < id_b) {
      ++res;
    }
    if (id_next_a < id_a and id_next_a > id_b) {
      --res;
    }
    if (id_prev_b > id_b and id_prev_b <= id_a) {
      --res;
    }
    if (id_prev_b < id_b and id_prev_b >= id_a) {
      ++res;
    }
    if (id_next_b > id_b and id_next_b < id_a) {
      ++res;
    }
    if (id_next_b < id_b and id_next_b > id_a) {
      --res;
    }

    // swap
    indexes[id_a] = b;
    indexes[id_b] = a;
    numbers[a] = id_b;
    numbers[b] = id_a;

    cout << res << '\n';
  }
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
