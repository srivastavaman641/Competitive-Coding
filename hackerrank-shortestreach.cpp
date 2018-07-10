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
int vis[100005];
int dis[100005];
vector<int>v[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		int n,m,s;
		queue<int>q;
		for(int i=0;i<100005;i++)
		{
			vis[i]=0;
			dis[i]=0;
			v[i].clear();
		}
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		cin>>s;
		q.push(s);
		vis[s]=1;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=0;i<v[x].size();i++)
			{
				if(vis[v[x][i]]==0)
				{
					vis[v[x][i]]=1;
					q.push(v[x][i]);
					dis[v[x][i]]=dis[x]+1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=s){
				if(vis[i]==1)
				{
					cout<<dis[i]*6<<" ";
				}
				else
					cout<<-1<<" ";
			}

		}
		cout<<endl;
	}
	return 0;
}
