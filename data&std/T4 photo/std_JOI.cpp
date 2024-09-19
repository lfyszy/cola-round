// O(N^2) steps, each in O(1)

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }
#define COLOR(s) ("\x1b[" s "m")


Int c2(Int n) {
  return n*(n-1)/2;
}
Int c3(Int n) {
  return n*(n-1)*(n-2)/6;
}
Int minK(Int n) {
  return (n & 1) ? (n * c2(n/2)) : ((n/2) * c2(n/2 - 1) + (n/2) * c2(n/2));
}

vector<string> solveMin(int N) {
  if (N & 1) {
    vector<string> a(N, string(N, '0'));
    for (int u = 0; u < N; ++u) {
      int v = u;
      for (int i = 1; i <= N/2; ++i) {
        if (++v == N) v = 0;
        a[u][v] = '1';
      }
    }
    return a;
  } else {
    auto a = solveMin(N + 1);
    a.pop_back();
    for (int u = 0; u < N; ++u) a[u].pop_back();
    return a;
  }
}

vector<string> solve(int N, Int K) {
  if (!(minK(N) <= K && K <= c3(N))) return {};
  
  Int k;
  vector<string> a;
  {
    Int sum = 0;
    int n = N;
    for (; n && minK(n - 1) + c2(n-1) + sum <= K; --n) sum += c2(n-1);
    cout << n << " " << minK(n) << " " << minK(n - 1) + c2(n-1) + sum << " " << K << "\n";
    k = minK(n) + sum;
    a = solveMin(n);
    for (int u = 0; u < n; ++u) a[u].resize(N, '0');
    a.resize(N, string(N, '0'));
    for (int u = n; u < N; ++u) for (int v = 0; v < u; ++v) a[u][v] = '1';
  }
  
  vector<vector<int>> uss(N);
  for (int u = 0; u < N; ++u) {
    int d = 0;
    for (int v = 0; v < N; ++v) if (a[u][v] == '1') ++d;
    uss[d].push_back(u);
  }
  vector<int> inq(N + 1, 0);
  queue<int> que;
  for (int d = 0; d < N; ++d) if (uss[d].size() >= 2) {
    inq[d] = 1;
    que.push(d);
  }
  for (; k < K; ++k) {
    const int d = que.front();
    que.pop();
    inq[d] = 0;
    int u = uss[d].back(); uss[d].pop_back();
    int v = uss[d].back(); uss[d].pop_back();
    swap(a[u][v], a[v][u]);
    if (a[u][v] == '1') swap(u, v);
    uss[d - 1].push_back(u);
    uss[d + 1].push_back(v);
    for (int dd = d - 1; dd <= d + 1; ++dd) if (uss[dd].size() >= 2) {
      if (!inq[dd]) {
        inq[dd] = 1;
        que.push(dd);
      }
    }
  }
  return a;
}

void stress() {
  for (int N = 0; N <= 30; ++N) {
    cerr << "N = " << N << ": " << minK(N) << " <= K <= " << c3(N) << endl;
    for (Int K = 0; K <= c3(N); ++K) {
      const auto adj = solve(N, K);
      if (minK(N) <= K && K <= c3(N)) {
        assert((int)adj.size() == N);
        for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) assert(adj[u][v] == '0' || adj[u][v] == '1');
        for (int u = 0; u < N; ++u) assert(adj[u][u] == '0');
        for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) if (u != v) assert(adj[u][v] != adj[v][u]);
        Int score = 0;
        for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) for (int w = 0; w < N; ++w) {
          if (adj[u][v] == '1' && adj[u][w] == '1' && adj[v][w] == '1') ++score;
        }
        assert(score == K);
      } else {
        assert(!adj.size());
      }
    }
  }
}

int main() {
  // stress(); return 0;
  
  for (int numCases; ~scanf("%d", &numCases); ) for (int caseId = 1; caseId <= numCases; ++caseId) {
    int N;
    Int K;
    scanf("%d%lld", &N, &K);
    K = c3(N) - K;
    
    const auto adj = solve(N, K);
    if (adj.size()) {
      puts("Yes");
      for (int u = 1; u < N; ++u) {
        puts(adj[u].substr(0, u).c_str());
      }
    } else {
      puts("No");
    }
  }
  return 0;
}