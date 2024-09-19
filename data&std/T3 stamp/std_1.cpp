#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
int n,m,k;
char s[MAXN];
int mp[MAXN][MAXN][MAXN],t[MAXN][MAXN];
int kn[MAXN],km[MAXN];
int cnt[MAXN<<2],vis[MAXN][MAXN];
struct node{
	int opt,x,y;
};
vector<node> ans;
inline int change(char x){
	if(x>='0' && x<='9') return x-'0'+1;
	if(x>='a' && x<='z') return x-'a'+1+11;
	if(x>='A' && x<='Z') return x-'A'+1+37;
}
inline int check(int d){
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cnt[t[i][j]]++;
	int sum=0;
	for(int i=1;i<=kn[d];i++) for(int j=1;j<=km[d];j++){
		if(cnt[mp[d][i][j]]) cnt[mp[d][i][j]]--,sum++;
		else if(cnt[0]) cnt[0]--;
		else return -1;
	}
	return sum;
}
inline void solve(int d){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=kn[d];i++) for(int j=1;j<=km[d];j++){
		int x=0,y=0;
		for(int ii=1;!x && ii<=n;ii++) for(int jj=1;jj<=m;jj++) if(!vis[ii][jj] && mp[d][i][j]==t[ii][jj]) x=ii,y=jj;
		for(int ii=1;!x && ii<=n;ii++) for(int jj=1;jj<=m;jj++) if(!vis[ii][jj] && !t[ii][jj]) x=ii,y=jj;
		while(x<i) swap(t[x][y],t[x+1][y]),ans.push_back({-3,x++,y});
		while(y<j) swap(t[x][y],t[x][y+1]),ans.push_back({-1,x,y++});
		while(x>i) swap(t[x][y],t[x-1][y]),ans.push_back({-4,x--,y});
		while(y>j) swap(t[x][y],t[x][y-1]),ans.push_back({-2,x,y--});
		vis[i][j]=1;
	}
	for(int i=1;i<=kn[d];i++) for(int j=1;j<=km[d];j++) t[i][j]=0;
	if(d) ans.push_back({d,1,1});
}
signed main(){
    freopen("stamp.in", "r", stdin);
    freopen("stamp.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k; kn[0]=n; km[0]=m;
	for(int i=1;i<=n;i++){
		cin>>s+1;
		for(int j=1;j<=m;j++) mp[0][i][j]=change(s[j]);
	}
	for(int i=1;i<=n;i++){
		cin>>s+1;
		for(int j=1;j<=m;j++) t[i][j]=change(s[j]);
	}
	for(int d=1;d<=k;d++){
		cin>>kn[d]>>km[d];
		for(int i=1;i<=kn[d];i++){
			cin>>s+1;
			for(int j=1;j<=km[d];j++)
				mp[d][i][j]=change(s[j]);
		}
	}
	while(1){
		if(check(0)>=0) break;
		bool flag=false;
		for(int i=1;i<=k;i++) if(check(i)>0) flag=true,solve(i);
		if(!flag) return cout<<-1<<'\n',0;
	}
	solve(0);
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++) cout<<ans[i].opt<<" "<<ans[i].x<<" "<<ans[i].y<<'\n';
	return 0;
}