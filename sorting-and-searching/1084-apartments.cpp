#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int applicants_number;
  int appartments_number;
  int k;
  cin >> applicants_number >> appartments_number >> k;
 
  vector<int> applicants(applicants_number);
  vector<int> appartments(appartments_number);
 
  for (int i = 0; i != applicants_number; ++i) {
    cin >> applicants[i];
  }
  for (int i = 0; i != appartments_number; ++i) {
    cin >> appartments[i];
  }
  
  sort(begin(applicants), end(applicants));
  sort(begin(appartments), end(appartments));
 
  int res = 0;
  int applicant = 0, appartment = 0;
  while (applicant < applicants_number and appartment < appartments_number) {
    int differ = applicants[applicant] - appartments[appartment];
    if (abs(differ) <= k) {
      ++res;
      ++applicant;
      ++appartment;
    }
    else if (differ > 0) {
      ++appartment;
    }
    else {
      ++applicant;
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
