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
int vis[200005],in[200005],out[200005];
vector<int> v[200005];
int timer=0;
void dfs(int x){
	vis[x]=1;
	timer++;
	in[x]=timer;
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
   int n,q;
   scanf("%d %d",&n,&q);
   for(int i=0;i<n+5;i++){
   	vis[i]=0;
   	in[i]=0;
   	out[i]=0;
   }
   for(int i=0;i<n-1;i++)
   {
   		int x,y;
   		scanf("%d %d",&x,&y);
   		v[x].pb(y);
   		v[y].pb(x);
   }
   timer=0;
   dfs(1);
   while(q--)
   {
   		int x,y;
   		scanf("%d %d",&x,&y);
   		if((in[x]<in[y] && out[x]>out[y]) || (in[x]>in[y] && out[x]<out[y]))
   			printf("YES\n");

   		else
   			printf("no\n");
   }
   return 0;
}
