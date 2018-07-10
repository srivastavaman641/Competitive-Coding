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
vector<int>v[10005];
int vis[10005],instack[10005];
stack<int>s;
int flag=0;
void dfs(int x)
{
	vis[x]=1;
	instack[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i]] && instack[v[x][i]])
			flag=1;
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	}
	s.push(x);
	instack[x]=0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
	}
	for(int i=1;i<=n;i++)
		sort(v[i].rbegin(),v[i].rend());
	for(int i=n;i>=1;i--)
	{
		if(!vis[i])
			dfs(i);
	}
	if(flag==1)
	{
		cout<<"Sandro fails."<<endl;
		return 0;
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}
