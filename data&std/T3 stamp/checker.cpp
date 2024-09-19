#include "testlib_for_lemon.h"
// #include "testlib.h"
#include <bits/stdc++.h>
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int N = 20 + 10;
string s[N], e[N], p[N][N];
int nn[N], mm[N], n, m, k;
struct node {int opt, x, y;} ; vector<node> v;
bool check(pair<int, int> a)
{
    if(a.first > n || a.second > m || a.first < 1 || a.second < 1) return 0;
    return 1;
}
pair<int, int> get_swap(int opt, int x, int y)
{
    if(opt == -4) return {x - 1, y};
    if(opt == -3) return {x + 1, y};
    if(opt == -2) return {x, y - 1};
    if(opt == -1) return {x, y + 1};
}
int main(int argc, char* argv[])
{
    // registerTestlibCmd(argc, argv);
    registerLemonChecker(argc, argv);
    n = inf.readInt(), m = inf.readInt(), k = inf.readInt();
    for(int i = 1; i <= n; i ++) s[i] = 'Y' + inf.readToken();
    for(int i = 1; i <= n; i ++) e[i] = 'Y' + inf.readToken();
    for(int id = 1; id <= k; id ++)
    {
        nn[id] = inf.readInt(), mm[id] = inf.readInt();
        for(int i = 1; i <= nn[id]; i ++) p[id][i] = 'Y' + inf.readToken();
    }
    int f = ans.readInt();
    int q = ouf.readInt();
    if(f == -1)
        if(q == -1) quitf(_ok, "It seems that they wil be happy.");
        else quitf(_wa, "There are feasible solutions available.");
    if(q > 400000) quitf(_wa, "You have used too many operations.");
    if(q < -1) quitf(_wa, "Your number of operations is negative.");
    while(q --)
    {
        node a; a.opt = ouf.readInt(); a.x = ouf.readInt(); a.y = ouf.readInt();
        v.push_back(a);
    }
    for(auto a : v)
    {
        if(a.opt < -4) quitf(_wa, "Impossible operation.1");
        if(a.opt > k) quitf(_wa, "Impossible operation.2");
        if(a.x < 1) quitf(_wa, "Impossible operation.3");
        if(a.y < 1) quitf(_wa, "Impossible operation.4");
        if(a.x > n) quitf(_wa, "Impossible operation.5");
        if(a.y > m) quitf(_wa, "Impossible operation.6");
        if(a.opt < 0) {if(!check(get_swap(a.opt, a.x, a.y))) quitf(_wa, "Impossible operation.7");}
        else if(a.opt == 0) {if(!check({a.x + 1, a.y + 1})) quitf(_wa, "Impossible operation.8");}
        else {if(!check({a.x + nn[a.opt] - 1, a.y + mm[a.opt] - 1})) quitf(_wa, "Impossible operation.9");}
        if(a.opt < 0)
            swap(s[a.x][a.y], s[get_swap(a.opt, a.x, a.y).first][get_swap(a.opt, a.x, a.y).second]);
        else if(a.opt == 0)
        {
            string tp;
            tp.push_back(s[a.x + 1][a.y]);
            tp.push_back(s[a.x][a.y]);
            tp.push_back(s[a.x][a.y + 1]);
            tp.push_back(s[a.x + 1][a.y + 1]);
            s[a.x][a.y] = tp[0];
            s[a.x][a.y + 1] = tp[1];
            s[a.x + 1][a.y + 1] = tp[2];
            s[a.x + 1][a.y] = tp[3];
        }
        else
        {
            for(int i = a.x; i <= a.x + nn[a.opt] - 1; i ++)
                for(int j = a.y; j <= a.y + mm[a.opt] - 1; j ++)
                    s[i][j] = p[a.opt][i - a.x + 1][j - a.y + 1];
        }
    }
    for(int i = 1; i <= n; i ++)
        if(s[i] != e[i]) quitf(_wa, "Your plan was wrong.");
    quitf(_ok, "It seems that they wil be happy.");
    return 0;
}