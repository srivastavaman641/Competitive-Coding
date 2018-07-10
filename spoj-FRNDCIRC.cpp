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
unordered_map<ll,ll> parent;
map<string,ll>m;
map<ll,ll>size;
ll root(ll x)
{
	while(x!=parent[x])
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
void union1(ll x,ll y)
{
	ll root_x=root(x);
	ll root_y=root(y);
	if(root_x==root_y)
		return;
	if(size[root_x]>size[root_y])
	{
		size[root_x]+=size[root_y];
		parent[root_y]=root_x;
	}
	else
	{
		size[root_y]+=size[root_y];
		parent[root_x]=root_y;

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
		int n;
		cin>>n;
		parent.clear();
		size.clear();
		m.clear();
		ll k=1;
		vector<ll>ans;
		for(ll i=1;i<=n;i++)
		{
			string s,s1;
			cin>>s>>s1;
			if(!m[s]){
				m[s]=k;
				size[m[s]]=1;
				parent[m[s]]=m[s];
				//cout<<k<<" ";
				k++;
				
			}
			if(!m[s1]){
				m[s1]=k;
				size[m[s1]]=1;
				parent[m[s1]]=m[s1];
				//cout<<k<<endl;
				k++;
			}
			ll x=root(m[s]);
			ll y=root(m[s1]);
			union1(x,y);
			ans.pb(size[root(x)]);
		}
		for(ll i=0;i<ans.size();i++)
			cout<<ans[i]<<endl;
	}


	return 0;
}
