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
ll a[500005],tree[2000005];
void update(int node,int start,int end,int x,int val)
{
	if(start==end)
	{
		if(val==1)
			tree[node]++;
		else{
			if(tree[node])
			tree[node]--;
		}
		return;
	}
	int mid=(start+end)/2;
	if(start<=x && x<=mid)
		update(2*node,start,mid,x,val);
	else
		update(2*node+1,mid+1,end,x,val);
	tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(int node,int start,int end,int l,int r)
{
	if(start>r||end<l)
		return 0;
	if(start>=l && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	ll ans=0;
	ans=query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
	return ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin>>n>>q;
   while(q--)
   {
   		int k,x,y;
   		cin>>k;
   		if(k==1)
   		{
   			cin>>x;
   			update(1,1,n,x,1);
   		}
   		else if(k==2)
   		{
   			cin>>x;
   			update(1,1,n,x,2);
   		}
   		else
   		{
   			cin>>x>>y;
   			cout<<query(1,1,n,x,y)<<endl;
   		}
   }


   return 0;
}
