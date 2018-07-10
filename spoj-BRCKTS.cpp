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
int tree[120005][2];
string s;
void build(int node,int start,int end)
{
	if(start==end)
	{	
		if(s[start]=='(')
			tree[node][0]=1;
		else
			tree[node][1]=1;
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	int ch=min(tree[2*node][0],tree[2*node+1][1]);
	tree[node][0]=tree[2*node][0]+tree[2*node+1][0]-ch;
	tree[node][1]=tree[2*node][1]+tree[2*node+1][1]-ch;
}
void update(int node,int start,int end,int x)
{
	if(start==end)
	{
		if(s[x]=='(')
		{
			tree[node][0]=0;
			tree[node][1]=1;
			s[x]=')';
		}
		else
		{
			tree[node][0]=1;
			tree[node][1]=0;
			s[x]='(';
		}
		return;
	}
	int mid=(start+end)/2;
	if(x>=start && x<=mid)
		update(2*node,start,mid,x);
	else
		update(2*node+1,mid+1,end,x);
	int ch=min(tree[2*node][0],tree[2*node+1][1]);
	tree[node][0]=tree[2*node][0]+tree[2*node+1][0]-ch;
	tree[node][1]=tree[2*node][1]+tree[2*node+1][1]-ch;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   for(int p=1;p<=10;p++)
   {
   		int n;
   		cin>>n>>s;
   		memset(tree,0,sizeof tree);
   		build(1,0,n-1);
   		int m;
   		cin>>m;
   		cout<<"Test "<<p<<":"<<endl;
   		while(m--)
   		{
   			int x;
   			cin>>x;
   			if(!x)
   			{
   				if(tree[1][0]==0 && tree[1][1]==0)
   				{
   					cout<<"YES"<<endl;
   				}
   				else
   					cout<<"NO"<<endl;
   			}
   			else
   			{
   				update(1,0,n-1,x-1);
   			}
   		}

   }


   return 0;
}
