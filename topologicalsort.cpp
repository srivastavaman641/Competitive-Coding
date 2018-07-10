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
bool vis[100005];
int indegree[100005];
stack<int>s;
vector<int>v[100005];
void dfs(int i)
{
	vis[i]=1;
	for(int j=0;j<v[i].size();j++)
	{

		if(!vis[v[i][j]])
		{
			dfs(v[i][j]);
			
		}
	}
	s.push(i);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   memset(vis,0,sizeof vis);
   memset(indegree,0,sizeof indegree);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=m;i++)
   {
   		int x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   }
   for(int i=1;i<=n;i++)
   {
   		for(int j=0;j<v[i].size();j++)
   		{
   			indegree[v[i][j]]++;
   		}

   }
   for(int i=1;i<=n;i++)
   {
   	if(indegree[i]==0)
   	{
   		dfs(i);
   	}
   }
   while(!s.empty())
   {
   	cout<<s.top()<<" ";
   	s.pop();
   }

   return 0;
}
