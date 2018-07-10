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
vector< pair<ll,ll> > v;
ll parent[100005];
ll root(ll x)
{
	while(parent[x]!=x)
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
void un(ll x,ll y)
{
	ll root_a=root(x);
	ll root_b=root(y);
	if(root_a!=root_b)
		parent[root_b]=root_a;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin>>t;
   while(t--)
   {
   		ll n,k,cnt=0;
   		cin>>n>>k;
   		for(int i=1;i<=n;i++)
   			parent[i]=i;
   		v.clear();
   		for(int i=0;i<k;i++)
   		{
   			ll q,x,y;
   			cin>>q>>x>>y;
   			if(x>n || y>n)
   				cnt++;
   			else if(q==2 && x==y)
   				cnt++;
   			else if(q==1)
   				un(x,y);
   			else 
   			v.pb(mp(x,y));
   		}
   		for(int i=0;i<v.size();i++)
   		{
   			ll f=v[i].first;
   			ll s=v[i].second;
   			if(root(f)==root(s)){
   				un(f,s);
   				cnt++;
   			}
   		}
   		cout<<cnt<<endl;

   }


   return 0;
}
