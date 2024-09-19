// problem: 
// date: 
#include <bits/stdc++.h>
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 25;
int du[N], dp[N][N * (N - 1) / 2][N * (N - 1) * (N - 2) / 6], res[N][N];
struct node {int a, b, c;} note[N][N * (N - 1) / 2][N * (N - 1) * (N - 2) / 6];
void solve()
{
    memset(dp, 0x3f, sizeof dp);
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n; i ++)
	 	for(int j = 0; j <= n * (n - 1) / 2; j ++)
				for(int k = 0; k <= n * (n - 1) * (n - 2) / 6 - m; k ++)
                    dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i ++)
	 	for(int j = i * (i - 1) / 2; j <= n * (n - 1) / 2; j ++)
			for(int k = 0; k <= n * (n - 1) * (n - 2) / 6; k ++)
				for(int d = 0; d <= min(j, n) && d * (d - 1) / 2 <= k; d ++)
					if(dp[i - 1][j - d][k - d * (d - 1) / 2] <= d) {dp[i][j][k] = d, note[i][j][k] = {i - 1, j - d, k - d * (d - 1) / 2}; break;}
    node now = {0, 0, 0};
    if(dp[n][n * (n - 1) / 2][n * (n - 1) * (n - 2) / 6 - m] != INF) now = {n, n * (n - 1) / 2, n * (n - 1) * (n - 2) / 6 - m};
    if(now.a == 0 && now.b == 0 && now.c == 0) {cout << "No\n"; return ;}
    for(int i = n; i >= 1; i --)
    {
        du[i] = dp[now.a][now.b][now.c];
        now = note[now.a][now.b][now.c];
    }
    for(int i = 2; i <= n; i ++)    
        for(int j = 1; j <= n; j ++)
            res[i][j] = 0;
    vector<pair<int, int>> all;
    for(int i = 1; i <= n; i ++) all.push_back({du[i], i});
    for(int i = 0; i + 1 < n; i ++)
    {
        sort(all.begin(), all.end());
        int c = n - i - all[0].first - 1;
        for(int j = 1; j <= c; j ++)
        {
            all[n - i - j].first --;
            res[all[n - i - j].second][all[0].second] = 1;
        }
        for(int j = 1; j < n - i - c; j ++) res[all[0].second][all[j].second] = 1;
        reverse(all.begin(), all.end());
        all.pop_back();
        reverse(all.begin(), all.end());
    }
    cout << "Yes\n";
    for(int i = 2; i <= n; i ++)    
        for(int j = 1; j < i; j ++)  
            cout << res[i][j] << (j == i - 1 ? "\n" : "\0");
}
fish main()
{
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t --) solve();
    return 0;
}