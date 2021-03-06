/**
 *    author: subobo
 *    created: 23.03.2022 10:40:00
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p, g, eg, sz;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    g.resize(n);
    eg.resize(n);
    sz.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }

  inline int get(int x) {
    while (x != p[x]) {
      x = p[x];
    }
    return x;
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    p[y] = x;
    eg[y] = g[x];
    sz[x] += sz[y];
    return true;
  }

  inline void add(int x, int y) {
    x = get(x);
    g[x] += y;
  }

  inline int goal(int x) {
    return x == p[x] ? g[x] : (g[x] - eg[x] + goal(p[x]));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  dsu d(n);
  while (q--) {
    string op;
    cin >> op;
    if (op == "join") {
      int x, y;
      cin >> x >> y;
      --x; --y;
      d.unite(x, y);
    }
    if (op == "add") {
      int x, y;
      cin >> x >> y;
      --x;
      d.add(x, y);
    }
    if (op == "get") {
      int x;
      cin >> x;
      --x;
      int ans = d.goal(x);
      cout << ans << '\n';
    }
  }
  return 0;
}