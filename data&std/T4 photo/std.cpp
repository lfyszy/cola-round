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
const int N = 5e3 + 10;
int res[N][N], inq[N];
vector<int> du[N];
queue<int> q;
#define c2(n) ((n) * (n - 1) / 2)
#define c3(n) ((n) * (n - 1) * (n - 2) / 6)
int min_m(int n) {return n & 1 ? n * c2(n / 2) : (n / 2) * c2(n / 2) + (n / 2) * c2(n / 2 - 1);}
void solve()
{
    int n, m; cin >> n >> m;
    /*-----*/
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            res[i][j] = 0;
    for(int i = 0; i < n; i ++) inq[i] = 0;
    for(int i = 0; i < n; i ++) du[i].clear();
    while(q.size()) q.pop();
    /*-----*/
    m = c3(n) - m;
    if(min_m(n) > m || m > c3(n)) {cout << "No\n"; return ;}
    int sum = 0, tp = n;
    while(tp && min_m(tp - 1) + c2(tp - 1) + sum <= m) sum += c2(tp - 1), tp --;
    int k = min_m(tp) + sum;
    for(int i = 1; i <= tp; i ++)
    {
        if(tp & 1)
        {
            int j = i + 1;
            for(int o = 1; o <= tp / 2; o ++)
            {
                if(j > tp) j = 1;
                res[i][j] = 1, j ++;
            }
        }
        else
        {
            int j = i + 1;
            for(int o = 1; o <= tp / 2 - (i > tp / 2); o ++)
            {
                if(j > tp) j = 1;
                res[i][j] = 1, j ++;
            }
        }
    }
    for(int i = tp + 1; i <= n; i ++)
        for(int j = 1; j < i; j ++) res[i][j] = 1;
    for(int i = 1; i <= n; i ++)
    {
        int d = 0;
        for(int j = 1; j <= n; j ++) d += res[i][j];
        du[d].push_back(i);
    }
    for(int d = 0; d < n; d ++)
        if(du[d].size() >= 2)
            inq[d] = 1, q.push(d);
    for(; k < m; k ++)
    {
        int d = q.front(); q.pop();
        inq[d] = 0;
        int u = du[d].back(); du[d].pop_back();
        int v = du[d].back(); du[d].pop_back();
        swap(res[u][v], res[v][u]);
        if(res[u][v] == 1) swap(u, v);
        du[d - 1].push_back(u);
        du[d + 1].push_back(v);
        for(int i = d - 1; i <= d + 1; i ++)
            if(du[i].size() >= 2 && !inq[i])
                inq[i] = 1, q.push(i);
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j < i; j ++)
            cout << res[i][j] << (j == i - 1 ? "\n" : "\0");
}
fish main()
{
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t --) solve();
    return 0;
}