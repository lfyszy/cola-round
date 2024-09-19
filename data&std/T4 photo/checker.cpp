#include "testlib_for_lemon.h"
// #include "testlib.h"
#include <bits/stdc++.h>
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int N = 5e3 + 10;
long long du[N];
int main(int argc, char* argv[])
{
    // registerTestlibCmd(argc, argv);
    registerLemonChecker(argc, argv);
    int t = inf.readInt();
    while(t --)
    {
        long long n = inf.readInt(), m = inf.readLong();
        string f = ans.readToken();
        string found = ouf.readToken();
        if(f != found) quitf(_wa, "You did not correctly determine whether there is a solution.\n");
        if(f == "No") continue;
        for(int i = 1; i <= n; i ++) du[i] = 0;
        for(int i = 2; i <= n; i ++)
        {
            string s = 'Y' + ouf.readToken();
            ans.readToken();
            for(int j = 1; j < i; j ++)
            {
                if(s[j] == '1') du[i] ++;
                else du[j] ++;
            }
        }
        long long res = n * (n - 1) * (n - 2) / 6;
        for(int i = 1; i <= n; i ++) res -= du[i] * (du[i] - 1) / 2;
        if(res != m) quitf(_wa, "Your plan is wrong.");
    }
    quitf(_ok, "Now you know how lovely she is^v^.");
    return 0;
}