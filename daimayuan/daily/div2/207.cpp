/**
 *    author: subobo
 *    created: 12.03.2022 09:05:51
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
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> cnt(n + 1);
  cnt[0] = 1;
  int one = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      one += 1;
    }
    if (one >= k) {
      ans += cnt[one - k];
    }
    cnt[one] += 1;
  }
  cout << ans << '\n';
  return 0;
}