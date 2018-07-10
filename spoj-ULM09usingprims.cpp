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
vector<pii>v[200005];
int vis[200005];
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
		for(int i=0;i<n;i++){
			vis[i]=0;
			v[i].clear();
		}
		ll c=0,ans=0;
		for(int i=0;i<m;i++)
		{
			ll x,y,z;
			cin>>x>>y>>z;
			v[x].pb(mp(z,y));
			v[y].pb(mp(z,x));
			c+=z;
		}
		int idx=0;
		for(int i=0;i<n;i++)
		{
			if(v[i].size())
			{
				idx=i;
				break;
			}
		}
		priority_queue<pii,vector<pii>,greater<pii> >pq;
		pq.push(mp(0,idx));
		while(!pq.empty())
		{
			pii p=pq.top();
			pq.pop();
			ll x=p.second;
			ll y=p.first;
			if(vis[x])
				continue;
			vis[x]=1;
			ans+=y;
			for(int i=0;i<v[x].size();i++)
			{
				if(!vis[v[x][i].second])
					pq.push(v[x][i]);
			}
		}
		cout<<c-ans<<endl;

		return 0;
	}
}
