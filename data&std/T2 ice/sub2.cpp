#include <bits/stdc++.h>
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int N = 6e5 + 10, INF = 0x3f3f3f3f;
int get(int n)
{
    while(n % 2 == 0) n /= 2;
    return n;
}
fish main()
{
    freopen("ice.in", "r", stdin);
    freopen("ice.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    cout << k << "\n";
    for(int i = 1; i <= k; i ++)
    {
        int tp = get(n + i * 2);
        cout << (n - tp + 1) / 2 << "\n";
    }
    return 0;
}