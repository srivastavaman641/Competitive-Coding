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
ll mx=1,mn=1;
ll parent[100005],size[100005];
multiset<int>m;
void union1(int x,int y)
{
	if(size[x]>size[y])
	{
		parent[y]=x;
		m.erase(m.find(size[x]));
		m.erase(m.find(size[y]));
		size[x]+=size[y];
		m.insert(size[x]);
	}
	else
	{
		parent[x]=y;
		m.erase(m.find(size[x]));
		m.erase(m.find(size[y]));
		size[y]+=size[x];
		m.insert(size[y]);
	}
}
ll root(ll x)
{
	while(x!=parent[x])
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++)
   {
   		size[i]=1;
   		parent[i]=i;
   		m.insert(1);
   }
   int cnt=n;
   while(q--)
   {
   		int x,y;
   		cin>>x>>y;
   		int a=root(x);
   		int b=root(y);
   		if(a!=b)
   		{
   			union1(a,b);
   		}
   		cout<<*m.rbegin()-*m.begin()<<endl;
   }
   return 0;
}
