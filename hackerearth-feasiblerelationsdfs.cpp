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
int va[1000005][2];
string op[1000005];
int vis[1000005];
vector<int>v[1000005];
void dfs(int x,int id)
{
	vis[x]=id;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			dfs(v[x][i],id);
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
   	int n,k;
   	cin>>n>>k;
   	memset(vis,0,sizeof vis);
   	for(int i=0;i<1000005;i++)
   		v[i].clear();
   	for(int i=0;i<k;i++)
   	{
   		cin>>va[i][0]>>op[i]>>va[i][1];
   		if(op[i][0]=='='){
   			v[va[i][1]].pb(va[i][0]);
   			v[va[i][0]].pb(va[i][1]);
   		}
   	}
   	int flag=1;
   	for(int i=1;i<=n;i++)
   	{
   		if(!vis[i])
   			dfs(i,i);
   	}
   	for(int i=0;i<k;i++)
   	{
   		if(op[i][0]!='=')
   		{
   			if(vis[va[i][0]]==vis[va[i][1]])
   			{
   				flag=0;
   				break;
   			}
   		}
   	}
   	if(flag==1)
   		cout<<"YES"<<endl;
   	else
   		cout<<"NO"<<endl;

   }
   return 0;
}
