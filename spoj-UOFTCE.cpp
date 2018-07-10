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
char a[105][105];
int dis[105][105],vis[105][105];
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int n,m;
void bfs(int i,int j)
{
	queue<pii>q;
	q.push(mp(i,j));
	dis[i][j]=0;
	while(!q.empty())
	{
		pii p=q.front();
		q.pop();
		int f=p.first;
		int s=p.second;
		vis[f][s]=1;
		for(int k=0;k<4;k++)
		{
			if(f+x[k]>0 && f+x[k]<=n && s+y[k]>0 && s+y[k]<=m && !vis[f+x[k]][s+y[k]] && a[f+x[k]][s+y[k]]!='#'){
				q.push(mp(f+x[k],s+y[k]));
				dis[f+x[k]][s+y[k]]=1+dis[f][s];
				vis[f+x[k]][s+y[k]]=1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		memset(dis,0,sizeof dis);
		memset(vis,0,sizeof vis);
		int x1=0,y1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j]=='C')
				{
					x1=i;
					y1=j;
				}
			}
		}
		int  mx=0;
		bfs(x1,y1);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='S')
				{
					ans=ans+(2*dis[i][j]+60);
					mx=max(mx,dis[i][j]);
				}
			}
		}
		cout<<ans-mx<<endl;
	}
	return 0;
}
