/**
 *    author: subobo
 *    created: 17.01.2022 12:28:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> dp(n + 1);
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
      dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
    }
    cout << dp[n] << '\n';
  }
  return 0;
}

