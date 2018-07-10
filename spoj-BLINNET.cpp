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
#define pii pair<ll,ll>

using namespace std;
vector<pair<ll,pii> >v;
int parent[10005];
int root(int x)
{
	while(x!=parent[x])
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
void union1(int x,int y)
{
	int root_x=root(x);
	int root_y=root(y);
	if(root_x==root_y)
		return;
	parent[root_y]=root_x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll ans=0;
		v.clear();
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
		for(int i=1;i<=n;i++)
		{
			string s;
			int k;
			cin>>s>>k;
			for(int j=0;j<k;j++)
			{
				ll y,z;
				cin>>y>>z;
				if(y>i)
					v.pb(mp(z,mp(i,y)));
			}
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)
		{
			int x=v[i].second.first;
			int y=v[i].second.second;
			ll z=v[i].first;
			if(root(x)!=root(y))
			{
				union1(x,y);
				ans+=z;
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}
