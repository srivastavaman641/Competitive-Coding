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
vector<int>v[100005];
int vis[100005],in[100005],out[100005];
int timer=0;
void dfs(int x)
{
	timer++;
	in[x]=timer;
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	}
	timer++;
	out[x]=timer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	int q;
	cin>>q;
	while(q--)
	{
		int t,x,y;
		cin>>t>>x>>y;
		if(t==0)
		{
			if(out[x]>=out[y] && in[x]<=in[y])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			if(in[x]>=in[y] && out[x]<=out[y])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}



	return 0;
}
