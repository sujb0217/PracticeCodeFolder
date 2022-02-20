/**
 *    author: subobo
 *    created: 20.02.2022 11:46:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> point(1);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    point.emplace_back(x, y);
  }
  int ans = 0;
  vector<bool> paired(n + 1, false);
  vector<int> ne(n + 1, 0), linked(n + 1, -1);
  auto check = [&]() {
    for (int i = 1; i <= n; i++) {
      int cur = i;
      for (int j = 1; j <= n; j++) {
        cur = linked[ne[cur]];
      }
      if (cur != -1) {
        return true;
      }
    }
    return false;
  };
  function<void()> Dfs = [&]() {
    int f = 1;
    while (paired[f] && f <= n) {
      f++;
    }
    if (f == n + 1) {
      // all pairs paired, check
      if (check()) {
        ans += 1;
      }
    }
    for (int p = f + 1; p <= n; p++) {
      if (!paired[p]) {
        paired[f] = paired[p] = true;
        linked[f] = p; linked[p] = f;
        Dfs();
        paired[f] = paired[p] = false;
        linked[f] = linked[p] = -1;
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    int x1 = point[i].first, y1 = point[i].second;
    for (int j = 1; j <= n; j++) {
      int x2 = point[j].first, y2 = point[j].second;
      if (i != j && y1 == y2 && x1 <= x2 && (!ne[i] || x2 < point[ne[i]].first)) {
        ne[i] = j;
      }
    }
  }
  Dfs();
  cout << ans << '\n';
  return 0;
}