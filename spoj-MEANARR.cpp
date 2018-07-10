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
ll n,k;
ll tree[800005];
ll a[200005];
void build(int node,int start,int end)
{
	if(start==end){
		tree[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	tree[node]=(tree[node])/(end-start+1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	ll ans=0;
	for(int i=1;i<=4*n+1;i++){
		if(tree[i]>=k)
			ans++;
	}
	cout<<ans<<endl;

	return 0;
}
