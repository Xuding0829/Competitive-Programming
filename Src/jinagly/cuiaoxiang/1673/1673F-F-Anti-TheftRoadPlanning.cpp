// url:https://codeforces.com/contest/1673/problem/F
// time:2022-04-30 19:32:48
// name:F-Anti-TheftRoadPlanning

// #define LOCAL
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
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const multiset<T, Cmp>& a) {
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

using int64 = long long;
using int128 = __int128_t;
using ii = pair<int, int>;
#define SZ(x) (int)((x).size())
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
mt19937_64 mrand(random_device{}());
int64 rnd(int64 x) { return mrand() % x; }
int lg2(int64 x) { return sizeof(int64) * 8 - 1 - __builtin_clzll(x); }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < SZ(a); ++i) cout << a[i] << " \n"[i + 1 == SZ(a)]; }
template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> void dedup(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
void add_mod(int& x, int y) { x += y; if (x >= MOD) x -= MOD; }
void sub_mod(int& x, int y) { x += MOD - y; if (x >= MOD) x -= MOD; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

int main() {
  // int n = 32;
  // vector<int> pre(n);
  // iota(pre.begin(), pre.end(), 0);
  // vector<int> a(n - 1);
  // for (int i = 0; i < n - 1; ++i) a[i] = pre[i + 1] ^ pre[i];
  // trace(a);
  // int sum = 0;
  // for (auto& x : a) sum += x;
  // trace(sum, sum * n + sum * n + 32 * n * (n - 1));

  int N = 32;
  vector<int> pre = {0}, a(N - 1);
  for (int k = 0; k < 5; ++k) {
    auto cur = pre;
    for (auto& x : cur) x += 1 << k;
    reverse(cur.begin(), cur.end());
    for (auto& x : cur) pre.push_back(x);
  }
  trace(pre);
  for (int i = 0; i < N - 1; ++i) a[i] = pre[i + 1] ^ pre[i];
  trace(a);

  vector<int> x(N - 1), y(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    for (int k = 0; k < 5; ++k) {
      if ((a[i] >> k) & 1) {
        x[i] |= 1 << (k * 2);
        y[i] |= 1 << (k * 2 + 1);
      }
    }
  }
  trace(x, y);

  int sum = 0;
  for (auto& t : x) sum += t;
  for (auto& t : y) sum += t;
  trace(sum, sum * N);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      if (j > 0) cout << " ";
      cout << x[j];
    }
    cout << endl;
  }
  for (int j = 0; j < n - 1; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i > 0) cout << " ";
      cout << y[j];
    }
    cout << endl;
  }

  trace(x, y);
  auto dist =
    [&](int sx, int sy, int tx, int ty) {
      int ret = 0;
      if (tx > sx) {
        for (int i = sx; i < tx; ++i) ret ^= x[i];
      } else {
        for (int i = tx; i < sx; ++i) ret ^= x[i];
      }
      if (ty > sy) {
        for (int i = sy; i < ty; ++i) ret ^= y[i];
      } else {
        for (int i = ty; i < sy; ++i) ret ^= y[i];
      }
      trace(sx, sy, tx, ty, ret);
      return ret;
    };

  int xx = 0, yy = 0;
  while (q--) {
    int sum;
    cin >> sum;
    bool found = 0;
    for (int nx = 0; nx < n; ++nx) {
      for (int ny = 0; ny < n; ++ny) {
        if (dist(xx, yy, nx, ny) == sum) {
          xx = nx;
          yy = ny;
          found = 1;
          break;
        }
      }
      if (found) break;
    }
    cout << yy + 1 << " " << xx + 1 << endl;
  }
  return 0;
}

