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
ll tree[400005],a[100005];
void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}
ll query(int node,int start,int end,int l,int r)
{
	if(start>end || start>r || end<l)
		return INT_MAX;
	if(start>=l && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	return min(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin>>n;
   for(int i=1;i<=n;i++)
   		cin>>a[i];
   build(1,1,n);
   cin>>q;
   while(q--)
   {
   		int l,r;
   		cin>>l>>r;
   		cout<<query(1,1,n,l+1,r+1)<<endl;
   }


   return 0;
}
