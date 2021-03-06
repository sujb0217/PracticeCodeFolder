/**
 *    author: subobo
 *    created: 01.04.2022 09:30:18
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
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<bool> pos(26);
    int pair = 0;
    for (int i = 0; i < n; i++) {
      if (pos[s[i] - 'a']) {
        fill(pos.begin(), pos.end(), false);
        pair += 1;
      } else {
        pos[s[i] - 'a'] = true;
      }
    }
    cout << n - pair * 2 << '\n';
  }
  return 0;
}