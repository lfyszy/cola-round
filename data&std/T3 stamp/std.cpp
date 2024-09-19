#include <bits/stdc++.h>
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define SP << " " <<
#define fish signed
using namespace std;
const int N = 20 + 10, maxc = (int)('z') + 1;
char pap[N][N];
char pre[N][N][N];
int nn[N], mm[N], n, m, k;
int have[maxc], need[N][maxc], wildcard;
//have为矩阵中每个字符的数量,need为每个预设需要的每种字符的数量
int count(int u)//计算使用当前预设所需的通配符的数量
{
    int res = 0;
    for(int i = '0'; i < maxc; i ++)
        res += max(0, need[u][i] - have[i]);
    return res;
}
bool useful(int u)//计算使用当前预设增加的通配符的数量
{
    for (int i = '0'; i < maxc; i ++)
        if(need[u][i] && have[i])
            return true;
    return false;
}
bool choose(int &now)//判断选用另一个还是使用当前预设
{
    if(now > 0)
    {
        if(!useful(now) || wildcard < count(now))
        now = 0;
    }
    if(now > 0) return true;
    for(int i = 1; i <= k; i ++)
        if(useful(i) && wildcard >= count(i))
        {
            now = i;
            return true;
        }
    return false;
}
struct node {int opt, x, y;} ; vector<node> ans;
void note_swap(int x, int y, int xx, int yy)
{
    if(x > xx) ans.push_back({-4, x, y});
    if(x < xx) ans.push_back({-3, x, y});
    if(y > yy) ans.push_back({-2, x, y});
    if(y < yy) ans.push_back({-1, x, y});
    swap(pap[x][y], pap[xx][yy]);
}
void note_cov(int u)
{
    ans.push_back({u, 1, 1});
    for(int i = 1; i <= nn[u]; i ++)
        for(int j = 1; j <= mm[u]; j ++)
            pap[i][j] = '*';
}
void move(char c, int gx, int gy, int sx, int sy)
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(i <= sx && j <= sy && (i < gx || i == gx && j < gy)) continue;
            if(pap[i][j] == c)
            {//为了不影响到已经排列好的位置，故需要视情况调整先移动哪一维
                if(i < gx)
                {
                    while(i < gx) note_swap(i, j, i + 1, j), i ++;
                    while(i > gx) note_swap(i, j, i - 1, j), i --;
                    while(j < gy) note_swap(i, j, i, j + 1), j ++;
                    while(j > gy) note_swap(i, j, i, j - 1), j --;
                }
                else
                {
                    while(j < gy) note_swap(i, j, i, j + 1), j ++;
                    while(j > gy) note_swap(i, j, i, j - 1), j --;
                    while(i < gx) note_swap(i, j, i + 1, j), i ++;
                    while(i > gx) note_swap(i, j, i - 1, j), i --;
                }
                return ;
            }
        }
}
void cov(int u)
{
    for(int i = 1; i <= nn[u]; i ++)
        for(int j = 1; j <= mm[u]; j ++)
            if(have[pre[u][i][j]])
            {
                move(pre[u][i][j], i, j, nn[u], mm[u]);
                wildcard ++, have[pre[u][i][j]] --;
            }
            else move('*', i, j, nn[u], mm[u]);
    note_cov(u);
}
fish main()
{
    freopen("stamp.in", "r", stdin);
    freopen("stamp.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
        scanf("%s", pre[0][i] + 1);
        nn[0] = n, mm[0] = m;//初始矩阵记为预设0
    for(int i = 1; i <= n; i ++)
        scanf("%s", pap[i] + 1);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            have[pap[i][j]] ++;
    for(int i = 1; i <= k; i ++)
    {
        cin >> nn[i] >> mm[i];
        for(int j = 1; j <= nn[i]; j ++)
            scanf("%s", pre[i][j] + 1);
    }
    for(int i = 0; i <= k; i ++)
        for(int j = 1; j <= nn[i]; j ++)
            for(int k = 1; k <= mm[i]; k ++)
                need[i][pre[i][j][k]] ++;
    int now = 0;
    while(true)//一直替换
        if(!choose(now)) break ;
        else cov(now);
    if(count(0) <= wildcard)//判断能否达到初始矩阵
    {
        if(useful(0))
        {
            cov(0);
            ans.pop_back();
        }
        cout << ans.size() << "\n";
        while(ans.size())
        {
            cout << (*ans.rbegin()).opt SP (*ans.rbegin()).x SP (*ans.rbegin()).y << "\n";
            ans.pop_back();
        }
    }
    else cout << "-1\n";
    return 0;
}