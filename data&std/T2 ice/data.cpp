// problem: 
// date: 
#include <bits/stdc++.h>
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f, lim = 1e9;
mt19937 rnd(random_device{}());
fish main()
{
    int k = rnd() % 3000; int n =  rnd() % lim; n -= n % 2;
    freopen("data/2.in", "w", stdout);
    cout << n SP k << "\n";
    freopen("data/2.out", "w", stdout);
    cout << k << "\n";
    return 0;
}