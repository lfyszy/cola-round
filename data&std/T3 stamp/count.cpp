#include <bits/stdc++.h>
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
mt19937 rnd(random_device{}());
fish main()
{
    freopen("stamp.out", "r", stdin);
    freopen("count.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    int q; cin >> q;
    int cnt = 0;
    while(q --)
    {
        int opt, x, y; cin >> opt >> x >> y;
        if(opt > 0) cnt ++;
    }
    cout << cnt << "\n";
    return 0;
}