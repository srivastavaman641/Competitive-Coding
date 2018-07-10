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
int vis[100005];
int e=0,v1=0,edge=0,vertex=1;
double ans=0.0;
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		e++;
		if(!vis[v[x][i]])
		{
			v1++;
			dfs(v[x][i],x);
			//e--;
			//v1--;
		}
	}
	//vis[x]=0;

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
   		int x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   		v[y].pb(x);
   }
   double mx=0;
   for(int i=1;i<=n;i++)
   {
   		if(!vis[i]){
   			e=0;
   			v1=1;
   			ans=0;
   			dfs(i,i);
   			e/=2;
   			ans=(e*1.0)/(v1*1.0);
   			if(ans>=mx){
   				mx=ans;
   				edge=e;
   				vertex=v1;
   			}
   		}
   }
   if(mx>1){
   cout<<">1"<<endl;
  }
	else{
		int x=__gcd(edge,vertex);
		edge/=x;
		vertex/=x;
   		cout<<edge<<"/"<<vertex<<endl;
}
   return 0;
}
