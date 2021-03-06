/**
 *    author: subobo
 *    created: 21.03.2022 23:13:31
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
  int n;
  cin >> n;
  const int N = (int) 1e6;
  vector<int> cnt(N + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      int delta = j / i - i;
      if (delta >= 0 && delta % 2 == 0) {
        ans += cnt[delta / 2] * cnt[j];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}