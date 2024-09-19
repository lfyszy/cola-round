#include<bits/stdc++.h>
const int N=600;
int n,m,k,mp[305],c[N][N][N],h[N],w[N],a[N][N];
std::vector<std::tuple<int,int,int> > ans;
inline void get_mp(){
    int tot=0;
    for(char i='0';i<='9';i++) mp[(int)i]=++tot;
    for(char i='a';i<='z';i++) mp[(int)i]=++tot;
    for(char i='A';i<='Z';i++) mp[(int)i]=++tot;
}
inline int chk(int k){
    static int cnt[N]; memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cnt[a[i][j]]++;
    int tot=0;
    for(int i=1;i<=h[k];i++) for(int j=1;j<=w[k];j++){
        if(cnt[c[k][i][j]]) cnt[c[k][i][j]]--,tot++;
        else if(cnt[0]) cnt[0]--;
        else return -1;
    }
    return tot;
}
inline void work(int k){
    static bool vis[N][N]; memset(vis,false,sizeof vis);
    for(int i=1;i<=h[k];i++) for(int j=1;j<=w[k];j++){
        int x=0,y=0;
        for(int l=1;!x&&l<=n;l++) for(int r=1;r<=m;r++) if(!vis[l][r]&&a[l][r]==c[k][i][j]) x=l,y=r;
		for(int l=1;!x&&l<=n;l++) for(int r=1;r<=m;r++) if(!vis[l][r]&&!a[l][r]) x=l,y=r;
        for(;x<i;x++) std::swap(a[x][y],a[x+1][y]),ans.push_back(std::make_tuple(-3,x,y));
        for(;y<j;y++) std::swap(a[x][y],a[x][y+1]),ans.push_back(std::make_tuple(-1,x,y));
        for(;x>i;x--) std::swap(a[x][y],a[x-1][y]),ans.push_back(std::make_tuple(-4,x,y));
        for(;y>j;y--) std::swap(a[x][y],a[x][y-1]),ans.push_back(std::make_tuple(-2,x,y));
        vis[i][j]=true;
    }
    for(int i=1;i<=h[k];i++) for(int j=1;j<=w[k];j++) a[i][j]=0;
    if(k) ans.push_back(std::make_tuple(k,1,1));
}
int main(){
    freopen("stamp.in", "r", stdin);
    freopen("stamp.out", "w", stdout);
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);
    get_mp();
    std::cin>>n>>m>>k,h[0]=n,w[0]=m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){ char ch; std::cin>>ch; c[0][i][j]=mp[(int)ch]; }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){ char ch; std::cin>>ch; a[i][j]=mp[(int)ch]; }
    for(int i=1;i<=k;i++){
        std::cin>>h[i]>>w[i];
        for(int j=1;j<=h[i];j++) for(int l=1;l<=w[i];l++){ char ch; std::cin>>ch; c[i][j][l]=mp[(int)ch]; }
    }
    for(;chk(0)<0;){
        bool flag=false;
        for(int i=1;i<=k;i++) if(chk(i)>0) flag=true,work(i);
        if(!flag) return std::cout<<-1,0;
    }
    work(0);
    std::reverse(ans.begin(),ans.end());
    std::cout<<ans.size()<<"\n";
    for(auto [op,x,y]:ans) std::cout<<op<<" "<<x<<" "<<y<<"\n";
    return 0;
}
