#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<int,int>

using namespace std;
int n,m;
int xx1[]={0,0,1,-1};
int yy1[]={1,-1,0,0};
int a[15][15],vis[15][15];
void dfs(int x,int y)
{
	if(x<=0 || x>n || y<=0 || y>m)
		return;
	if(x==n && y==m){
		vis[x][y]=1;
		return;
	}
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		if(!vis[x+xx1[i]][y+yy1[i]] && a[x+xx1[i]][y+yy1[i]]==1)
			dfs(x+xx1[i],y+yy1[i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	dfs(1,1);
	if(vis[n][m]==1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}
