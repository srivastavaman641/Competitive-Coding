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
vector<int>v[5005],v1[5005],ans[5005];
vector<int>a;
stack<int>s;
int vis[5005],in[5005];
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v1[x].size();i++)
	{
		if(!vis[v1[x][i]])
			dfs(v1[x][i]);
	}
	s.push(x);
}
int dfss(int x,int cnt)
{
	vis[x]=cnt;
	int c=1;
	ans[cnt].pb(x);
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			c+=dfss(v[x][i],cnt);
	}
	return c;
}
int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);*/
	int n,m;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		cin>>m;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			a.clear();
			v[i].clear();
			v1[i].clear();
			ans[i].clear();
			in[i]=0;
		}
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].pb(y);
			v1[y].pb(x);
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
				dfs(i);
		}
		memset(vis,0,sizeof vis);
		int cnt=0;
		while(!s.empty())
		{
			int x=s.top();
			s.pop();
			if(!vis[x])
			{
				cnt++;
				dfss(x,cnt);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<v1[i].size();j++)
			{
				if(vis[i]!=vis[v1[i][j]])
					in[vis[v1[i][j]]]++;
			}
		}
		int an=0,c=0;
		for(int i=1;i<=cnt;i++)
		{
			if(in[i]==0){
				c++;
				for(int j=0;j<ans[i].size();j++)
					a.pb(ans[i][j]);
			}
		}
		if(c==0)
		{
			cout<<endl;
			continue;
		}
		sort(a.begin(),a.end());
		for(int i=0;i<a.size();i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}


	return 0;
}
