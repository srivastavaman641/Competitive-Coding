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
char v[35][35];
int vis[35][35];
int x[]={-1,0,0,1};
int y[]={0,-1,1,0};
int dis[35][35];
int prev1[35][35],prev2[35][35];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0;i<35;i++)
	{
		for(int j=0;j<35;j++)
		{
			vis[i][j]=0;
			dis[i][j]=0;
		}
	}
	vector< pair<int,int> >v1;
	queue<int>q;
	int x1,y1;
	cin>>x1>>y1;
	int x2,y2;
	cin>>x2>>y2;
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>v[i][j];
		}
	}
	int cn=0;
	q.push(x1);
	q.push(y1);
	vis[x1][y1]=1;
   //v1.pb(mp(x1,y1));
	prev1[x1][y1]=-1;
	prev2[x1][y1]=-1;
	while(!q.empty())
	{
		int f1=q.front();
		q.pop();
		int f2=q.front();
		q.pop();
		v1.pb(mp(f1,f2));
		cn++;
		if(f1==x2 && f2==y2){
		//v1.pb(mp(x2,y2));
			break;
		}
		for(int i=0;i<4;i++)
		{
			if(f1+x[i]>=0 && f1+x[i]<r && f2+y[i]>=0 && f2+y[i]<c && v[f1+x[i]][f2+y[i]]!='%' && vis[f1+x[i]][f2+y[i]]==0)
			{
				prev1[f1+x[i]][f2+y[i]]=f1;
				prev2[f1+x[i]][f2+y[i]]=f2;
				q.push(f1+x[i]);
				q.push(f2+y[i]);
				dis[f1+x[i]][f2+y[i]]=dis[f1][f2]+1;
				vis[f1+x[i]][f2+y[i]]=1;
			}
		}
	}
	cout<<cn<<endl;
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1[i].first<<" "<<v1[i].second;
		cout<<endl;
	}
	cout<<dis[x2][y2]<<endl;
	v1.clear();
	int i=x2,j=y2;
  // v1.pb(mp(x2,y2));
	while(prev1[i][j]!=-1 && prev2[i][j]!=-1)
	{
		v1.pb(mp(i,j));
		i=prev1[i][j];
		j=prev2[i][j];
	}
	v1.pb(mp(x1,y1));
	for(int i=v1.size()-1;i>=0;i--)
	{
		cout<<v1[i].first<<" "<<v1[i].second;
		cout<<endl;
	}

	return 0;
}
