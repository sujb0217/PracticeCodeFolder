/**
 *    author: subobo
 *    created: 21.04.2022 22:35:23
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int rt;
    cin >> rt;
    if (rt <= 1399) {
      cout << "Division 4\n";
    } else 
    if (1400 <= rt && rt <= 1599) {
      cout << "Division 3\n";
    } else
    if (1600 <= rt && rt <= 1899) {
      cout << "Division 2\n";
    } else {
      cout << "Division 1\n";
    }
  }
  return 0;
}