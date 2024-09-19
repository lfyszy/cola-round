#include <bits/stdc++.h>
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e7 + 10;
int ans[N], n, k;
bool f, st[N];
void dfs(int u)
{
    if(f) return ;
    if(u == k + 1)
    {
        for(int i = 1; i <= k; i ++) cout << ans[i] << "\n";
        f = 1;
        return ;
    }
    for(int i = 1; i <= k; i ++)
        if(!st[i] && __gcd(n - 2 * i + 1, n + 2 * u - 1) == 1)
        {
            ans[u] = i, st[i] = 1;
            dfs(u + 1); st[i] = 0;
        }
}
fish main()
{
    freopen("ice.in", "r", stdin);
    freopen("ice.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cout << k << "\n";
    dfs(1);
    return 0;
}
