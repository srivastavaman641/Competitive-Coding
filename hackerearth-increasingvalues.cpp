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
vector<ll>v[100005];
ll vis[100005],tree[100005],a[100005],parent[100005],mark[100005];
ll cnt=0;
ll lim;
void dfs(ll x)
{
	vis[x]=1;
	tree[x]=a[x];
	for(ll i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			dfs(v[x][i]);
			parent[v[x][i]]=x;
			tree[x]+=tree[v[x][i]];
		}
	}
	if(tree[x]>lim){
		mark[x]=1;
		cnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q>>lim;
	for (int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	parent[1]=0;
	dfs(1);
	while(q--)
	{
		ll x,val;
		cin>>x>>val;
		tree[x]+=val;
		while(x>0)
		{
			if(tree[x]>lim){
				if(!mark[x]){
					mark[x]=1;
					cnt++;
				}
				else
					break;
			}
			tree[parent[x]]+=val;
			if(tree[parent[x]]>lim && parent[x]!=0)
			{
				if(!mark[parent[x]])
				{
					mark[parent[x]]=1;
					cnt++;
				}
				else
					break;
			}
			x=parent[parent[x]];
			tree[x]+=val;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
