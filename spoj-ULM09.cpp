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
int parent[200005],size[200005];
vector<pair<int,pii> >v;
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
	if(size[root_x]>size[root_y])
	{
		parent[root_y]=root_x;
		size[root_x]+=size[root_y];
	}
	else
	{
		parent[root_x]=root_y;
		size[root_y]+=size[root_x];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		if(m==0)
		{
			cout<<0<<endl;
			continue;
		}
		v.clear();
		int c=0,ans=0;
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			v.pb(mp(z,mp(x,y)));
			c+=z;
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			parent[i]=i;
			size[i]=1;
		}
		for(int i=0;i<m;i++)
		{
			int x=v[i].second.first;
			int y=v[i].second.second;
			int z=v[i].first;
			if(root(x)!=root(y))
			{
				union1(x,y);
				ans+=z;
			}
		}
		cout<<c-ans<<endl;

	}


	return 0;
}
