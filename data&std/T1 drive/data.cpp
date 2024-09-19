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
mt19937 rnd(random_device{}());
fish main()
{
    freopen("down/2.in", "w", stdout);
    int t = rnd() % 3 + 1, sum = 0, lim = 1e7;
    int max = lim / t;
    cout << t << "\n";
    while(t --)
    {
        int n = rnd() % max + 1;
        cout << n << "\n";
        for(int i = 1; i <= n; i ++)
        {
            int opt = rnd();
            if(i <= n / 3) opt = opt % 4 == 0 ? -1 : opt % 4 <= 2 ? 1 : 0;
            else opt = opt % 4 == 0 ? 0 : opt % 4 == 1 ? 1 : -1;
            cout << opt << " ";
        } if(t) cout << "\n";
    }
    return 0;
}