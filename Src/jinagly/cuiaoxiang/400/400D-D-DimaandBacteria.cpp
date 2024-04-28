// url:https://codeforces.com/contest/400/problem/D
// time:2021-11-08 16:49:06
// name:D-DimaandBacteria

#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

template <class T> auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
  return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

typedef long long int64;
typedef pair<int, int> ii;
#define SZ(x) (int)((x).size())
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
// mt19937_64 mrand(random_device{}());
// int64 rnd(int64 x) { return mrand() % x; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < SZ(a); ++i) cout << a[i] << " \n"[i + 1 == SZ(a)]; }
template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> void dedup(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
void add(int& x, int y) { x += y; if (x >= MOD) x -= MOD; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

const int N = 1e5 + 10;
int f[N];
int find(int x) {
  if (f[x] != f[f[x]]) f[x] = find(f[x]);
  return f[x];
}
void join(int x, int y) {
  int rx = find(x), ry = find(y);
  if (rx != ry) {
    f[ry] = rx;
  }
}

int main() {
  int n, m, len;
  cin >> n >> m >> len;
  vector<int> cnt(len);
  for (int i = 0; i < len; ++i) cin >> cnt[i];
  vector<int> id(n);
  for (int i = 0, k = 0; i < len; ++i) {
    for (int j = 0; j < cnt[i]; ++j) id[k + j] = i;
    k += cnt[i];
  }
  for (int i = 0; i < n; ++i) f[i] = i;
  auto g = vect<int>(inf<int>, len, len);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    if (z == 0) {
      join(x, y);
    }
    if (id[x] != id[y]) {
      int u = id[x], v = id[y];
      ckmin(g[u][v], z);
      ckmin(g[v][u], z);
    }
  }
  for (int i = 0, k = 0; i < len; ++i) {
    int r = find(k);
    bool ok = true;
    for (int j = 1; j < cnt[i]; ++j) {
      if (find(k + j) != r) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "No" << '\n';
      return 0;
    }
    k += cnt[i];
  }
  for (int i = 0; i < len; ++i) g[i][i] = 0;
  for (int k = 0; k < len; ++k) {
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        ckmin(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      if (g[i][j] == inf<int>) g[i][j] = -1;
    }
    out(g[i]);
  }

  return 0;
}

