#include <bits/stdc++.h>
#define MAXN 20
#define MAXM 20
#define MAXK 20
#define MAXC ((int) 'z')
using namespace std;

int n, m, K;
vector<vector<int>> ans;
char MAP[MAXN + 5][MAXM + 5];
int nn[MAXK + 5], mm[MAXK + 5];
char PAT[MAXK + 5][MAXN + 5][MAXM + 5];

// star：目前有几个通配符
// have[c]：目前有几个字符 c
// need[p][c]：盖章 p 需要几个字符 c
int star, have[MAXC + 1], need[MAXK + 1][MAXC + 1];

// 检查章 which 现在至少需要几个通配符才能盖
int miss(int which) {
    int ret = 0;
    for (int i = '0'; i <= MAXC; i++) ret += max(0, need[which][i] - have[i]);
    return ret;
}

// 检查盖章 which 能否新产生通配符
bool haveAny(int which) {
    for (int i = '0'; i <= MAXC; i++) if (need[which][i] && have[i]) return true;
    return false;
}

// 上次盖的章是 now，看接下来盖哪个章
// return 0：所有章都不能盖
// return 1：上一次的章还能接着盖
// return 2：换了一个新章
int choose(int &now) {
    if (now > 0) { if (!haveAny(now) || star < miss(now)) now = 0; }
    // 这个章能盖就继续盖
    if (now > 0) return 1;
    // 不能盖就选新章
    for (int k = 1; k <= K; k++) if (haveAny(k) && star >= miss(k)) {
        now = k;
        return 2;
    }
    return 0;
}

// 记录交换操作
void Swap(int i, int j, int ii, int jj) {
    if (i > ii) ans.push_back({-4, i, j});
    else if (i < ii) ans.push_back({-3, i, j});
    else if (j > jj) ans.push_back({-2, i, j});
    else ans.push_back({-1, i, j});
    swap(MAP[i][j], MAP[ii][jj]);
}

// 记录盖章操作
void Stamp(int which) {
    for (int i = 1; i <= nn[which]; i++) for (int j = 1; j <= mm[which]; j++) MAP[i][j] = '*';
    ans.push_back({which, 1, 1});
}

// 把任意一个字符 c 移动到 (GI, GJ)
// 盖章范围位于左上角的 (SI, SJ)
void Move(char c, int GI, int GJ, int SI, int SJ) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        bool smaller = (i < GI) || (i == GI && j < GJ);
        // 我们不想破坏 (GI, GJ) 之前已经整理好的部分
        if (i <= SI && j <= SJ && smaller) continue;
        // 在可以破坏的范围内找到了字符 c
        if (MAP[i][j] == c) {
            // 为了不破坏已经整理好的部分
            // 先把它在 (SI, SJ) 的范围外移动到对应行 / 列，再一次性移动过去
            if (i <= GI) {
                while (i < GI) Swap(i, j, i + 1, j), i++;
                while (i > GI) Swap(i, j, i - 1, j), i--;
                while (j < GJ) Swap(i, j, i, j + 1), j++;
                while (j > GJ) Swap(i, j, i, j - 1), j--;
            } else {
                while (j < GJ) Swap(i, j, i, j + 1), j++;
                while (j > GJ) Swap(i, j, i, j - 1), j--;
                while (i < GI) Swap(i, j, i + 1, j), i++;
                while (i > GI) Swap(i, j, i - 1, j), i--;
            }
            return;
        }
    }
    assert(false);
}

// 接着盖同一个章
void gao1(int which) {
    for (int i = 1; i <= nn[which]; i++) for (int j = 1; j <= mm[which]; j++)
        if (have[PAT[which][i][j]]) {
            // 选择任意一个字符变成通配符
            Move(PAT[which][i][j], i, j, nn[which], mm[which]);
            star++;
            have[PAT[which][i][j]]--;
            Stamp(which);
            return;
        }
    assert(false);
}

// 盖一个新章
void gao2(int which) {
    for (int i = 1; i <= nn[which]; i++) for (int j = 1; j <= mm[which]; j++) {
        if (have[PAT[which][i][j]]) {
            // 需要的字符还有，把它移动到目标位置
            Move(PAT[which][i][j], i, j, nn[which], mm[which]);
            star++;
            have[PAT[which][i][j]]--;
        } else {
            // 需要的字符没了，用通配符代替
            Move('*', i, j, nn[which], mm[which]);
        }
    }
    Stamp(which);
}

int main() {
    freopen("stamp.in", "r", stdin);
    freopen("stamp.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &K);

    for (int i = 1; i <= n; i++) scanf("%s", PAT[0][i] + 1);
    nn[0] = n; mm[0] = m;

    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) have[MAP[i][j]]++;

    for (int k = 1; k <= K; k++) {
        scanf("%d%d", &nn[k], &mm[k]);
        for (int i = 1; i <= nn[k]; i++) scanf("%s", PAT[k][i] + 1);
    }
    for (int k = 0; k <= K; k++) for (int i = 1; i <= nn[k]; i++) for (int j = 1; j <= mm[k]; j++) need[k][PAT[k][i][j]]++;

    // 持续盖章，直到任何一个章都不能盖
    int now = 0;
    while (true) {
        int t = choose(now);
        if (t == 0) break;
        else if (t == 1) gao1(now);
        else gao2(now);
    }

    // 把初始局面看成章 0，检查章 0 是否能盖
    if (miss(0) <= star) {
        // 能盖章 0，有解
        if (haveAny(0)) {
            gao2(0);
            ans.pop_back();
        }
        printf("%d\n", ans.size());
        while (!ans.empty()) {
            printf("%d %d %d\n", ans.back()[0], ans.back()[1], ans.back()[2]);
            ans.pop_back();
        }
    } else {
        // 不能盖章 0，无解
        printf("-1\n");
    }

    return 0;
}