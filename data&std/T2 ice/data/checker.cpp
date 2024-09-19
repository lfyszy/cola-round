#include "testlib.h"
#include <bits/stdc++.h>
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int N = 1e7 + 10; int a[N]; bool st[N];
inline int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int k = ans.readInt(); int n = inf.readInt();
    int found = ouf.readInt();
    if(found != k) quitf(_wa, "Your answer is totally wrong.expect %d, found %d", k, found);
    for(int i = 1; i <= k; ++ i) a[i] = ouf.readInt();
    for(int i = 1; i <= k; ++ i)
    {
        if(a[i] > k) quitp(0.1, "You don't have a piece of ice numbered %d", a[i]);
        if(st[a[i]]) quitp(0.1, "You can't put a piece of ice into servel cups at the same time."); st[a[i]] = 1;
        if(gcd(n - (2 * a[i] - 1), n + 2 * i - 1) != 1) quitp(0.1, "Your answer is right but your plan is wrong.");
    }
    quitf(_ok, "I think cola is delicious^v^.");
    return 0;
}