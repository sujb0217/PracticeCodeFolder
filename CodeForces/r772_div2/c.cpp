/**
 *    author: subobo
 *    created: 08.03.2022 21:23:09
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
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (a[n] < a[n - 1]) {
      puts("-1");
      continue;
    }
    bool ok = true;
    vector<array<int, 3>> s;
    for (int i = n - 2; i >= 1; i--) {
      if (a[i] > a[i + 1]) {
        a[i] = a[i + 1] - a[n];
        if (a[i] > a[i + 1]) {
          ok = false;
          break;
        }
        s.push_back({i, i + 1, n});
      }
    }
    if (ok) {
      cout << s.size() << '\n';
      for (auto i : s) {
        for (int j : i) {
          cout << j << " ";
        }
        cout << '\n';
      }
    } else {
      puts("-1");
    }
  }
  return 0;
}