#include <bits/stdc++.h>
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e6 + 10;
int ans[N], K;
void solve(int k)
{
    if(!k) return ;
    int p = 0;
    while((2 * k - 1) >> p) p ++;
    p = ((1 << p) - 2 * k) / 2 + 1;
    solve(p - 1);
    for(int i = p; i <= k; i ++) ans[i] = k - i + p;
}
fish main()
{
    freopen("ice.in", "r", stdin);
    freopen("ice.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string n; cin >> n >> K;
    cout << K << "\n";
    solve(K);
    for(int i = 1; i <= K; i ++) cout << ans[i] << "\n";
    return 0;
}