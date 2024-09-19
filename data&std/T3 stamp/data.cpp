#include <bits/stdc++.h>
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
mt19937 rnd(time(NULL));
char rdch()
{
    int tp = rnd();
    if(tp % 3 == 0) return rnd() % 26 + 'a';
    if(tp % 3 == 1) return rnd() % 26 + 'A';
    if(tp % 3 == 2) return rnd() % 10 + '0';
}
const int N = 25;
char st[N][N], ed[N][N], pre[N][N][N];
int nn[N], mm[N];
int rd(int l, int r) {if(l == r) return l; return rnd() % (r - l) + l;}
pair<int, int> get_swap(int opt, int x, int y)
{
    if(opt == -4) return {x - 1, y};
    if(opt == -3) return {x + 1, y};
    if(opt == -2) return {x, y - 1};
    if(opt == -1) return {x, y + 1};
}
int solve()
{
    ofstream ofs; ofs.open("stamp.in", ios::out);
    int n = 20, m = 20;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            ed[i][j] = st[i][j] = rdch();
    int k = 20;
    for(int o = 1; o <= k; o ++)
    {
        nn[o] = rd(1, 20), mm[o] = rd(1, 20);
        for(int i = 1; i <= nn[o]; i ++)
            for(int j = 1; j <= mm[o]; j ++)
                pre[o][i][j] = rdch();

    }
    int q = rd(1e3, 5e3);
    // q = 1;
    while(q --)
    {
        int ttp = rnd();
        if(ttp % 100 == 0)
        {
            int opt = -rd(1, 4);
            int x, y;
            if(opt == -4) x = rd(2, n), y = rd(1, m);
            if(opt == -3) x = rd(1, n - 1), y = rd(1, m);
            if(opt == -2) x = rd(1, n), y = rd(2, m);
            if(opt == -1) x = rd(1, n), y = rd(1, m - 1);
            int _x = get_swap(opt, x, y).first;
            int _y = get_swap(opt, x, y).second;
            swap(ed[x][y], ed[_x][_y]);
        }
        else if(ttp % 100 < 50)
        {
            int x = rd(1, n - 1), y = rd(1, m - 1);
            string tp;
            tp.push_back(ed[x + 1][y]);
            tp.push_back(ed[x][y]);
            tp.push_back(ed[x][y + 1]);
            tp.push_back(ed[x + 1][y + 1]);
            ed[x][y] = tp[0];
            ed[x][y + 1] = tp[1];
            ed[x + 1][y + 1] = tp[2];
            ed[x + 1][y] = tp[3];
        }
        else
        {
            int opt = rd(1, k);
            int x = rd(1, n - nn[opt] + 1), y = rd(1, m - mm[opt] + 1);
            for(int i = x; i <= x + nn[opt] - 1; i ++)
                for(int j = y; j <= y + mm[opt] - 1; j ++)
                    ed[i][j] = pre[opt][i - x + 1][j - y + 1];
        }
    }
    ofs << n SP m SP k << "\n";
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            ofs << st[i][j] << (j == m ? "\n" : "\0");
    ofs << "\n";
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            ofs << ed[i][j] << (j == m ? "\n" : "\0");
    for(int o = 1; o <= k; o ++)
    {
        ofs << "\n";
        ofs << nn[o] SP mm[o] << "\n";
        for(int i = 1; i <= nn[o]; i ++)
            for(int j = 1; j <= mm[o]; j ++)
                ofs << pre[o][i][j] << (j == mm[o] ? "\n" : "\0");
    }
    system("std.exe");
    system("count.exe");
    ifstream ifs; ifs.open("count.out", ios::in);
    int cnt; ifs >> cnt; return cnt;
}
fish main()
{
    while(1) if(solve() > 90) return 0;
    return 0;
}